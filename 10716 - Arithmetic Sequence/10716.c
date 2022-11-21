#include<stdio.h>
int main(void){
    int a, n, d;
    scanf("%d %d %d", &a, &n, &d);
    int a_n = a+(n-1)*d;
    int s_n = (a+a_n)*n/2;
    printf("%d %d", a_n, s_n);
    return 0;
}