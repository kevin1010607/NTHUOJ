#include<bits/stdc++.h>
using namespace std;
int t, n, q;
vector<int> l(5005), r(5005), dp(5005);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        int res = 0;
        cin >> n >> q;
        vector<int> m(n+2);
        for(int i = 0; i < q; i++){
            cin >> l[i] >> r[i];
            m[l[i]]++, m[r[i]+1]--;
        }
        for(int i = 0; i < q; i++){
            int sec = 0, cnt = 0;
            m[l[i]]--, m[r[i]+1]++;
            for(int j = 1; j <= n; j++){
                cnt += m[j];
                if(cnt > 0) sec++;
                dp[j] = dp[j-1]+(cnt==1);
            }
            for(int j = 0; j < q; j++){
                if(j == i) continue;
                res = max(res, sec-(dp[r[j]]-dp[l[j]-1]));
            }
            m[l[i]]++, m[r[i]+1]--;
        }
        cout << res << "\n";
    }
    return 0;
}