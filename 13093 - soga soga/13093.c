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
int main(void){
    int n;
    scanf("%d", &n);
    Node *head = newNode(-1);
    Node *now = head, *mid = NULL;
    for(int i = 1, val; i <= n; i++){
        scanf("%d", &val);
        now->next = newNode(val);
        now->next->pre = now;
        now = now->next;
        if(i == (n+1)/2) mid = now;
    }
    int q;
    scanf("%d", &q);
    now = head->next;
    while(q--){
        int type;
        scanf("%d", &type);
        if(type == 1){
            int dir;
            scanf("%d", &dir);
            if(dir == 1) now = now->next;
            else now = now->pre;
        }
        else if(type == 2){
            printf("%d\n", now->val);
        }
        else if(type == 3){
            if(mid == now) now = now->next;
            Node *tmp = mid;
            mid = mid->pre;
            mid->next = mid->next->next;
            mid->next->pre = mid;
            free(tmp);
            if(n%2 == 0) mid = mid->next;
            n--;
        }
    }
    while(head != NULL){
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}