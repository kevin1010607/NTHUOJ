#include "function.h"
Node *newNode(char* color){
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node->color, color);
    node->next = NULL;
    return node;
}
void insert(Node** head, char* color, int idx){
    Node **pp = &((*head)->next);
    Node *ptr = (*head)->next;
    for(int i = 0; ; i++){
        if(i==idx || ptr==NULL){
            *pp = newNode(color);
            (*pp)->next = ptr;
            break;
        }
        pp = &(ptr->next);
        ptr = ptr->next;
    }
}
void erase1(Node** head, int idx){
    Node **pp = &((*head)->next);
    Node *ptr = (*head)->next;
    for(int i = 1; ptr != NULL; i++){
        if(i==idx || ptr->next==NULL){
            *pp = ptr->next;
            free(ptr);
            break;
        }
        pp = &(ptr->next);
        ptr = ptr->next;
    }
}
void erase2(Node** head, char* color){
    Node **pp = &((*head)->next);
    Node *ptr = (*head)->next;
    while(ptr != NULL){
        if(!strcmp(ptr->color, color)){
            *pp = ptr->next;
            free(ptr);
            ptr = *pp;
        }
        else{
            pp = &(ptr->next);
            ptr = ptr->next;
        }
    }
}
void reverse(Node** head, int idx1, int idx2){
    Node *pre = *head;
    for(int i = 0; ; i++){
        if(pre->next == NULL) return;
        if(i == idx1-1) break;
        pre = pre->next;
    }
    Node *ptr = pre->next->next, *p1 = pre->next;
    for(int i = idx1+1; i<=idx2 && ptr!=NULL; i++){
        Node *tmp = pre->next;
        pre->next = ptr;
        p1->next = ptr->next;
        ptr->next = tmp;
        ptr = p1->next;
    }
}
