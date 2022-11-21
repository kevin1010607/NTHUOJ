#include<stdio.h>
#include<string.h>
const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const char S[] = "ICPCASIASG";
char s[105][105];
int startX[105], startY[105], idx;
int solve(int x, int y, int now, int n){
    if(now == 10) return 1;
    if(s[x][y] != S[now]) return 0;
    for(int i = 0; i < 8; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        if(solve(nx, ny, now+1, n)) return 1;
    }
    return 0;
}
int main(void){
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        fgets(s[i], (n+1)*sizeof(char), stdin);
        for(int j = 0; j < n; j++){
            if(s[i][j] == 'I'){
                startX[idx] = i;
                startY[idx] = j;
                idx++;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < idx; i++){
        ans = solve(startX[i], startY[i], 0, n);
        if(ans) break;
    }
    if(ans) printf("YES\n");
    else printf("NO\n");
    return 0;
}