#include<stdio.h>
#define min(a,b) a<b?a:b
int n, q, l, r, m, val;
long long dp[1000005];
int main(void){
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++){
        scanf("%d", &val);
        dp[i] = dp[i-1]+(val<0?0:val);
    }
    while(q--){
        scanf("%d %d %d", &l, &r, &m);
        printf("%lld\n", dp[l+m-1]-dp[l-1]);
    }
    return 0;
}