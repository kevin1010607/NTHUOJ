#include<stdio.h>
#define maxn 105
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int a[maxn][maxn];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    int q;
    scanf("%d", &q);
    q %= 4;
    while(q-- > 0){
        int ans[maxn][maxn];
        for(int in_i = 1, ans_j = n; in_i <= n; in_i++, ans_j--)
            for(int in_j = 1, ans_i = 1; in_j <= m; in_j++, ans_i++)
                ans[ans_i][ans_j] = a[in_i][in_j];

        int temp = m;
        m = n;
        n = temp;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                a[i][j] = ans[i][j];
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(j != m) printf("%d ", a[i][j]);
            else printf("%d\n", a[i][j]);
    return 0;
}
