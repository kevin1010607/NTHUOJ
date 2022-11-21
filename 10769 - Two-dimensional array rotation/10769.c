#include<stdio.h>
#define maxn 20
int arr[maxn][maxn];
int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    for(int s = 0; s < n; s++){
        int len = s+1;
        for(int i = s, j = 0; len > 0; i--, j++, len--){
            if(len == s+1) printf("%d", arr[i][j]);
            else printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
    for(int s = n; s <= 2*n-2; s++){
        int len = 2*n-s-1;
        for(int i = n-1, j = s-n+1; len > 0; i--, j++, len--){
            if(len == 2*n-s-1) printf("%d", arr[i][j]);
            else printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
