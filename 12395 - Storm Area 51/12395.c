#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 1005
typedef struct _node{
    char ch;
    int isvar, isnum;
    struct _node *left, *right;
}Node;
Node *newNode(char ch, int isvar, int isnum){
    Node *node = (Node*)malloc(sizeof(Node));
    node->ch = ch;
    node->isvar = isvar;
    node->isnum = isnum;
    node->left = node->right = NULL;
    return node;
}
char expr[MAX];
int evaluate(Node *now, int x, int y, int z){
    if(!now->isnum&&!now->isvar){
        int op1 = evaluate(now->left, x, y, z);
        int op2 = evaluate(now->right, x, y, z);
        switch(now->ch){
            case '+': return op1+op2;
            case '-': return op1-op2;
            case '*': return op1*op2;
            case '/': return op1/op2;
            default: return 0;
        }
    }
    else if(now->isvar){
        switch(now->ch){
            case 'x': return x;
            case 'y': return y;
            case 'z': return z;
            default: return 0;
        }
    }
    else if(now->isnum) return (int)(now->ch);
    return 0;
}
void builtTree(Node **now){
    static int idx;
    while(isspace(expr[idx])) idx++;
    if(!isdigit(expr[idx])){
        if(expr[idx]>='x'&&expr[idx]<='z'){
            *now = newNode(expr[idx], 1, 0);
            idx++;
        }
        else{
            *now = newNode(expr[idx], 0, 0);
            idx++;
            builtTree(&((*now)->left));
            builtTree(&((*now)->right));
        }
    }
    else{
        int num = expr[idx]-'0';
        while(isdigit(expr[++idx]))
            num = 10*num+expr[idx]-'0';
        *now = newNode((char)num, 0, 1);
    }
}
void printInorder(Node *now){
    if(now == NULL) return;
    printInorder(now->left);
    if(now->isnum) printf("%d", now->ch);
    else printf("%c", now->ch);
    printInorder(now->right);
}
void freeTree(Node *now){
    if(now == NULL) return;
    freeTree(now->left);
    freeTree(now->right);
    free(now);
}
int main(void){
    int x, y, z;
    scanf("%[^\n]", expr);
    scanf("%d %d %d", &x, &y, &z);
    Node *root = NULL;
    builtTree(&root);
    printInorder(root);
    puts("");
    printf("%d\n", evaluate(root, x, y, z));
    freeTree(root);
    return 0;
}