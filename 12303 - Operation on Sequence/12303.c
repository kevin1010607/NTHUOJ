#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct _node{
    int data;
    struct _node *next;
}Node;
Node* newNode(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void insert(Node** head, int val1, int val2){
    while(val2--){
        Node *tmp = (*head)->next;
        (*head)->next = newNode(val1);
        (*head)->next->next = tmp;
    }
}
void erase(Node** head, int val1){
    while((val1--) && (*head)->next!=NULL){
        Node *tmp = (*head)->next;
        (*head)->next = (*head)->next->next;
        free(tmp);
    }
}
void move(Node** head, int val1){
    Node *ptr = *head;
    int len = 1;
    while(ptr->next != NULL){
        ptr = ptr->next;
        len++;
    }
    while(val1 <= 0) val1 += 10000*len;
    val1 %= len;
    ptr->next = *head;
    while(val1--) ptr = ptr->next;
    *head = ptr->next;
    ptr->next = NULL;
}
void show(Node** head){
    Node *ptr = *head;
    while(ptr->next != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}
int main(void){
    int a, n, val1, val2;
    char s[10];
    scanf("%d", &a);
    Node *head = newNode(a);
    scanf("%d", &n);
    while(n--){
        scanf("%s", s);
        if(!strcmp(s, "insert")){
            scanf("%d %d", &val1, &val2);
            insert(&head, val1, val2);
        }
        else if(!strcmp(s, "erase")){
            scanf("%d", &val1);
            erase(&head, val1);
        }
        else if(!strcmp(s, "move")){
            scanf("%d", &val1);
            move(&head, val1);
        }
        else if(!strcmp(s, "show")){
            show(&head);
        }
    }
    return 0;
}