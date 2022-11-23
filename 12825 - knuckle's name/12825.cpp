#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#define N 2005
using namespace std;
void dfs(int idx, vector<bitset<N>>& v, vector<bool>& b){
    b[idx] = true;
    for(int i = 0; i < 26; i++){
        if(b[i] || v[i].none()) continue;
        if((v[idx]&v[i]) != bitset<N>(0)) dfs(i, v, b);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    string s;
    cin >> t;
    while(t--){
        int res = 0;
        vector<bool> b(26);
        vector<bitset<N>> v(26);
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s;
            for(auto c : s) v[c-'a'][i] = 1;
        }
        for(int i = 0; i < 26; i++){
            if(b[i] || v[i].none()) continue;
            dfs(i, v, b);
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}