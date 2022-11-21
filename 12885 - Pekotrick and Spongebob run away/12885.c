#include<stdio.h>
#define maxn 505
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[maxn][maxn];
    int k = 1;
    for(int j = 1; j <= m;){
        for(int i = 1; i <= n; i++)
            arr[i][j] = k++;
        j++;
        for(int i = n; i >= 1; i--)
            arr[i][j] = k++;
        j++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j != 1) printf(" ");
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}