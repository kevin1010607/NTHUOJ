#include<bits/stdc++.h>
using namespace std;
typedef struct{int x, y, u;}P;
int t, n, r, k;
int dfs(P& now, vector<P>& v){
    int res = 1;
    now.u = 1;
    for(auto& p : v){
        if(p.u) continue;
        if(((now.x-p.x)*(now.x-p.x)+(now.y-p.y)*(now.y-p.y)) <= r*r)
            res += dfs(p, v);
    }
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> r >> k;
        vector<P> v(n);
        for(auto& p : v) cin >> p.x >> p.y;
        int res1 = 0, res2 = 0;
        for(auto& p : v){
            if(p.u) continue;
            int cnt = dfs(p, v);
            (cnt<k)?(res1++):(res2++);
        }
        cout << res1 << " " << res2 << "\n";
    }
    return 0;
}