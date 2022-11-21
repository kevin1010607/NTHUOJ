#include<stdio.h>
#include<string.h>
char s[105][105];
char tmp[105][105];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int main(void){
    int r, c, T;
    scanf("%d %d %d", &r, &c, &T);
    for(int i = 0; i < r; i++)
        scanf("%s", s[i]);
    for(int t = 0; t < T; t++){
        memcpy(tmp, s, sizeof(tmp));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(tmp[i][j] != 'F') continue;
                for(int d = 0; d < 4; d++){
                    int x = i+dx[d], y = j+dy[d];
                    if(x<0||x>=r||y<0||y>=c) continue;
                    if(tmp[x][y] == 'C')
                        s[x][y] = 'F';
                }
            }
        }
    }
    for(int i = 0; i < r; i++)
        printf("%s\n", s[i]);
    return 0;
}
