#include<iostream>
#include<vector>
#include<queue>
#include<set>
#define P pair<vector<int>, int>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T, cnt;
    cin >> T;
    while(T--){
        vector<int> a(8), b(8), t(8);
        queue<P> q;
        set<vector<int>> s;
        cin>>a[0]>>a[1]>>a[2]>>a[7]>>a[3]>>a[6]>>a[5]>>a[4];
        cin>>b[0]>>b[1]>>b[2]>>b[7]>>b[3]>>b[6]>>b[5]>>b[4];
        int ans = -1;
        q.push(P(a, 0)), s.insert(a);
        while(q.size()){
            a = q.front().first, cnt = q.front().second, q.pop();
            if(a == b) {ans = cnt; break;}
            for(int i = 0; i < 8; i++) t[i] = a[(i+7)%8];
            if(s.count(t) == 0) q.push(P(t, cnt+1)), s.insert(t);
            for(int i = 0; i < 8; i++){
                t = a, swap(t[i], t[(i+1)%8]);
                if(s.count(t) == 0) q.push(P(t, cnt+1)), s.insert(t);
            }
            for(int i = 0; i < 4; i++){
                t = a, swap(t[i], t[i+4]);
                if(s.count(t) == 0) q.push(P(t, cnt+1)), s.insert(t);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}