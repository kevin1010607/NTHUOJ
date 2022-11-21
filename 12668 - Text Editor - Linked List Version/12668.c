#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    char data;
    struct _node *prev, *next;
}Node;
Node *newNode(char data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}
void showList(Node *head, Node *tail){
    while(head->next != tail){
        head = head->next;
        putchar(head->data);
        free(head->prev);
    }
    puts("");
    free(head->next);
    free(head);
}
void solve(char* op, int n){
    Node *head = newNode(0);
    Node *tail = newNode(0);
    head->next = tail;
    tail->prev = head;
    Node *now = head, *tmp = NULL;
    for(int i = 0; i < n; i++){
        switch(op[i]){
            case 'L':
                now = now->prev;
                break;
            case 'R':
                now = now->next;
                break;
            case 'B':
                tmp = now;
                now->prev->next = now->next;
                now->next->prev = now->prev;
                now = now->prev;
                free(tmp);
                break;
            default:
                tmp = newNode(op[i]);
                tmp->prev = now;
                tmp->next = now->next;
                now->next->prev = tmp;
                now->next = tmp;
                now = tmp;
                break;
        }
    }
    showList(head, tail);
}
int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char *op = (char*)malloc((n+1)*sizeof(char));
        scanf("%s", op);
        solve(op, n);
        free(op);
    }
    return 0;
}