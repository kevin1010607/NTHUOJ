#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int data;
    struct _node *left;
    struct _node *right;
}Node;
Node *newNode(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
Node *Insert(Node *node, int data){
    if(node == NULL){
        Node *tmp = newNode(data);
        return tmp;
    }
    if(data > node->data)
        node->right = Insert(node->right, data);
    else if(data < node->data)
        node->left = Insert(node->left, data);
    return node;
}
void Print_Post(Node *node){
    if(node == NULL) return;
    Print_Post(node->left);
    Print_Post(node->right);
    printf("%d\n", node->data);
}
int main(void){
    Node *root = NULL;
    int val = 0;
    while(scanf("%d", &val) != EOF){
        root = Insert(root, val);
    }
    Print_Post(root);
    return 0;
}
