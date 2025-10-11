#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/time.h>

static void restore_cursor(int sig){
    (void)sig;
    write(1,"\x1b[0m\x1b[?25h\n",12);
    exit(0);
}

int main(){
    struct winsize w;
    if(ioctl(1, TIOCGWINSZ, &w)==-1){ w.ws_row=24; w.ws_col=80; }
    int rows = w.ws_row, cols = w.ws_col/2;
    signal(SIGINT, restore_cursor);
    signal(SIGTERM, restore_cursor);
    srand((unsigned)time(NULL));
    double t=0;
    write(1,"\x1b[?25l",6);
    while(1){
        char buf[8192];
        int p=0;
        buf[p++]='\x1b'; buf[p++]='['; buf[p++]='H';
        for(int y=0;y<rows;y++){
            for(int x=0;x<cols;x++){
                double nx = (double)x/cols*6.0;
                double ny = (double)y/rows*6.0;
                double v = sin(nx + t) + sin(ny*1.3 - t*0.7) + sin((nx+ny)*0.5 + t*0.3);
                int color = (int)((v+3.0)/6.0 * 230.0) + 16;
                if(color<16) color=16;
                if(color>231) color=231;
                int n = snprintf(buf+p, sizeof(buf)-p, "\x1b[48;5;%dm  ", color);
                if(n<0) n=0;
                p+=n;
            }
            int n = snprintf(buf+p, sizeof(buf)-p, "\x1b[0m\n");
            if(n<0) n=0;
            p+=n;
        }
        write(1, buf, p);
        t += 0.08;
        usleep(60000);
    }
    restore_cursor(0);
    return 0;
}
