#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int val;
    struct _node *next, *pre;
}Node;
Node *newNode(int val){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->val = val;
    tmp->next = tmp->pre = NULL;
    return tmp;
}
int compare(const void *a, const void *b){
    const int* ia = (const int*)a;
    const int* ib = (const int*)b;
    return (*ia>*ib)-(*ia<-*ib);
}
int arr[100005];
int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    qsort(arr+1, n, sizeof(int), compare);
    Node *ptr = newNode(0), *nowX = ptr, *nowY = ptr;
    for(int i = 1; i <= n; i++){
        ptr->next = newNode(arr[i]);
        ptr->next->pre = ptr;
        ptr = ptr->next;
    }

    int q;
    scanf("%d", &q);
    while(q--){
        int type, val;
        scanf("%d %d", &type, &val);
        Node *now = (type==1?nowX:nowY);
        while(now!= NULL && now->val<val) now = now->next;
        if(type == 1){
            if(now!=NULL && now->val==val){
                Node *pre = now->pre;
                Node *next = now->next;
                pre->next = next;
                if(next != NULL) next->pre = pre;
                if(now == nowY) nowY = nowY->next;
                free(now);
                now = next;
            }
            nowX = now;
        }
        if(type == 2){
            if(now!=NULL && now->val==val) printf("Yes\n");
            else printf("No\n");
            nowY = now;
        }
    }
    return 0;
}
