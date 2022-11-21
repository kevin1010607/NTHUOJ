#include<stdio.h>
#include<string.h>
char s[5005][5005];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                s[i][j] = ' ';
        int x = 0, y = -1, dir = 0;
        for(int k = n; k > 0; k--){
            int tmp = k;
            while(tmp--){
                x += dx[dir];
                y += dy[dir];
                s[x][y] = '#';
            }
            dir = (dir+1)%4;
        }
        for(int i = 0; i < n; i++){
            s[i][n] = '\0';
            printf("%s\n", s[i]);
        }
    }
    return 0;
}
