#include<bits/stdc++.h>
using namespace std;
typedef struct{int x, y, step;}P;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x, y, res = -1, T = 0;
    cin >> n >> m;
    vector<string> v(n);
    vector<vector<bool>> used(n, vector<bool>(m, false));
    int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
    for(auto& s : v) cin >> s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 'I') x = i, y = j;
            else if(v[i][j] == 'T') T++;
        }
    }
    queue<P> q;
    q.push({x, y, 0});
    used[x][y] = true;
    while(!q.empty()){
        P now = q.front();
        q.pop();
        if(v[now.x][now.y] == 'T') T--;
        if(T == 0) {res = now.step; break;}
        for(int i = 0; i < 4; i++){
            int nx = now.x+dx[i], ny = now.y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m||used[nx][ny]||v[nx][ny]=='C') continue;
            q.push({nx, ny, now.step+1});
            used[nx][ny] = true;
        }
    }
    cout << res << "\n";
    return 0;
}