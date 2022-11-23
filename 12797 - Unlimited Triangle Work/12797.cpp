#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t, a, b, c, d;
int main(void){
    cin >> t;
    while(t--){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        ll res = 0;
        vector<int> dp(100005);
        cin >> a >> b >> c >> d;
        for(int i = a; i <= b; i++)
            dp[i+b]++, dp[i+c+1]--;
        for(int i = a+b; i <= b+c; i++){
            dp[i] = dp[i-1]+dp[i];
            if(i-1 >= c) res += (ll)dp[i]*(min(i-1, d)-c+1);
        }
        cout << res << "\n";
    }
    return 0;
}