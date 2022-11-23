#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t, a, b;
vector<ll> dp(1000005);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < 1000005; i++){
        int n = i, cnt = 0;
        while(n) cnt += (n%10==1), n /= 10;
        dp[i] = dp[i-1]+cnt;
    }
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << dp[b]-dp[a-1] << "\n";
    }
    return 0;
}