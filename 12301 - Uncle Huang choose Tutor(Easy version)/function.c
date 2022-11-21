#include "function.h"
void insertNext(Node *p, int num){
    Node *q = (Node*)malloc(sizeof(Node));
    q->number = num;
    q->next = p->next;
    p->next = q;
}
void deleteNext(Node *p){
    Node *q = p->next;
    p->next = q->next;
    free(q);
}
Node *createList(int n){
    Node *last = (Node*)malloc(sizeof(Node));
    last->number = n;
    last->next = last;
    for(int i = n-1; i >= 1; i--)
        insertNext(last, i);
    return last->next;
}
void freeList(Node* head){
    free(head);
}
int solveJosephus(Node **head, int step){
    Node *ptr = *head;
    int len = 1;
    while(ptr->next != *head){
        ptr = ptr->next;
        len++;
    }
    while(ptr->next != ptr){
        int move = (step-1)%len;
        while(move--) ptr = ptr->next;
        deleteNext(ptr);
        len--;
    }
    *head = ptr;
    return ptr->number;
}