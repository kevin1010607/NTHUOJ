#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum{CommandMode, InsertMode}Mode;
typedef enum{Null, Num}Work;
typedef struct _node{
    char ch;
    struct _node *prev;
    struct _node *next;
}Node;
Node *newNode(char);
void Insert(Node**, Node**, char);
void Delete(Node**);
void FreeList(Node*);
void PrintList(Node*, Node*);
char s[300];
Mode mode;
Work work;
int main(void){
    while(~scanf("%s", s)){
        mode = CommandMode;
        work = Null;
        Node *head = newNode('\0');
        Node *tail = newNode('\0');
        head->next = tail, tail->prev = head;
        Node *cursor = tail;
        int len = strlen(s);
        for(int i = 0; i < len; i++){
            if(mode == CommandMode){
                if(work == Null){
                    if(s[i] == 'h'){
                        if(cursor->prev != head)
                            cursor = cursor->prev;
                    }
                    else if(s[i] == 'l'){
                        if(cursor!=tail &&cursor->next!=tail)
                            cursor = cursor->next;
                    }
                    else if(s[i] == 'x'){
                        if(cursor != tail){
                            Node *newcursor;
                            newcursor = cursor->next;
                            Delete(&cursor);
                            cursor = newcursor;
                            if(cursor==tail&&cursor->prev!=head) 
                                cursor = cursor->prev;
                        }
                    }
                    else if(s[i] == 'a'){
                        mode = InsertMode;
                        if(cursor != tail)
                            cursor = cursor->next;
                    }
                    else if(s[i] == 'A'){
                        mode = InsertMode;
                        cursor = tail;
                    }
                    else if(s[i] == 'i'){
                        mode = InsertMode;
                    }
                    else if(s[i] == 'I'){
                        mode = InsertMode;
                        cursor = head->next;
                    }
                    else if(s[i]>='0'&&s[i]<='9'){
                        int num = s[i]-'0';
                        i++;
                        while(s[i]>='0'&&s[i]<='9'){
                            num = 10*num+s[i]-'0';
                            i++;
                        }
                        if(s[i] == 'h'){
                            while(num--){
                                if(cursor->prev != head)
                                    cursor = cursor->prev;
                                else break;
                            }
                        }
                        else if(s[i] == 'l'){
                            while(num--){
                                if(cursor!=tail&&cursor->next!=tail)
                                    cursor = cursor->next;
                                else break;
                            }
                        }
                        else if(s[i] == 'x'){
                            while(num--){
                                if(cursor != tail){
                                    Node *newcursor = cursor->next;
                                    Delete(&cursor);
                                    cursor = newcursor;
                                }
                                else{
                                    if(cursor->prev != head)
                                        cursor = cursor->prev;
                                    break;
                                }
                            }
                        }
                    }
                    else if(!strncmp(s+i, ":wq", 3)){
                        i += 2;
                        break;
                    }
                }
            }
            else if(mode == InsertMode){
                if(!strncmp(s+i, "ESC", 3)){
                    mode = CommandMode;
                    work = Null;
                    i += 2;
                    if(cursor->prev != head)
                        cursor = cursor->prev;
                }
                else{
                    Insert(&(cursor->prev), &cursor, s[i]);
                }
            }
        }
        PrintList(head, tail);
        //printf("%c\n", cursor->ch);
        FreeList(head);
    }
    return 0;
}
Node *newNode(char ch){
    Node *node = (Node*)malloc(sizeof(Node));
    node->ch = ch;
    node->prev = node->next = NULL;
    return node;
}
void Insert(Node **prev, Node **next, char ch){
    Node *node = newNode(ch);
    node->prev = *prev;
    node->next = *next;
    (*prev)->next = node;
    (*next)->prev = node;
}
void Delete(Node **node){
    Node *ptr = *node;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
}
void FreeList(Node *head){
    while(head->next != NULL){
        head = head->next;
        free(head->prev);
    }
    free(head);
}
void PrintList(Node *head, Node *tail){
    Node *ptr = head->next;
    while(ptr != tail){
        putchar(ptr->ch);
        ptr = ptr->next;
    }
    puts("");
}
