#include<stdio.h>
#define maxn 505
int main(void){
    //Solution_1
    int n;
    scanf("%d", &n);
    int a[maxn][maxn];

    int k = 1;
    int i = 0, j = 0;
    int x = 2, y = 0, z = 1;

    while(k <= 4*n*n){
        while(k <= x*n-y)
            a[i][j++] = k++;
        x += 2;
        y += z;
        i++, j--;
        while(k <= x*n-y)
            a[i++][j] = k++;
        x += 2;
        y += z++;
        i--, j--;
        while(k <= x*n-y)
            a[i][j--] = k++;
        x += 2;
        y += z;
        i--, j++;
        while(k <= x*n-y)
            a[i--][j] = k++;
        x += 2;
        y += z++;
        i++, j++;
    }

    for(i = 0; i < 2*n; i++){
        for(j = 0; j < 2*n; j++){
            if(j != 2*n-1) printf("%d ", a[i][j]);
            else printf("%d\n", a[i][j]);
        }
    }

    //Solution_2

    /*int n;
    scanf("%d", &n);
    int a[maxn][maxn];
    int k = 1;

    for(int i = 1; i <= n; i++){
        int len = 2*(n-i+1)-1;
        for(int j = 0; j < len; j++)
            a[i][i+j] = k++;
        for(int j = 0; j < len; j++)
            a[i+j][i+len] = k++;
        for(int j = 0; j < len; j++)
            a[i+len][i+len-j] = k++;
        for(int j = 0; j < len; j++)
            a[i+len-j][i] = k++;
    }

    for(int i = 1; i <= 2*n; i++){
        for(int j = 1; j <= 2*n; j++){
            if(j != 2*n) printf("%d ", a[i][j]);
            else printf("%d\n", a[i][j]);
        }
    }*/

    return 0;
}
