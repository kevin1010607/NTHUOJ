#include<iostream>
#include<vector>
#include<unordered_map>
#define ull unsigned long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ull n, k, mul[11] = {1};
    for(int i = 1; i < 11; i++) mul[i] = mul[i-1]*10;
    while(cin >> n >> k){
        vector<ull> v(n), l(n);
        unordered_map<ull, ull> m[11];
        for(int i = 0; i < n; i++){
            cin >> v[i];
            ull tmp = v[i];
            while(tmp) {l[i]++, tmp/=10;}
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < 11; j++){
                ull now = (v[i]*mul[j])%k;
                m[j][now]++;
            }
        }
        ull res = 0;
        for(int i = 0; i < n; i++){
            ull now = (k-(v[i]%k))%k;
            res += (m[l[i]][now]);
            if((v[i]*mul[l[i]])%k == now) res--;
        }
        cout << res << "\n";
    }
    return 0;
}