#include<stdio.h>
int n, m;
int w[25], v[25];
long long sol[25][25];
long long max(long long a, long long b){
    return (a > b ? a : b);
}
long long solve(int idx, long long weight, long long value, int a, int b){
    if(weight > m) return 0;
    if(idx > n) return value;
    long long p = solve(idx+1, weight, value, a, b);
    if(idx == a || idx == b) return p;
    long long q = solve(idx+1, weight+w[idx], value+v[idx], a, b);
    return max(p, q);
}
int main(void){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &w[i], &v[i]);
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(w[i]+w[j] > m) sol[i][j] = 0;
            else sol[i][j] = solve(1, w[i]+w[j], v[i]+v[j], i, j);
        }
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", sol[a][b]);
    }
    return 0;
}