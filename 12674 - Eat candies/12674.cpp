#include<bits/stdc++.h>
using namespace std;
int t, r, g, b, res, a[3];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> r >> g >> b;
        a[0] = min({r, g, b});
        a[2] = max({r, g, b});
        a[1] = r+g+b-a[0]-a[2];
        if(a[2] > a[0]+a[1]) res = a[0]+a[1];
        else res = (a[0]+a[1]+a[2])/2;
        cout << res << "\n";
    }
    return 0;
}