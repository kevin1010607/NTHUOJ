#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
map<int, vector<int>> m;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(cin >> s){
        if(s == "output"){
            for(auto i:m){
                for(auto j:i.second) cout << j << ' ';
                cout << '\n';
            }
        }
        else if(s == "insert"){
            int val, key = 0;
            vector<int> v;
            while(cin >> val && val) v.push_back(val);
            for(int i = 0; i < v.size(); i++) key += v[i]*(v.size()-i);
            if(m.find(key) != m.end()){
                cout << "exist\n";
                m.erase(key);
                reverse(v.begin(), v.end());
                key = 0;
                for(int i = 0; i < v.size(); i++) key += v[i]*(v.size()-i);
            }
            m.insert(pair<int, vector<int>>(key, v));
        }
        else if(s == "range_out"){
            int val, key1 = 0, key2 = 0;
            vector<int> v;
            while(cin >> val && val) v.push_back(val);
            for(int i = 0; i < v.size(); i++) key1 += v[i]*(v.size()-i);
            v.clear();
            while(cin >> val && val) v.push_back(val);
            for(int i = 0; i < v.size(); i++) key2 += v[i]*(v.size()-i);
            for(auto i:m){
                if(i.first>=key1 && i.first<=key2){
                    for(auto j:i.second) cout << j << ' ';
                    cout << '\n';
                }
            }
        }
    }
    return 0;
}