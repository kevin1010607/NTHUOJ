#include<stdio.h>
#include<stdlib.h>
#define mod 1000000007
typedef struct _node{
    int id, data;
    struct _node *left, *right;
}Node;
Node *newNode(int data, int id){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->id = id;
    node->left = node->right = NULL;
    return node;
}
Node* Insert(Node *node, int data, int id){
    if(node == NULL) node = newNode(data, id);
    if(data < node->data) node->left = Insert(node->left, data, id);
    else if(data > node->data) node->right = Insert(node->right, data, id);
    return node;
}
int Search(Node *node, int data){
    if(node == NULL) return 0;
    if(data < node->data) return Search(node->left, data);
    else if(data > node->data) return Search(node->right, data);
    else return node->id;
}
void freeTree(Node *now){
    if(now == NULL) return;
    freeTree(now->left);
    freeTree(now->right);
    free(now);
}
long long two_power(int n){
    if(n == 1) return 2;
    long long tmp = two_power(n/2);
    tmp = (tmp*tmp)%mod;
    if(n%2 == 0) return tmp;
    else return (2*tmp)%mod;
}
long long method(int n){
    if(n%2 == 1) return 0;
    else return two_power(n/2);
}
int main(void){
    int n, q;
    while(~scanf("%d %d", &n, &q)){
        Node *root = NULL;
        for(int i = 1, val; i <= n; i++){
            scanf("%d(/`A`)/ ~I__I", &val);
            root = Insert(root, method(val), i);
        }
        int num;
        while(q--){
            scanf("%d", &num);
            int ans = Search(root, num);
            if(ans) printf("%d\n", ans);
            else printf("Go Down Chicken 404\n");
        }
        freeTree(root);
    }
    return 0;
}