#include<iostream>
#include<set>
#define ll long long
#define P pair<ll, ll>
using namespace std;
set<P> s;
ll n, q, type, v1, v2, v3, ans[100005];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) s.insert(P(0, i));
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> v1 >> v2;
            s.erase(P(ans[v1], v1));
            ans[v1] += v2;
            s.insert(P(ans[v1], v1));
        }
        else if(type == 2){
            cin >> v1 >> v2 >> v3;
            auto it = s.lower_bound(P(v2, v1));
            if(it!=s.end() && *it<=P(v2, v1+v3)){
                ans[it->second] -= (it->second-v1);
                s.erase(it);
                s.insert(P(ans[it->second], it->second));
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i];
        if(i != n) cout << ' ';
    }
    cout << '\n';
    return 0;
}