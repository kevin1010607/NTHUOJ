#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll solve(ll x){
    ll res = LLONG_MAX;
    for(int i = 0; i < 64; i++){
        ll pow2 = (ll)1<<i;
        ll l = 0, r = min((ll)1e9, (ll)1e18/pow2); // avoid overflow in line 11
        while(l <= r){
            ll mid = l+(r-l)/2, n = mid*2+1;
            ll a1 = n*(n-1)/2, a2 = n*(pow2-1);
            if(a1+a2 > x) r = mid-1;
            else if(a1+a2 < x) l = mid+1;
            else {res = min(res, n*pow2); break;}
        }
    }
    return res==LLONG_MAX?-1:res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        cout << solve(x) << "\n";
    }
    return 0;
}