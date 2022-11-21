#include "function.h"
Node *newNode(int val){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = val;
    tmp->next = NULL;
    return tmp;
}
void deleteNode(Node ** nd, int data){
    if(data == 1){
        Node *tmp = (*nd)->next;
        free(*nd);
        *nd = tmp;
    }
    else{
        Node *now = *nd;
        Node *target = NULL;
        for(int i = 1; now != NULL; i++){
            if(i == data-1){
                target = now;
                break;
            }
            now = now->next;
        }
        if(target==NULL||target->next==NULL) return;
        now = target->next;
        target->next = target->next->next;
        free(now);
    }
}
Node* createList(){
    Node *head = newNode(-1);
    Node *now = head;
    int val;
    while(1){
        scanf("%d", &val);
        if(val > -1){
            now->next = newNode(val);
            now = now->next;
        }
        else break;
    }
    now = head->next;
    free(head);
    return now;
}