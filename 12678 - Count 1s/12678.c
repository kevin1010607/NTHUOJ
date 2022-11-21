#include<stdio.h>
int t, a, b, dp[1000005];
int main(void){
    for(int i = 1; i < 1000005; i++){
        int sum = 0, tmp = i;
        while(tmp){
            if(tmp%10 == 1) sum++;
            tmp /= 10;
        }
        dp[i] = dp[i-1]+sum;
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[b]-dp[a-1]);
    }
    return 0;
}