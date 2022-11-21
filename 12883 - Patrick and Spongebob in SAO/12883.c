#include<stdio.h>
#define maxn 505
int main(void){
    int n;
    scanf("%d", &n);
    int arr[maxn];
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int l , r;
        scanf("%d %d", &l, &r);
        int cnt[maxn] = {0};
        int ans = arr[l];
        for(int j = l; j <= r; j++){
            cnt[arr[j]]++;
            if(cnt[arr[j]] > cnt[ans] || (cnt[arr[j]] == cnt[ans] && arr[j] < ans))
                ans = arr[j];
        }
        printf("%d\n", ans);
        for(int j = l; j <= r; j++)
            cnt[arr[j]]--;
    }
    return 0;
}