#include<stdio.h>
#include<stdlib.h>
#include "function.h"
#define swap(a,b) {int tmp=*a;*a=*b;*b=tmp;}
Node *newNode(int val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}
void createLinkedList(Node **head, int N, int *arr){
    *head = newNode(arr[1]);
    Node *now = *head;
    for(int i = 2; i <= N; i++){
        now->next = newNode(arr[i]);
        now = now->next;
    }
    now->next = *head;
}
void swapTwoSegment(Node **head, int N, int a, int b, int len){
    if(a > b) swap(&a, &b);
    int circle = b+len-1>N;
    if(a+len > b) return;
    if(circle && b+len-N>a) return;
    Node *startA = NULL, *endA = NULL;
    Node *startB = NULL, *endB = NULL;
    Node *startSeg1 = NULL, *endSeg1 = NULL;
    Node *startSeg2 = NULL, *endSeg2 = NULL;
    int Seg1 = 1, Seg2 = 1;
    Node *now = *head;
    int idx = 1;
    for(; ; idx++){
        if(idx == a) {startA = now; break;}
        now = now->next;
    }
    int tmp = len-1;
    while(tmp--){ 
        now = now->next;
        idx++;
    }
    endA = now;
    if(idx+1 == b) Seg1 = 0;
    else{
        startSeg1 = now->next;
        while(idx+1 != b){
            now = now->next;
            idx++;
        }
        endSeg1 = now;
    }
    tmp = len;
    startB = now->next;
    while(tmp--) now = now->next;
    endB = now;
    if(now->next == startA) Seg2 = 0;
    else{
        startSeg2 = now->next;
        while(now->next != startA) now = now->next;
        endSeg2 = now;
    }

    if(Seg1){
        endB->next = startSeg1;
        endSeg1->next = startA;
    }
    else endB->next = startA;
    if(Seg2){
        endA->next = startSeg2;
        endSeg2->next = startB;
    }
    else endA->next = startB;
    while(len--){
        if(startA == *head){
            *head = startB;
            break;
        }
        if(startB == *head){
            *head = startA;
            break;
        }
        startA = startA->next;
        startB = startB->next;
    }
}