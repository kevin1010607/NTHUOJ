#include<stdio.h>
int main(void){
    char a[3];
    for(int i = 0; i < 3; i++)
        a[i] = getchar()-'A';
    getchar();
    int s;
    scanf("%d", &s);
    s %= 26;

    for(int i = 0; i < 3; i++){
        a[i] = (a[i]+s+26)%26+'A';
        putchar(a[i]);
    }
    printf("\n");
    return 0;
}