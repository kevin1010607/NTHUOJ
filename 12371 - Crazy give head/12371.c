#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
char S[1005], p[1005];
int lenS, lenp, q, a, b, ans, dp[1005];
int main(void){
    while(~scanf("%s %s", S, p)){
        lenS = strlen(S), lenp = strlen(p);
        for(int i = 1; i <= lenS-lenp+1; i++)
            dp[i] = dp[i-1]+(!strncmp(S+i-1, p, lenp));
        ans = 0;
        scanf("%d", &q);
        while(q--){
            scanf("%d %d", &a, &b);
            if(b-lenp+1 <= a-1) continue;
            ans = max(ans, dp[b-lenp+1]-dp[a-1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}