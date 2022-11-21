#include<stdio.h>
int main(void){
    char c[10];
    scanf("%s", c);
    double n = 100*(c[0]-'0')+10*(c[1]-'0')+(c[2]-'0')+(double)(c[4]-'0')/10+(double)(c[5]-'0')/100+(double)(c[6]-'0')/1000;
    double m = 100*(c[2]-'0')+10*(c[1]-'0')+(c[0]-'0')+(double)(c[6]-'0')/10+(double)(c[5]-'0')/100+(double)(c[4]-'0')/1000;
    printf("%.3lf", n+m);
    return 0;
}