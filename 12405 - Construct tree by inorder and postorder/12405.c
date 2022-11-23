#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int val;
    struct _node *left, *right;
}Node;
Node *newNode(int val){
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->val = val, ret->left = ret->right = NULL;
    return ret;
}
Node *buildTree(int *inorder, int *postorder, int size){
    if(size <= 0) return NULL;
    Node *root = newNode(postorder[size-1]);
    int idx = 0;
    while(inorder[idx] != postorder[size-1]) idx++;
    root->left = buildTree(inorder, postorder, idx);
    root->right = buildTree(inorder+idx+1, postorder+idx, size-idx-1);
    return root;
}
void preorder(Node *root){
    if(!root) return;
    printf(" %d", root->val);
    preorder(root->left);
    preorder(root->right);
}
void freeTree(Node *root){
    if(!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int n, id, in[105], post[105];
int main(void){
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++) scanf("%d", in+i);
        for(int i = 0; i < n; i++) scanf("%d", post+i);
        Node *root = buildTree(in, post, n);
        printf("testcase%d:", ++id);
        preorder(root);
        printf(" \n");
        freeTree(root);
    }
    return 0;
}