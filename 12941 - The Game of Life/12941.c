#include<stdio.h>
#include<string.h>
int s[505][505];
int cnt[505][505];
static int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
static int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int main(void){
    int n, m, T;
    scanf("%d %d %d", &n, &m, &T);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &s[i][j]);
    for(int t = 0; t < T; t++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(s[i][j] == 0) continue;
                for(int k = 0; k < 8; k++){
                    int x = i+dx[k], y = j+dy[k];
                    if(x<0||x>=n||y<0||y>=m) continue;
                    cnt[x][y]++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!(cnt[i][j]==2||cnt[i][j]==3)&&s[i][j]==1)
                    s[i][j] = 0;
                else if(cnt[i][j]==3&&s[i][j]==0)
                    s[i][j] = 1;
                cnt[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j != m-1) printf("%d ", s[i][j]);
            else printf("%d\n", s[i][j]);
        }
    }
    return 0;
}