#include<iostream>
#include"function.h"
using namespace std;
void Array::move(int d){cur = max(1, min(cur+d, size));}
void Array::remove(){
    for(int i = cur; i < size; i++) mem[i] = mem[i+1];
    size--, cur = min(cur, size);
}
void List::move(int d){
    if(d > 0) while(d-- && cur->getNxt()) cur = cur->getNxt();
    else if(d < 0) while(d++ && cur->getPre()) cur = cur->getPre();
}
void List::remove(){
    cur = cur->remove(); size--;
}
ContainerBase* create(int n, int *arr, int q, Operation *ops){
    int op2 = 0, op3 = 0;
    for(int i = 1; i <= q; i++){
        if(ops[i].type == 2) op2++;
        else if(ops[i].type == 3) op3++;
    }
    return (op2>op3?(ContainerBase*)new Array(n, arr):(ContainerBase*)new List(n, arr));
}

/*#include"function.h"
#include<iostream>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
void Array::move(int d){}
void Array::remove(){}
void List::move(int d){}
void List::remove(){}
ContainerBase* create(int n, int *arr, int q, Operation *ops){
    rope<int> R;
    for(int i = 1; i <= n; i++) R.push_back(arr[i]);
    int p = 1, T = n;
    for(int i = 1; i <= q; i++){
        if(ops[i].type == 1) cout << R[p-1] << '\n', ops[i].type = -1;
        else if(ops[i].type == 2) p = max(1, min(p+ops[i].d, T));
        else R.erase(p-1, 1), T--, p = min(p, T);
    }
    return new Array(n, arr);
}*/