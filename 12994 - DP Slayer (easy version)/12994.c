#include<stdio.h>
int n, m;
int w[25], v[25];
long long max(long long a, long long b){
    return (a > b ? a : b);
}
long long solve(int idx, long long weight, long long value){
    if(weight > m) return 0;
    if(idx == n) return value;
    long long p = solve(idx+1, weight, value);
    long long q = solve(idx+1, weight+w[idx], value+v[idx]);
    return max(p, q);
}
int main(void){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &w[i], &v[i]);
    int q;
    scanf("%d", &q);
    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        long long ans = solve(0, 0, 0);
        printf("%lld\n", ans);
    }
    return 0;
}