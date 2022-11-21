#include<stdio.h>
#include<string.h>
int n, m;
int stX, stY, gateX[30], gateY[30];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char s[305][305];
int used[305][305];
int solve(int x, int y){
    if(s[x][y] == '&') return 1;
    used[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if('a' <= s[nx][ny] && s[nx][ny] <= 'z'){
            int tmp = s[nx][ny]-'a';
            nx = gateX[tmp];
            ny = gateY[tmp];
        }
        if(used[nx][ny] || s[nx][ny] == '#') continue;
        if(solve(nx, ny)) return 1;
    }
    return 0;
}
int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%s", s[i]);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(s[i][j] == '$'){
                    stX = i, stY = j;
                }
                else if('A' <= s[i][j] && s[i][j] <= 'Z'){
                    gateX[s[i][j]-'A'] = i;
                    gateY[s[i][j]-'A'] = j;
                }
            }
        }
        printf("%s\n", (solve(stX, stY)?"Yes":"No"));
        memset(used, '\0', sizeof(used));
    }
    return 0;
}