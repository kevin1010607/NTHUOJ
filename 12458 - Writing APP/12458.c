#include<stdio.h>
#define max(a, b) (a > b ? a : b)
char s[1005];
int dp[1005][1005];
int solve(int l, int r){
    if(l > r) return 0;
    if(l == r) return 1;
    if(dp[l][r] != 0) return dp[l][r];
    if(s[l] == s[r]) return dp[l][r] = solve(l+1, r-1)+2;
    return dp[l][r] = max(solve(l+1, r), solve(l, r-1));
}
int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    printf("%s\n", (k >= n-solve(0, n-1)?"Yes":"No"));
    return 0;
}
