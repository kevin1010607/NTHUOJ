#include<stdlib.h>
#include "function.h"

Node* createList(int *a, int size){
    Node *head = (Node*)malloc(sizeof(Node));
    Node *now = head;
    for(int i = 0; i < size; i++){
        now->data = a[i];
        if(i != size-1){
            now->next = (Node*)malloc(sizeof(Node));
            now = now->next;
        }
    }
    now->next = NULL;
    return head;
}
void push_front(Node** head, int val){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = val;
    tmp->next = *head;
    *head = tmp;
}
void deleteElementByIdx(Node** head, int idx){
    if(idx == 0){
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    else{
        Node *task = *head;
        Node *pre = NULL;
        while(idx--){
            pre = task;
            task = task->next;
            if(task == NULL) break;
        }
        if(idx == -1){
            pre->next = task->next;
            free(task);
        }
    }
}
Node* copyList(Node* head){
    Node *new_head = (Node*)malloc(sizeof(Node));
    Node *now = new_head;
    while(head->next != NULL){
        now->data = head->data;
        now->next = (Node*)malloc(sizeof(Node));
        now = now->next;
        head = head->next;
    }
    now->data = head->data;
    now->next = NULL;
    return new_head;
}
void SwapElementByIdx(Node** head, int idx1, int idx2){
    if(idx1 > idx2){
        int tmp = idx1;
        idx1 = idx2;
        idx2 = tmp;
    }
    Node *task1 = *head;
    while(idx1--){
        task1 = task1->next;
        if(task1 == NULL) break;
        idx2--;
    }
    if(idx1 == -1){
        Node *task2 = task1;
        while(idx2--){
            task2 = task2->next;
            if(task2 == NULL) break;
        }
        if(idx2 == -1){
            int tmp = task1->data;
            task1->data = task2->data;
            task2->data = tmp;
        }
    }
}