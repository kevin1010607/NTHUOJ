#include<iostream>
using namespace std;
int n, val, a[200005];
int BS(long long num, int l, int r){
    int mid = (l+r)/2;
    if(a[mid] > num) return BS(num, l, mid-1);
    else if(a[mid] < num) return BS(num, mid+1, r);
    else return mid;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    while(cin >> val) cout << BS(val, 0, n-1) << '\n';
    return 0;
}
