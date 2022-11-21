#include<stdio.h>
#include<stdlib.h>
#include "function.h"
#define swap(a, b) {int tmp = *a; *a = *b; *b = tmp;}
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
void swapTwoSegment(Node **head, int a, int b, int len){
    if(a > b) swap(&a, &b);
    Node *old_head = *head;
    Node *now = *head;
    Node *startA = NULL, *endA = NULL;
    Node *startB = NULL, *endB = NULL;
    Node *startSeg1 = NULL, *endSeg1 = NULL;
    Node *startSeg2 = NULL, *endSeg2 = NULL;
    int Seg1 = 0, Seg2 = 0;
    int i = 1, idxA = 1, idxB = 1;
    int head_position = 0, in = -1;// 0 in A, 1 in B;
    while(i < a){
        now = now->next;
        i++;
    }
    startA = now;
    while(idxA < len){
        if(now == old_head) {head_position = idxA; in = 0;}
        now = now->next;
        idxA++;
        i++;
    }
    endA = now;
    if(endA == old_head) {head_position = idxA; in = 0;}
    now = now->next;
    i++;
    if(i != b){
        Seg1 = 1;
        startSeg1 = now;
        while(i < b-1){
            now = now->next;
            i++;
        }
        endSeg1 = now;
        now = now->next;
        i++;
    }
    startB = now;
    while(idxB < len){
        if(now == old_head) {head_position = idxB; in = 1;}
        now = now->next;
        idxB++;
        i++;
    }
    endB = now;
    if(endB == old_head) {head_position = idxB; in = 1;}
    now = now->next;
    if(now != startA){
        Seg2 = 1;
        startSeg2 = now;
        while(now->next != startA){
            now = now->next;
        }
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
    if(head_position!=0 && in!=-1){
        if(in == 0){
            now = startB;
            for(int i = 1; i < head_position; i++)
                now = now->next;
        }
        else if(in == 1){
            now = startA;
            for(int i = 1; i < head_position; i++)
                now = now->next;
        }
        *head = now;
    }
}