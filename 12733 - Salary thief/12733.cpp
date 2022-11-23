#include<bits/stdc++.h>
#define MOD (int)(1e9+7)
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, x;
    string s;
    cin >> t;
    while(t--){
        cin >> x >> s;
        long long n = s.size(), right = n-1, flag = 1;
        for(int i = 0; i < x; i++){
            int times = s[i]-'0';
            if(flag && n>x) flag = 0;
            if(flag){
                for(int j = 0; j < times-1; j++)
                    s += s.substr(i+1, right);
            }
            n = (n+(right*(times-1))%MOD)%MOD;
            right = (right*times-1)%MOD;
        }
        cout << n << "\n";
    }
    return 0;
}