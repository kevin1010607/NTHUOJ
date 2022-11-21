#include<iostream>
#define max(a, b) (a>b?a:b)
using namespace std;
int n, k;
int *v, *w;
int solve(int idx, int weight, int value){
    if(weight > k) return 0;
    if(idx == n) return value;
    int p, q;
    p = solve(idx+1, weight+w[idx], value+v[idx]);
    q = solve(idx+1, weight, value);
    return max(p, q);
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    v = new int[n];
    w = new int[n];
    for(int i = 0 ; i < n; i++)
        cin >> v[i] >> w[i];
    cout << solve(0, 0, 0) << '\n';
    delete []v;
    delete []w;
    return 0;
}