#include<stdio.h>
int main(void){
    char input[6];
    scanf("%s", input);
    for(int i = 0; i < 5; i++)
        input[i] = 25-(input[i]-'a')+'a';
    printf("%s\n", input);
    return 0;
}