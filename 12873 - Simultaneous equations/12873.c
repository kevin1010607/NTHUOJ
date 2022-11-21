#include<stdio.h>
int main(void){
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    int x, y;
    x = (c*e-b*f)/(a*e-b*d);
    y = (a*f-c*d)/(a*e-b*d);
    printf("%d %d", x, y);
    return 0;
}