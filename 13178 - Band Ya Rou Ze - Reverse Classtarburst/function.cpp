#include<iostream>
#include"function.h"
Node::~Node(){
    Node *tmp = neighbors[(neighbors[0]==nullptr?1:0)];
    if(tmp){
        tmp->unLink(this);
        delete tmp;
    }
}
void List::init(std::string s){
    if(s == "") head = tail = nullptr;
    else{
        head = tail = new Node(s[0]);
        for(int i = 1; i < s.size(); i++){
            Node *tmp = new Node(s[i]);
            tmp->link(tail), tail->link(tmp), tail = tmp;
        }
    }
}
void List::merge(List &front, List &back){
    if(front.tail == nullptr) head = back.head, tail = back.tail;
    else if(back.tail == nullptr) head = front.head, tail = front.tail;
    else{
        front.tail->link(back.head), back.head->link(front.tail);
        head = front.head, tail = back.tail;
    }
}
void List::swap(List &swapList){
    std::swap(head, swapList.head);
    std::swap(tail, swapList.tail);
}
void List::reverse(){
    std::swap(head, tail);
}
List::~List(){
    delete head;
}