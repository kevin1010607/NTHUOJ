#include<stdio.h>
#define INF 0x3f3f3f3f
int main(void){
    int n, m, ans = INF;
    scanf("%d %d", &n, &m);
    for(int i = 0, val; i < n*m; i++){
        scanf("%d", &val);
        if(val < ans) ans = val;
    }
    printf("%d\n", ans);
    return 0;
}