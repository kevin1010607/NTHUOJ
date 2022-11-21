#include<stdio.h>
int main(void){
    int a1, a2, a3;
    scanf("%d,%d,%d", &a1, &a2, &a3);
    int b1, b2, b3;
    scanf("%d,%d,%d", &b1, &b2, &b3);

    int ans1, ans2, ans3;
    int car1, car2;
    car2 = ((a3+b3)-(a3+b3)%1000)/1000;
    ans3 = (a3+b3)%1000;
    car1 = ((a2+b2+car2)-(a2+b2+car2)%1000)/1000;
    ans2 = (a2+b2+car2)%1000;
    ans1 = a1+b1+car1;

    int ans = ans1*1000000+ans2*1000+ans3;
    printf("%d\n", ans);
    return 0;
}