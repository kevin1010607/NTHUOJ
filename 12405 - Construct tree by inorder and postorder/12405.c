#include<stdio.h>
#include<stdlib.h>
static int id;
typedef struct _node{
    int data;
    struct _node *left, *right;
}Node;
Node *newNode(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
Node *buildTree(int *inorder, int *postorder, int in_start, int in_end){
    if(in_start > in_end) return NULL;
    int p;
    for(p = in_start; p <= in_end; p++)
        if(*postorder == inorder[p]) break;
    Node *node = newNode(*postorder);
    node->left = buildTree(inorder, postorder-1-(in_end-p), in_start, p-1);
    node->right = buildTree(inorder, postorder-1, p+1, in_end);
    return node;
}
void printPreorder(Node *now){
    if(now == NULL) return;
    printf("%d ", now->data);
    printPreorder(now->left);
    printPreorder(now->right);
}
void freeTree(Node *now){
    if(now == NULL) return;
    freeTree(now->left);
    freeTree(now->right);
    free(now);
}
int main(void){
    int n;
    while(~scanf("%d", &n)){
        int inorder[100], postorder[100];
        for(int i = 0; i < n; i++)
            scanf("%d", inorder+i);
        for(int i = 0; i < n; i++)
            scanf("%d", postorder+i);
        Node *root = buildTree(inorder, postorder+n-1, 0, n-1);
        printf("testcase%d: ", ++id);
        printPreorder(root);
        puts("");
        freeTree(root);
    }
}