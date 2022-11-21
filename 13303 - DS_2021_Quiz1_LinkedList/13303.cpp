#include<iostream>
using namespace std;
class List{
    class Node{
    public:
        int val;
        Node *next;
        Node(int val, Node *next):val(val), next(next){}
    };
private:
    int num;
    Node *now;
public:
    List(int *a, int n){
        now = new Node(a[0], NULL);
        now->next = now;
        num = 1;
        for(int i = n-1; i > 0; i--) Insert(a[i]);
    }
    int getNum(){return num;}
    void Insert(int val){
        Node *node = new Node(val, now->next);
        now->next = node;
        num++;
    }
    void Delete(unsigned long long cnt){
        cnt = (cnt+(num-1))%num;
        Node *n = now;
        while(cnt--) n = n->next;
        Node *tmp = n->next;
        n->next = tmp->next;
        delete tmp;
        now = n->next;
        num--;
    }
    void Print(){
        Node *n = now;
        for(int i = 0; i < num; i++){
            if(i != num-1) cout << n->val << " ";
            else cout << n->val << "\n";
            n = n->next;
        }
    }
    void FreeList(){
        while(num--){
            Node *tmp = now;
            now = now->next;
            delete tmp;
        }
    }
};
int n, s[10005];
unsigned long long a, b;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    List list(s, n);
    while(cin>>a>>b && a!=-1 && b!=-1){
        if(a == 1) list.Delete(b);
        else if(a == 2) list.Insert(b);
        if(list.getNum() == 1) break;
    }
    list.Print();
    list.FreeList();
    return 0;
}