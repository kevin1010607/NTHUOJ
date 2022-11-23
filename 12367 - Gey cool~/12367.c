#include<stdio.h>
int n, q, a, b, Ma, Mb;
long long dp[2000005], tmp, M;
int main(void){
    while(~scanf("%d %d", &n, &q)){
        dp[0] = M = 0;
        for(int i = 0; i < n; i++) scanf("%lld", &tmp), dp[i+1] = dp[i]+tmp;
        while(q--){
            scanf("%d %d", &a, &b);
            tmp = (a>b?(dp[n]-dp[a-1]+dp[b]):(dp[b]-dp[a-1]));
            if(tmp > M) Ma = a, Mb = b, M = tmp;
        }
        printf("Max_range: (%d,%d); Value: %lld\n", Ma, Mb, M);
    }
    return 0;
}