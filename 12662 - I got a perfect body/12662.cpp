#include<bits/stdc++.h>
using namespace std;
int t, n, p, k;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> p >> k;
        vector<int> v(n), dp(n+1);
        for(auto& i : v) cin >> i;
        sort(v.begin(), v.end());
        for(int i = 1; i <= n; i++){
            if(i >= k) dp[i] = dp[i-k]+v[i-1];
            else dp[i] = dp[i-1]+v[i-1];
        }
        for(int i = n; i >= 0; i--)
            if(dp[i] <= p) {cout << i << "\n"; break;}
    }
    return 0;
}