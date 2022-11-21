#include"function.h"
#include<stdlib.h>
Node *newNode(int val){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = val;
    tmp->next = NULL;
    return tmp;
}
Node* createList(int *a, int size){
    Node *head = newNode(-1);
    Node *now = head;
    for(int i = 0; i < size; i++){
        now->next = newNode(a[i]);
        now = now->next;
    }
    now = head->next;
    free(head);
    return now;
}
void push_front(Node** head, int val){
    Node *tmp = newNode(val);
    tmp->next = *head;
    *head = tmp;
}
void deleteElementByIdx(Node** head, int idx){
    if(idx == 0){
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return ;
    }
    Node *now = *head;
    for(int i = 1; now->next != NULL; i++){
        if(i == idx) break;
        now = now->next;
    }
    if(now->next == NULL) return;
    if(now->next->next == NULL){
        free(now->next);
        now->next = NULL;
    }
    else{
        Node *tmp = now->next;
        now->next = now->next->next;
        free(tmp);
    }
}
Node* copyList(Node* head){
    Node *newhead = newNode(-1);
    Node *now = newhead;
    while(head != NULL){
        now->next = newNode(head->data);
        now = now->next;
        head = head->next;
    }
    now = newhead->next;
    free(newhead);
    return now;
}
void SwapElementByIdx(Node** head, int idx1, int idx2){
    Node *now = *head;
    Node *A = NULL, *B = NULL;
    for(int i = 0; now != NULL; i++, now = now->next){
        if(i == idx1) A = now;
        if(i == idx2) B = now;
    }
    if(A==NULL || B==NULL) return;
    int tmp = A->data;
    A->data = B->data;
    B->data = tmp;
}
void ReverseList(Node** head){
    Node *now = *head;
    Node *pre = NULL;
    while(now->next != NULL){
        Node *tmp = now->next;
        now->next = pre;
        pre = now;
        now = tmp;
    }
    now->next = pre;
    *head = now;
}
void ShiftListByK(Node** head, int k){
    if(k == 0) return;
    Node *now = *head;
    int len = 1;
    while(now->next != NULL){
        now = now->next;
        len++;
    }
    if(k%len == 0) return;
    k = len-k%len;
    now->next = *head;

    while(k--) now = now->next;
    *head = now->next;
    now->next = NULL;
}