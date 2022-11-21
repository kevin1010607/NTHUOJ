#include<stdio.h>
int main(void){
    int N, val;
    scanf("%d", &N);
    int cnt[10001] = {};
    for(int i = 0; i < N; i++){
        scanf("%d", &val);
        cnt[val]++;
    }
    long long ans = 0;
    for(int i = 0; i < 10001; i++)
        if(cnt[i] > 1) ans += (long long)cnt[i]*(cnt[i]-1)/2;
    printf("%lld\n", ans);
    return 0;
}
