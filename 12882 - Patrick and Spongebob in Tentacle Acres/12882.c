#include<stdio.h>
#define maxn 100
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int a[maxn][maxn];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int max = 0;
        int u, d, l, r;
        scanf("%d %d %d %d", &u, &d, &l, &r);
        for(int j = u-1; j < d; j++)
            for(int k = l-1; k < r; k++)
                if(a[j][k] > max) max = a[j][k];
        printf("%d\n", max);
    }
    return 0;
}
