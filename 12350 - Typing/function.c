#include "function.h"
#define next ptr_to_next_node
#define prev ptr_to_prev_node
#define ch character
Node *head, *tail;
Node *newNode(char intype, Node *prev, Node *next){
    Node *node = (Node*)malloc(sizeof(Node));
    node->ch = intype;
    node->next = next;
    node->prev = prev;
    return node;
}
void insert(Node** cursor, char intype){
    Node *tmp = (*cursor)->next;
    (*cursor)->next = newNode(intype, *cursor, tmp);
    tmp->prev = (*cursor)->next;
}
void deletion(Node** cursor){
    if((*cursor)->next == tail) return;
    Node *tmp = (*cursor)->next;
    (*cursor)->next = (*cursor)->next->next;
    (*cursor)->next->prev = *cursor;
    free(tmp);
}
void backspace(Node** cursor){
    if((*cursor) == head) return;
    Node *tmp = *cursor;
    (*cursor)->prev->next = (*cursor)->next;
    (*cursor)->next->prev = (*cursor)->prev;
    *cursor = (*cursor)->prev;
    free(tmp);
}
void go_left(Node** cursor, int num){
    while(num--) (*cursor) = (*cursor)->prev;
}
void go_right(Node** cursor, int num){
    while(num--) (*cursor) = (*cursor)->next;
}
void go_home(Node** cursor){
    *cursor = head;
}
void go_end(Node** cursor){
    *cursor = head->prev;
}