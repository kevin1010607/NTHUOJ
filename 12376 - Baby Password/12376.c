#include<stdio.h>
int main(void){
    char C;
    int D;
    scanf("%c %d", &C, &D);
    C = (C-'A'-D+26)%26+'A';
    printf("%c\n", C);
    return 0;
}