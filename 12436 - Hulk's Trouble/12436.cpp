#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, x;
    cin >> n;
    vector<int> v(n);
    for(auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    cin >> q;
    while(q--){
        cin >> x;
        int res = (upper_bound(v.begin(), v.end(), x))-(lower_bound(v.begin(), v.end(), x));
        cout << res << "\n";
    }
    return 0;
}