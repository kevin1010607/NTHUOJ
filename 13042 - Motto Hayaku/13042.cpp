#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, int>
using namespace std;
vector<ll> M(100005);
vector<P> v, f;
set<P> s;
int n;
ll x, A, B, m, sp(0), mi(-1), ch, fin;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x >> A >> B >> m;
    for(int i = 0; i < n; i++){
        cin >> M[i];
        f.push_back(make_pair(M[i], i));
    }
    sort(f.begin(), f.end());
    v = f;
    for(int i = 1; i < n; i++) v[i].first += v[i-1].first;
    for(int i = 0; i < n; i++) s.insert({(i+1)*f[i].first-v[i].first,i});
    ll r = m, l = x*n-v[n-1].first;
    if(l <= r){
        cout << A*n+B*x << '\n';
        for(int i = 0; i < n; i++) {
            if(i != n-1) cout << x << " ";
            else cout << x << "\n";
        }
    }
    else{
        int ma = 0;
        for (int i = n; i >= 0; i--) {
            if(i != n) r -= x-f[i].first;
            if (r < 0) break;
            if(i != n) ma++;
            auto mp = s.lower_bound({r, 0});
            if(mp->first != r) mp--;
            ll md = mp->second, st = r - mp->first;
            ll nm = f[md].first+st/(md+1), ns = B*nm+A*ma;
            if(ns > sp) ch = ma, sp = ns, fin = nm, mi = md;
        }
        for(int i = 0; i < n; i++){
            if(i <= mi) f[i].first = fin;
            if(i >= n-ch) f[i].first = x;
            M[f[i].second] = f[i].first;
        }
        cout << sp << '\n';
        for(int i = 0; i < n; i++) {
            if(i != n-1) cout << M[i] << " ";
            else cout << M[i] << "\n";
        }
    }
    return 0;
}