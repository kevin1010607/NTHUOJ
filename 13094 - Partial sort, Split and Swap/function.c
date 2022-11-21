#include"function.h"
#include<stdlib.h>
Node *newNode(int val){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = val;
    tmp->next = NULL;
    return tmp;
}
Node* Partial_sort(Node* head, int a){
    Node *tmp = head;
    Node *front = newNode(-1);
    Node *back = newNode(-1);
    Node *fptr = front, *bptr = back;
    while(head != NULL){
        if(head->data < a){
            fptr->next = newNode(head->data);
            fptr = fptr->next;
        }
        else{
            bptr->next = newNode(head->data);
            bptr = bptr->next;
        }
        head = head->next;
    }
    while(tmp != NULL){
        Node *now = tmp;
        tmp = tmp->next;
        free(now);
    }
    fptr->next = back->next;
    tmp = front->next;
    free(front);
    free(back);
    return tmp;
}

Node* Split_and_Swap(Node* head, int a, int b){
    Node *ptrA = NULL, *ptrB = NULL;
    Node *now = head;
    for(int i = 0; now->next != NULL; i++, now = now->next){
        if(i == a) ptrA = now;
        if(i == b-1) ptrB = now;
    }
    if(ptrA == ptrB){
        now->next = head;
        now = ptrA->next;
        ptrA->next = NULL;
    }
    else{
        now->next = ptrA->next;
        now = ptrB->next;
        ptrB->next = head;
        ptrA->next = NULL;
    }
    return now;
}