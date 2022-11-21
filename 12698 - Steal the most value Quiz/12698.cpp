#include<iostream>
#define min(a,b) a<b?a:b
#define INF 0x3f3f3f3f
using namespace std;
int n, k;
int v[15], w[15];
int steal(int idx, int value, int weight){
    if(value >= k) return weight;
    if(idx == n) return INF;
    int p, q;
    p = steal(idx+1, value+v[idx], weight+w[idx]);
    q = steal(idx+1, value, weight);
    return min(p, q);
}
int main(void){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> v[i] >> w[i];
    cout << steal(0, 0, 0) << endl;
    return 0;
}