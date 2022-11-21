#include<stdio.h>
#include<stdlib.h>
#include "function.h"
Node *newNode(int level){
    Node *node = (Node*)malloc(sizeof(Node));
    node->level = level;
    node->left_child = node->right_child = NULL;
    return node;
}
Node *findMin(Node *now){
    if(now == NULL) return NULL;
    while(now->left_child != NULL)
        now = now->left_child;
    return now;
}
void build_tree(Node **now, int *arr, int l, int r){
    if(l > r) {*now = NULL; return;}
    int mid = l+(r-l)/2;
    *now = newNode(arr[mid]);
    build_tree(&((*now)->left_child), arr, l, mid-1);
    build_tree(&((*now)->right_child), arr, mid+1, r);
}
int query_heatstroke(Node *now, int x){
    if(now == NULL) return 0;
    if(x < now->level) return query_heatstroke(now->left_child, x);
    else if(x > now->level) return query_heatstroke(now->right_child, x);
    else return 1;
}
void eat_rat(Node **root, int x){
    if(*root == NULL) return;
    if(x < (*root)->level) eat_rat(&((*root)->left_child), x);
    else if(x > (*root)->level) eat_rat(&((*root)->right_child), x);
    else{
        if((*root)->left_child && (*root)->right_child){
            Node *tmp = findMin((*root)->right_child);
            (*root)->level = tmp->level;
            eat_rat(&((*root)->right_child), tmp->level);
        }
        else{
            Node *tmp = *root;
            if((*root)->left_child != NULL)
                *root = (*root)->left_child;
            else if((*root)->right_child != NULL)
                *root = (*root)->right_child;
            else *root = NULL;
            free(tmp);
        }
    }
}