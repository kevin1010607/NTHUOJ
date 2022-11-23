#include<iostream>
#define INF 0x3f3f3f3f
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x, res(INF);
    cin >> n >> m;
    n *= m;
    while(n--){
        cin >> x;
        res = min(res, x);
    }
    cout << res << "\n";
    return 0;
}