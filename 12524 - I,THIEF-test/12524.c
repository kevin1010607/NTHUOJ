#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int dp[101], from[101], a[101], ans[101];
int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dp[1] = a[1];
    from[1] = -1;
    dp[2] = max(a[1], a[2]);
    from[2] = (a[1]>a[2]?1:0);
    for(int i = 3; i <= n; i++){
        if(dp[i-1] > dp[i-2]+a[i]){
            dp[i] = dp[i-1];
            from[i] = i-1;
        }
        else{
            dp[i] = dp[i-2]+a[i];
            from[i] = i-2;
        }
    }
    int len = 0, now = n;
    while(now > 0){
        if(from[now] == now-1) now--;
        else ans[len++] = now, now -= 2;
    }
    for(int i = len-1; i >= 0; i--)
        printf("%d ", ans[i]);
    return 0;
}