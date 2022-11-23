#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    string st;
    set<int> s;
    cin >> n;
    while(n--){
        cin >> st;
        if(st == "insert"){
            cin >> a;
            s.insert(a);
        }
        else if(st == "print"){
            if(s.size() == 0) continue;
            for(auto it = s.begin(); it != s.end(); ++it){
                if(it == s.begin()) cout << *it;
                else cout << " " << *it;
            }
            cout << "\n";
        }
        else if(st == "min"){
            if(s.size() == 0) continue;
            cout << *s.begin() << "\n";
        }
        else if(st == "range_erase"){
            cin >> a >> b;
            s.erase(s.lower_bound(a), s.upper_bound(b));
        }
        else if(st == "sum"){
            int sum = 0;
            for(auto i : s) sum += i;
            cout << sum << "\n";
        }
    }
    return 0;
}