#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int id, num;
    struct _node *left, *right;
}Node;
Node *newNode(int id, int num){
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->num = num;
    node->left = node->right = NULL;
    return node;
}
void buildTree(Node **now, int *arr, int l, int r){
    if(l > r) {*now = NULL; return;}
    int mid = l+(r-l)/2;
    *now = newNode(mid, arr[mid]);
    buildTree(&((*now)->left), arr, l, mid-1);
    buildTree(&((*now)->right), arr, mid+1, r);
}
int search(Node *now, int num){
    if(now == NULL) return 0;
    if(num < now->num) return search(now->left, num);
    else if(num > now->num) return search(now->right, num);
    else return now->id;
}
void freeTree(Node *now){
    if(now == NULL) return;
    freeTree(now->left);
    freeTree(now->right);
    free(now);
}
int main(void){
    int n, q;
    while(~scanf("%d %d", &n, &q)){
        int *a = (int*)malloc((n+1)*sizeof(int));
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        Node *root = NULL;
        buildTree(&root, a, 1, n);
        free(a);
        while(q--){
            int num;
            scanf("%d", &num);
            int ans = search(root, num);
            if(ans) printf("%d\n", ans);
            else printf("Break your bridge!\n");
        }
        freeTree(root);
    }
    return 0;
}