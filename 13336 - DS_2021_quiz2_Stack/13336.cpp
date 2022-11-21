#include<iostream>
#include<string>
#include<cstring>
#define P pair<unsigned long long, unsigned long long>
#define SIZE 100
using namespace std;
template<class T>
class Stack{
private:
    T *s;
    int _top, capacity;
public:
    Stack():s(new T[SIZE]), _top(0), capacity(SIZE) {}
    void doubleSize(){
        T *t = new T[capacity*2];
        memcpy(t, s, capacity*sizeof(T));
        delete[] s;
        s = t, capacity *= 2;
    }
    int size(){
        return _top;
    }
    bool empty(){
        return _top == 0;
    }
    void push(T obj){
        if(_top == capacity) doubleSize();
        s[_top++] = obj;
    }
    void pop(){
        if(_top == 0) return;
        s[--_top].~T();
    }
    T top(){
        return s[_top-1];
    }
};
char c;
string s;
Stack<P> S;
unsigned long long t, q, v1, v2, id, n[30], m[30];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> c >> v1 >> v2;
        id = c-'A';
        n[id] = v1, m[id] = v2;
    }
    cin >> q;
    while(q--){
        unsigned long long ans = 0;
		bool k = false;
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') continue;
            if(s[i] == ')'){
                P p2 = S.top();
                S.pop();
                P p1 = S.top();
                S.pop();
                if(p1.second != p2.first){
                    k  = true;
                    break;
                }
                ans += p1.first*p1.second*p2.second;
                S.push({p1.first, p2.second});
            }
            else{
                S.push({n[s[i]-'A'], m[s[i]-'A']});
            }
        }
        if(k) cout << "error\n";
        else cout << ans << "\n";
    }
    return 0;
}