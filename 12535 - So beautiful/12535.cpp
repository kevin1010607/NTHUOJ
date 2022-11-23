#include<bits/stdc++.h>
using namespace std;
int n, p, s, res;
vector<vector<int>> v(205, vector<int>(5, 0));
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        int cnt = 0;
        char ch;
        for(auto c : str){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                cnt++, ch = c;
        }
        int id = 0;
        if(ch == 'a') id = 0;
        else if(ch == 'e') id = 1;
        else if(ch == 'i') id = 2;
        else if(ch == 'o') id = 3;
        else if(ch == 'u') id = 4;
        v[cnt][id]++;
    }
    for(auto& i : v){
        int tmp = 0;
        for(auto& j : i) p += j/2, tmp += j%2;
        s += tmp/2;
    }
    res = s>p?p:s+(p-s)/2;
    cout << res << "\n";
    return 0;
}