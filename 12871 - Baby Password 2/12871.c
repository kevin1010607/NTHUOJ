#include<stdio.h>
int main(void){
    char C;
    int D;
    scanf("%c %d", &C, &D);
    if(C >= 'A' && C <= 'Z')
        C = (C-'A'-D+26)%26+'a';
    else if(C >= 'a' && C <= 'z')
        C = (C-'a'-D+26)%26+'A';
    printf("%c\n", C);
    return 0;
}