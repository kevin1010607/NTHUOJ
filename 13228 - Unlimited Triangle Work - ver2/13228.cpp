#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t, a,b,c,d;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        ll res = 0;
        vector<int> dp(100005);
        for(int i = a; i <= b; i++){
            dp[i+b]++, dp[i+c+1]--;
        }
        for(int i = a+b; i <= 2*d; i++){
            dp[i] += dp[i-1];
        }
        for(int i = a+b; i <= 2*d; i++){
            dp[i] += dp[i-1];
        }
        for(int i = c; i <= d; i++){
            if(i%2 == 0)  res += dp[(int)(1.5*i-1)]-dp[i];
            else res += dp[(int)(1.5*i)]-dp[i];
        }
        cout << res << "\n";
    }
    return 0;
}