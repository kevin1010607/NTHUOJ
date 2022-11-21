#include<iostream>
#include<queue>
using namespace std;
queue<int> q, p[3];
int main(void){
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, v;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        if(s == "ENQUEUE"){
            cin >> v;
            if(p[v%3].empty()) q.push(v%3);
            p[v%3].push(v);
        }
        else if(s == "DEQUEUE"){
            cout << p[q.front()].front() << '\n';
            p[q.front()].pop();
            if(p[q.front()].empty()) q.pop();
        }
    }
    return 0;
}