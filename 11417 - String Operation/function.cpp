#include"function.h"

Str::Str(char *c){
    head = tail = new Char(*c);
    for(int i = 1; c[i]!='\0'; i++){
        tail = tail->next = new Char(c[i]);
    }
}
Str::Str(const Str &s){
    head = tail = new Char(s.head->text);
    Char *tmp = s.head->next;
    while(tmp){
        tail = tail->next = new Char(tmp->text);
        tmp = tmp->next;
    }
}
Str& Str::strInsert(const Str &s){
    Str *tmp = new Str(s);
    tail->next = tmp->head;
    tail = tmp->tail;
    return *this;
}