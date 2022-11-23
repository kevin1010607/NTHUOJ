#include<bits/stdc++.h>
using namespace std;
int t, n, m;
vector<int> v(200005);
int solve(int x){
    int res = 0, r = -1;
    for(int i = 0; i<n && v[i]>r; i++){
        if(i%x == 0) r++;
        res += v[i]-r;
    }
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> v[i];
        int l = 1, r = n+1, mid;
        while(l < r){
            mid = l+(r-l)/2;
            if(solve(mid) >= m) r = mid;
            else l = mid+1;
        }
        cout << (l==n+1?-1:l) << "\n";
    }
    return 0;
}