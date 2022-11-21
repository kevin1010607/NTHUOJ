#include<stdio.h>
int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    int A = a;
    int B = b;
    while(a && b){
        if(a > b) a %= b;
        else b %= a;
    }
    printf("%d\n", A*B/(a > b ? a : b));
    return 0;
}
