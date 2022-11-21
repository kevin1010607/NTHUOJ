#include<stdio.h>
long long prefix[2000005];
int main(void){
    int n, q;
    while(~scanf("%d %d", &n, &q)){
        for(int i = 1, val; i <= n; i++){
            scanf("%d", &val);
            prefix[i] = prefix[i-1]+val;
        }
        int a, b, x, y;
        long long tmp, max = -1;
        while(q--){
            scanf("%d %d", &a, &b);
            if(a > b) tmp = prefix[n]-prefix[a-1]+prefix[b];
            else tmp = prefix[b]-prefix[a-1];
            if(tmp > max) {x = a, y = b, max = tmp;}
        }
        printf("Max_range: (%d,%d); Value: %lld\n", x, y, max);
    }
    return 0;
}