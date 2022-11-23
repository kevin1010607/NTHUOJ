#include<stdio.h>
#include<string.h>
#define maxn 100005
char A[maxn], B[maxn];
int solve(int sA, int eA, int sB, int eB){
    if(eA-sA != eB-sB) return 0;
    int len = eA-sA+1;
    if(!strncmp(A+sA, B+sB, len)) return 1;
    if(len%2 == 0){
        if(solve(sA, sA+len/2-1, sB, sB+len/2-1)&&solve(sA+len/2, eA, sB+len/2, eB))
            return 1;
        if(solve(sA, sA+len/2-1, sB+len/2, eB)&&solve(sA+len/2, eA, sB, sB+len/2-1))
            return 1;
    }
    return 0;
}
int main(void){
    scanf("%s", A);
    scanf("%s", B);
    int len = strlen(A);
    printf("%s\n", solve(0, len-1, 0, len-1)?"YES":"NO");
    return 0;
}
