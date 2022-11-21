#include<iostream>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
#define P pair<int, int>
using namespace std;
int n, m, x, y, eX, eY, dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
queue<P> q;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> d(n+1, vector<int>(m+1, INF));
    vector<vector<char>> s(n+1, vector<char>(m+1));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> s[i][j];
    cin >> x >> y >> eX >> eY;
    q.push(P(x, y)), d[x][y] = 0;
    while(q.size()){
        x = q.front().first, y = q.front().second, q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<=0||nx>n||ny<=0||ny>m||s[nx][ny]=='1') continue;
            if(d[x][y]+1 < d[nx][ny]) d[nx][ny] = d[x][y]+1, q.push(P(nx, ny));
        }
    }
    cout << (d[eX][eY]==INF?-1:d[eX][eY]) << '\n';
    return 0;
}