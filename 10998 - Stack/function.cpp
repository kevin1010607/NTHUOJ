#include "function.h"
List_stack::List_stack():head(NULL),tail(NULL){}
List_stack::~List_stack(){
    ListNode *tmp = tail;
    while(tmp){
        ListNode *now = tmp;
        tmp = tmp->prevPtr;
        delete now;
    }
}
void List_stack::push(const int& n){
    ListNode *tmp = new ListNode(n);
    tmp->prevPtr = tail;
    tail = tmp;
}
void List_stack::pop(){
    if(tail == NULL) return;
    ListNode *tmp = tail;
    tail = tail->prevPtr;
    delete tmp;
}
void List_stack::print(){
    ListNode *tmp = tail;
    while(tmp){
        std::cout << tmp->data << (tmp->prevPtr?" ":"");
        tmp = tmp->prevPtr;
    }
}