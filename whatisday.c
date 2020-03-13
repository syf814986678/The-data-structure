#include <stdio.h>
typedef struct 
{
    int year;
    int month;
    int day;
}DATE;

int whatisday(DATE date){
    int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int sumday=0;
    if((date.year%4==0)&&(date.year%100!=0)||(date.year%400==0)) days[2]=29;
    for(int i=1;i<=date.month;i++){
        sumday+=days[i];
    }
    if(date.day!=days[date.month]){
        sumday-=days[date.month]-date.day;
    }
    
    return sumday;
}

void main(){
    DATE date;
    printf("请输入年-月-日\n");
    scanf("%d-%d-%d",&date.year,&date.month,&date.day);
    printf("%d",whatisday(date));
    
}