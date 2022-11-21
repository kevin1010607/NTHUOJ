#include<stdio.h>
#define maxn 1005
int a[maxn][maxn];
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++)
            if(i != n-1) printf("%d ", a[i][j]);
            else printf("%d\n", a[i][j]);
    return 0;
}
