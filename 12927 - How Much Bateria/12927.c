#include<stdio.h>
int dp[1000005][32];
int num[32];
int main(void){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1, s; i <= n; i++){
        scanf("%d", &s);
        num[s]++;
        for(int j = 0; j < 32; j++)
            dp[i][j] = num[j];
    }
    while(q--){
        int L, R, cnt = 0;
        scanf("%d %d", &L, &R);
        for(int i = 0; i < 32; i++)
            if(dp[R+1][i] > dp[L][i]) cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
