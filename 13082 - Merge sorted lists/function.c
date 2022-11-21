#include<stdlib.h>
#include "function.h"
int compare(const void *a, const void *b){
    const int *ia = (const int*)a;
    const int *ib = (const int*)b;
    return (*ia>*ib)-(*ia<*ib);
}
Node* Merge_lists(Node* list1, Node* list2){
    int arr[25], idx = 0;
    while(list1 != NULL){
        arr[idx++] = list1->data;
        Node *tmp = list1;
        list1 = list1->next;
        free(tmp);
    }
    while(list2 != NULL){
        arr[idx++] = list2->data;
        Node *tmp = list2;
        list2 = list2->next;
        free(tmp);
    }
    qsort(arr, idx, sizeof(int), compare);
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = arr[0];
    Node *now = head;
    for(int i = 1; i < idx; i++){
        if(arr[i] == now->data) continue;
        now->next = (Node*)malloc(sizeof(Node));
        now->next->data = arr[i];
        now = now->next;
    }
    now->next = NULL;
    return head;
}