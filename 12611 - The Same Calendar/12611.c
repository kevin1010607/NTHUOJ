#include<stdio.h>
int isLeapYear(int year){
    return (year%400==0 || (year%4==0 && year%100!=0));
}
int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int year;
        scanf("%d", &year);
        int sum = 0, isLeap = isLeapYear(year);
        do{
            year++;
            sum += (isLeapYear(year)?366:365);
        }while(sum%7!=0 || isLeapYear(year)!=isLeap);
        printf("%d\n", year);
    }
    return 0;
}