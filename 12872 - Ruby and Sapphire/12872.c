#include<stdio.h>
int main(void){
    int x, y, N, M;
    scanf("%d %d", &N, &M);
    x = (7*N-M)/2;
    y = (M-5*N)/2;
    printf("%d %d\n", x, y);
    return 0;
}