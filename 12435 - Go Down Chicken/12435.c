#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007
typedef struct _node{
    int val, idx;
    struct _node *left, *right;
}Node;
Node *newNode(int val, int idx){
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->val = val, ret->idx = idx;
    ret->left = ret->right = NULL;
    return ret;
}
Node *insert(Node *root, int val, int idx){
    if(!root) return newNode(val, idx);
    if(val < root->val) root->left = insert(root->left, val, idx);
    else if(val > root->val) root->right = insert(root->right, val, idx);
    return root;
}
int search(Node *root, int val){
    if(!root) return -1;
    if(val == root->val) return root->idx;
    else if(val < root->val) return search(root->left, val);
    else return search(root->right, val);
}
void freeTree(Node *root){
    if(!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int power(int num){
    if(num == 1) return 2;
    long long p = power(num/2);
    p = (p*p)%MOD;
    return num%2?(p*2)%MOD:p;
}
int m(int num){
    if(num%2 == 1) return 0;
    return power(num/2);
}
int n, q, val, res;
int main(void){
    while(~scanf("%d %d", &n, &q)){
        Node *root = NULL;
        for(int i = 1; i <= n; i++){
            scanf("%d(/`A`)/ ~I__I", &val);
            root = insert(root, m(val), i);
        }
        while(q--){
            scanf("%d", &val);
            res = search(root, val);
            if(res != -1) printf("%d\n", res);
            else printf("Go Down Chicken 404\n");
        }
        freeTree(root);
    }
    return 0;
}