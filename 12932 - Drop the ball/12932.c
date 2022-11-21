#include<stdio.h>
#define maxn 505
int main(void){
    int n, m;
    char a[maxn][maxn] = {};
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%s", a[i]+1);

    int q;
    scanf("%d", &q);
    while(q--){
        int j;
        scanf("%d", &j);
        for(int i = 1; i <= n; i++){
            if(a[i][j] == '\\' && j == m){
                printf("Right!\n");
                break;
            }
            else if(a[i][j] == '/' && j == 1){
                printf("Left!\n");
                break;
            }
            else if((a[i][j] == '\\' && a[i][j+1] == '/') || (a[i][j] == '/' && a[i][j-1] == '\\')){
                printf("Stuck QQ\n");
                break;
            }
            else{
                if(a[i][j] == '\\') j++;
                else j--;
            }
            if(i == n) printf("Position: %d\n", j);
        }
    }
    return 0;
}
