#include<stdio.h>
#define maxn 1000005
int e[maxn];
long long sum[maxn];
int main(void){
    int N;
    scanf("%d", &N);
    sum[0] = 0;
    for(int i = 1; i <= N; i++){
        scanf("%d", &e[i]);
        sum[i] = sum[i-1]+e[i];
    }
    int M;
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int L, R;
        long long ans;
        scanf("%d %d", &L, &R);
        ans = sum[R]-sum[L-1];
        printf("%lld\n", ans);
    }
    return 0;
}
