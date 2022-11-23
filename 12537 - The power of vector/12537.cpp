#include<bits/stdc++.h>
using namespace std;
int n, x, M, Mi, m, mi;
vector<int> v;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s == "push_back"){
            cin >> x;
            if(v.empty()) M = m = x, Mi = mi = 1;
            v.push_back(x);
            if(x >= M) M = x, Mi = v.size();
            if(x < m) m = x, mi = v.size();
        }
        else if(s == "pop_back"){
            if(v.empty()) continue;
            if(Mi == v.size()){
                M = v[0], Mi = 1;
                for(int i = 0; i < v.size()-1; i++)
                    if(v[i] >= M) M = v[i], Mi = i+1;
            }
            if(mi == v.size()){
                m = v[0], mi = 1;
                for(int i = 0; i < v.size()-1; i++)
                    if(v[i] < m) m = v[i], mi = i+1;
            }
            v.pop_back();
        }
        else if(s == "find"){
            cin >> x;
            if(x > v.size()) continue;
            cout << v[x-1] << "\n";
        }
        else if(s == "min"){
            if(v.empty()) continue;
            cout << m << " " << mi << "\n";
        }
        else if(s == "max"){
            if(v.empty()) continue;
            cout << M << " " << Mi << "\n";
        }
    }
    return 0;
}