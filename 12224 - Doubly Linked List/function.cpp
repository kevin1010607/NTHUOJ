#include"function.h"
void List::InsertHead(int data){
    if(head){
        head->prev = new ListNode(data);
        head->prev->next = head;
        head = head->prev;
        if(cnt%2 == 0) middle = middle->prev;
    }
    else head = tail = middle = new ListNode(data);
    cnt++;
}
int List::RemoveHead(){
    if(head){
        ListNode *tmp = head;
        int num = head->data;
        if(cnt%2==1 && cnt>1) middle = middle->next;
        head = head->next;
        if(head) head->prev = nullptr;
        else tail = nullptr;
        cnt--;
        delete tmp;
        return num;
    }
    else throw std::out_of_range("\n");
}
void List::InsertTail(int data){
    if(tail){
        tail->next = new ListNode(data);
        tail->next->prev = tail;
        tail = tail->next;
        if(cnt%2 == 1) middle = middle->next;
    }
    else head = tail = middle = new ListNode(data);
    cnt++;
}
int List::RemoveTail(){
    if(tail){
        ListNode *tmp = tail;
        int num = tail->data;
        if(cnt%2 == 0) middle = middle->prev;
        tail = tail->prev;
        if(tail) tail->next = nullptr;
        else head = nullptr;
        cnt--;
        delete tmp;
        return num;
    }
    else throw std::out_of_range("\n");
}
void List::Swap(){
    if(cnt < 2) return;
    head->prev = tail;
    tail->next = head;
    tail = middle->prev;
    std::swap(head, middle);
    if(cnt%2 == 1) middle = middle->prev;
    head->prev = tail->next = nullptr;
}