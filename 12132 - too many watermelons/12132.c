#include<stdio.h>
#include<stdlib.h>
int eat[200005];
int cnt;
typedef struct _node{
    int data;
    struct _node *next;
}Node;
Node *newNode(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void freeNode(Node *node){
    while(node != NULL){
        Node *tmp = node;
        node = node->next;
        free(tmp);
    }
}
void deleteNext(Node **head){
    Node *ptr = *head;
    Node *tmp = ptr->next;
    ptr->next = ptr->next->next;
    free(tmp);
}
int main(void){
    int n;
    scanf("%d", &n);
    Node *head = newNode(-1);
    Node *ptr = head;
    for(int i = 0, val; i < n; i++){
        scanf("%d", &val);
        ptr->next = newNode(val);
        ptr = ptr->next;
    }
    ptr = head;
    for(int i = 0, val; i < n; i++){
        scanf("%d", &val);
        if(eat[val]) printf("0%c", (i==n-1?'\n':' '));
        else{
            cnt = 1;
            while(ptr->next->data != val){
                eat[ptr->next->data] = 1;
                deleteNext(&ptr);
                cnt++;
            }
            eat[val] = 1;
            deleteNext(&ptr);
            printf("%d%c", cnt, (i==n-1?'\n':' '));
        }
    }
    freeNode(head);
    return 0;
}
