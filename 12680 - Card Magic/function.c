#include "function.h"
#include<stdio.h>
#include<stdlib.h>
Node *newNode(int size){
    Node *node = (Node*)malloc(sizeof(Node));
    node->size = size;
    node->data = (int*)malloc(size*sizeof(int));
    node->next = NULL;
    return node;
}
Node* ReadOneList(){
    int size;
    scanf("%d:", &size);
    Node *node = newNode(size);
    for(int i = 0; i < size; i++){
        scanf("%d", &(node->data[i]));
    }
    return node;
}
void PrintList(Node* node){
    while(node->next){
        node = node->next;
        for(int i = 0; i < node->size; i++){
            if(i != node->size-1)
                printf("%d ", node->data[i]);
            else
                printf("%d\n", node->data[i]);
        }
    }
}
void Merge(Node* node, int x, int y){
    Node *nodeX = NULL, *nodeY = NULL;
    for(int i = 0; nodeX==NULL || nodeY==NULL; i++){
        if(i == y) nodeY = node;
        if(i == x-1){
            nodeX = node->next;
            node->next = nodeX->next;
            i++;
        }
        node = node->next;
    }
    int size = nodeX->size+nodeY->size;
    int *data = (int*)malloc(size*sizeof(int));
    int idx = 0;
    for(int i = 0; i < nodeY->size; i++){
        data[idx] = nodeY->data[i];
        idx++;
    }
    for(int i = 0; i < nodeX->size; i++){
        data[idx] = nodeX->data[i];
        idx++;
    }
    free(nodeX->data);
    free(nodeY->data);
    free(nodeX);
    nodeY->size = size;
    nodeY->data = data;
}
void Cut(Node* node, int x, int id){
    for(int i = 0; ; i++){
        if(i == x) break;
        node = node->next;
    }
    int size1 = id, size2 = node->size-id;
    int *data1 = (int*)malloc(size1*sizeof(int));
    int *data2 = (int*)malloc(size2*sizeof(int));
    int idx = 0;
    for(int i = 0; i < size1; i++){
        data1[i] = node->data[idx];
        idx++;
    }
    for(int i = 0; i < size2; i++){
        data2[i] = node->data[idx];
        idx++;
    }
    free(node->data);
    node->size = size1;
    node->data = data1;
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->size = size2;
    new_node->data = data2;
    new_node->next = node->next;
    node->next = new_node;
}