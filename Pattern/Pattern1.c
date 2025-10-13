/*
1
23
456
*/

#include <stdio.h>

int main() {
    int num = 1; // start printing from 1
    for (int i = 1; i <= 3; i++) {  // number of rows
        for (int j = 1; j <= i; j++) {  // number of elements in each row
            printf("%d", num);
            num++;
        }
        printf("\n");  // move to next line after each row
    }
    return 0;
}
