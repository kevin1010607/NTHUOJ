#include<iostream>
#include<cstring>
#define SIZE 100
#define P pair<int, int>
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
int n, val;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Stack<P> s;
    s.push(P(0, 0));
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> val;
        while(s.top().first >= val) s.pop();
        cout << s.top().second << " ";
        s.push(P(val, i));
    }
    cout << "\n";
    return 0;
}