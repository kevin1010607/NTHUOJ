#include<stdio.h>
#include<stdlib.h>
#include "function.h"
#define num number
#define left ptr_to_left_node
#define right ptr_to_right_node
Node *newNode(int val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->num = val;
    node->left = node->right = NULL;
    return node;
}
Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end){
    if(inorder_start > inorder_end) return NULL;
    int p;
    for(p = inorder_start; p <= inorder_end; p++)
        if(*preorder == inorder[p]) break;
    Node *root = newNode(*preorder);
    root->left = buildTree(inorder, preorder+1, inorder_start, p-1);
    root->right = buildTree(inorder, preorder+1+p-inorder_start, p+1, inorder_end);
    return root;
}
void showPostorder(Node* root){
    if(root == NULL) return;
    showPostorder(root->left);
    showPostorder(root->right);
    printf("%d ", root->num);
}
void freeTree(Node *root){
    if(root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}