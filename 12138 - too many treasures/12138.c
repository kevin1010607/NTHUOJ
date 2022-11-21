#include<stdio.h>
long long prefix[1000005];
int main(void){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1, val; i <= n; i++){
        scanf("%d", &val);
        prefix[i] = prefix[i-1];
        if(val > 0) prefix[i] += val;
    }
    int l, r, m;
    while(q--){
        scanf("%d %d %d", &l, &r, &m);
        printf("%lld\n", prefix[l-1+m]-prefix[l-1]);
    }
    return 0;
}