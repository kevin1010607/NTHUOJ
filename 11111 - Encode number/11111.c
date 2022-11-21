#include<stdio.h>
int main(void){
    char input[4];
    scanf("%s", input);
    for(int i = 0; i < 3; i++){
        input[i] += ('A'-'1');
        printf("%c", input[i]);
    }
    return 0;
}