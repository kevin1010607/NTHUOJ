#include<stdio.h>
int w[25], v[25];
long long table [25][1005];
int n, m;
long long max(long long a, long long b){
    return (a > b ? a : b);
}
void solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            long long p, q;
            p = table[i-1][j];
            int temp = j-w[i];
            q = temp>=0?v[i]+table[i-1][temp]:0;
            table[i][j] = max(p, q);
        }
    }
}
int main(void){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &w[i], &v[i]);
    solve();
    printf("%lld\n", table[n][m]);
    return 0;
}