#include<stdio.h>
#include<stdlib.h>
#define mod 10007
int x[100005], y[100005];
int dp[105][105];
int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", x+i);
    for(int i = 0; i < n; i++)
        scanf("%d", y+i);
    for(int i = 1; i <= 100; i++){
        for(int j = 0; j <= i; j++){
            if(j == 1) dp[i][j] = i;
            else if(i == j || j == 0) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%mod;
        }
    }
    int ans = 1;
    for(int i = 0; i < n; i++)
        ans = (ans*dp[x[i]][y[i]])%mod;
    printf("%d\n", ans);
    return 0;
}
