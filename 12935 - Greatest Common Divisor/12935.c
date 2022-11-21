#include<stdio.h>
int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    while(a && b){
        if(a > b) a %= b;
        else b %= a;
    }
    if(a > b) printf("%d\n", a);
    else printf("%d\n", b);
    return 0;
}
