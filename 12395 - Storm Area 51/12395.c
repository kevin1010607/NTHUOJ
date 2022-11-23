#include<stdio.h>
#include<stdlib.h>
typedef enum{Op, Var, Num}Type;
Type getType(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/') return Op;
    else if(c=='x' || c=='y' || c=='z') return Var;
    else return Num;
}
typedef struct _node{
    Type type;
    int val;
    char ch;
    struct _node *left, *right;
}Node;
Node *newNode(int val, char ch, Type type){
    Node *res = (Node*)malloc(sizeof(Node));
    res->val = val, res->ch = ch, res->type = type;
    res->left = res->right = NULL;
    return res;
}
Node* buildTree(){
    char c = getchar();
    Type type = getType(c);
    Node *root = newNode(0, c, type);
    if(type == Op){
        getchar();
        root->left = buildTree();
        root->right = buildTree();
    }
    else if(type == Num){
        ungetc(c, stdin);
        scanf("%d", &(root->val));
        getchar();
    }
    else if(type == Var) getchar();
    return root;
}
void Inorder(Node *root){
    if(!root) return;
    Inorder(root->left);
    root->type==Num?printf("%d", root->val):printf("%c", root->ch);
    Inorder(root->right);
}
void freeTree(Node *root){
    if(!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int evaluate(Node *root, int x, int y, int z){
    if(root->type == Op){
        int l = evaluate(root->left, x, y, z);
        int r = evaluate(root->right, x, y, z);
        switch(root->ch){
            case'+': return l+r;
            case'-': return l-r;
            case'*': return l*r;
            case'/': return l/r;
        }
    }
    else if(root->type == Var){
        switch(root->ch){
            case'x': return x;
            case'y': return y;
            case'z': return z;
        }
    }
    return root->val;
}
int main(void){
    int x, y, z;
    Node *root = buildTree();
    scanf("%d %d %d", &x, &y, &z);
    Inorder(root);
    puts("");
    printf("%d\n", evaluate(root, x, y, z));
    freeTree(root);
    return 0;
}