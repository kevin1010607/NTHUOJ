#include<stdio.h>
int main(void){
    int time;
    scanf("%d", &time);
    int hour, min;
    hour = (time-time%100)/100;
    min = time%100;
    if(hour < 12) printf("%.2d:%.2d a.m.", hour, min);
    else printf("%.2d:%.2d p.m.", hour-12, min);
    return 0;
}