#include<stdio.h>
#define maxn 120
int main(void){
    int N;
    scanf("%d", &N);
    unsigned long long f[maxn];
    f[0] = 1;
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= N; i++)
        f[i] = f[i-1]+f[i-3];
    printf("%llu\n", f[N]);
    return 0;
}