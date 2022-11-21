#include<stdio.h>
float x;
int main(void){
    while(~scanf("%f", &x)){
        unsigned int *ptr = (unsigned int*)&x;
        int T = 32;
        while(T--) printf("%u", ((*ptr)&(1<<T))>>T);
        printf("\n");
    }
    return 0;
}