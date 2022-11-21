#include<stdio.h>
int c[1005];
int main(void){
    int n, m, ans = 0, end = 0, idx = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", c+i);
    for(int i = 0, val; i < m; i++){
        scanf("%d", &val);
        if(end || idx==n) continue;
        while(val < c[idx]){
            idx++;
            if(idx == n){
                end = 1;
                break;
            }
        }
        if(!end){
            idx++;
            if(idx == n) end = 1;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}