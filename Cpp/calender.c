# include<stdio.h>// making a calender using array and string.

int get_1st_weekday(int year);


int main(){
    int year,month,daysinmonth,day,count=0,startingday;
    printf("enter the desired year:");
    scanf("%d", &year);

    char *months[]={"january","february","march", "april","may","june","july","august", "september","october","november","december"};

    int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};

    if((year%4== 0 && year%100!=0)  || year%400==0){
        monthDay[1]= 29;
    }

    startingday = get_1st_weekday(year);



    
  
    for(month=0;month<12;month++){

        daysinmonth = monthDay[month];
        

        printf("\n\n---------------%s--------------\n", months[month]);
        printf("\n sun  mon  tue  wed  thur  fri  sat\n");


        for(count=0;count<startingday;count++){
        printf("     ");
    }



        for(day =1;day<=daysinmonth;day++){
            printf("%5d", day);

            count++;
            if(count>6){
                printf("\n");
                count =0;
                
            }
            startingday=count;


        }
        

    }

    
    return 0;
}
int get_1st_weekday(int year){


 int d;
    d = (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return d;
}
