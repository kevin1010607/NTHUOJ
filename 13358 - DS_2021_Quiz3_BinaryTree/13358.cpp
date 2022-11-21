#include<iostream>
#include<string>
using namespace std;
int level, idx, res, *L, *R;
void solve(string& s, int lev, int id){
    if(s[++idx] == ')') {idx++; return;}
    level = max(level, lev);
    if(L[lev]==0 || id<L[lev]) L[lev] = id;
    if(R[lev]==0 || id>R[lev]) R[lev] = id;
    idx++;
    solve(s, lev+1, id*2);
    solve(s, lev+1, id*2+1);
    idx++;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(cin >> s){
        level = idx = res = 0;
        L = new int[100005]();
        R = new int[100005]();
        solve(s, 1, 1);
        for(int i = 1; i <= level; i++){
            if(L[i] != R[i]) res = max(res, R[i]-L[i]+1);
        }
        cout << res << "\n";
        delete[] L; delete[] R;
    }
    return 0;
}