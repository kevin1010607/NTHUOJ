#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char A[2005], B[2005];
short dp[2005][2005];
int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s %s", A, B);
        int lenA = strlen(A);
        for(int i = 0; i < lenA; i++){
            int len = 0;
            while(A[i+len] == B[len]){
                len++;
                if(A[i+len]=='\0'||B[len]=='\0') break;
            }
			for(int j = i; j < lenA; j++){
                if(i == 0) dp[j][i] = 0;
                else dp[j][i] = dp[j][i-1];
                if(j < i+len) dp[j][i]++;
			}
        }
        int q;
        scanf("%d", &q);
        while(q--){
            int L, R;
            scanf("%d %d", &L, &R);
            int ans = dp[R][R]+1;
            if(L != 0) ans -= dp[R][L-1];
            printf("%d\n", ans);
        }
    }
    return 0;
}
