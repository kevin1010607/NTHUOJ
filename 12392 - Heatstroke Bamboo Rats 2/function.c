#include "function.h"
#include<stdio.h>
#include<stdlib.h>
#define left left_child
#define right right_child
Node *newNode(int level){
    Node *node = (Node*)malloc(sizeof(Node));
    node->level = level;
    node->left = node->right = NULL;
    return node;
}
Node* findMin(Node *now){
    if(now == NULL) return NULL;
    while(now->left) now = now->left;
    return now;
}
void build_tree(Node **now, int *arr, int l, int r){
    if(l > r) return;
    int mid = l+(r-l)/2;
    *now = newNode(arr[mid]);
    build_tree(&((*now)->left), arr, l, mid-1);
    build_tree(&((*now)->right), arr, mid+1, r);
}
int query_heatstroke(Node *now, int x){
    if(now == NULL) return 0;
    if(x < now->level) return query_heatstroke(now->left, x);
    else if(x > now->level) return query_heatstroke(now->right, x);
    else return 1;
}
void eat_rat(Node **root, int x){
    if(*root == NULL) return;
    if(x < (*root)->level) eat_rat(&((*root)->left), x);
    else if(x > (*root)->level) eat_rat(&((*root)->right), x);
    else{
        if((*root)->left && (*root)->right){
            Node *tmp = findMin((*root)->right);
            (*root)->level = tmp->level;
            eat_rat(&((*root)->right), tmp->level);
        }
        else{
            Node *tmp = *root;
            if((*root)->left) *root = (*root)->left;
            else if((*root)->right) *root = (*root)->right;
            else *root = NULL;
            free(tmp);
        }
    }
}
void buy_rat(Node **root, int x){
    if(*root == NULL) {*root = newNode(x); return;}
    if(x < (*root)->level) buy_rat(&((*root)->left), x);
    else if(x > (*root)->level) buy_rat(&((*root)->right), x);
    else{
        if((*root)->left == NULL) (*root)->left = newNode(x);
        else if((*root)->right == NULL) (*root)->right = newNode(x);
        else{
            buy_rat(&((*root)->right), x);
        }
    }
}