#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    char data;
    struct _node *next;
}Node;
Node *newNode(char data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void printList(Node **head, int n){
    for(int i = 0; i < n; i++){
        Node *now = head[i];
        while(now->next != NULL){
            Node *tmp = now;
            now = now->next;
            putchar(now->data);
            free(tmp);
        }
        puts("");
    }
}
int main(void){
    int n;
    scanf("%d", &n);
    Node **head = (Node**)malloc(n*sizeof(Node*));
    Node **tail = (Node**)malloc(n*sizeof(Node*));
    for(int i = 0, val; i < n; i++){
        scanf("%d ", &val);
        head[i] = newNode(0);
        Node *now = head[i];
        for(int j = 0; j < val; j++){
            char ch;
            scanf("%c", &ch);
            now->next = newNode(ch);
            now = now->next;
        }
        tail[i] = now;
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int type, a, b;
        scanf("%d %d %d", &type, &a, &b);
        a--, b--;
        if(type == 1){
            if(head[a] == tail[a]) continue;
            tail[a]->next = head[b]->next;
            head[b]->next = head[a]->next;
            if(head[b] == tail[b]) tail[b] = tail[a];
            head[a]->next = NULL;
            tail[a] = head[a];
        }
        else if(type == 2){
            if(head[a] == tail[a]) continue;
            tail[b]->next = head[a]->next;
            tail[b] = tail[a];
            head[a]->next = NULL;
            tail[a] = head[a];
        }
        else if(type == 3){
            if(head[a]==tail[a] && head[b]==tail[b]) continue;
            Node *tmp = head[a]->next;
            head[a]->next = head[b]->next;
            head[b]->next = tmp;
            if(head[a] == tail[a]){
                tail[a] = tail[b];
                tail[b] = head[b];
            }
            else if(head[b] == tail[b]){
                tail[b] = tail[a];
                tail[a] = head[a];
            }
            else{
                tmp = tail[a];
                tail[a] = tail[b];
                tail[b] = tmp;
            }
        }
    }
    printList(head, n);
    free(tail);
    free(head);
    return 0;
}