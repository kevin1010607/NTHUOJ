#include<stdio.h>
long long a[1000005];
int main(void){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1, val; i <= n; i++){
        scanf("%d(/`A`)/ ~I__I ", &val);
        a[i] = a[i-1]+val;
    }
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", a[r]-a[l-1]);
    }
    return 0;
}
