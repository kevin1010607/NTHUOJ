#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int val;
    struct _node*next[4];
    int dyna[4];
}Node;
Node *newNode(int val){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->val = val;
    tmp->next[0] = tmp->next[1] = tmp->next[2] = tmp->next[3] = NULL;
    tmp->dyna[0] = tmp->dyna[1] = tmp->dyna[2] = tmp->dyna[3] = 0;
    return tmp;
}
void delete_node(Node *now){
    for(int i = 0; i < 4; i++)
        if(now->dyna[i]) delete_node(now->next[i]);
    free(now);
}
int main(void){
    int q;
    scanf("%d", &q);
    Node *head = newNode(0);
    Node *now = head;
    while(q--){
        int type, dir, val;
        scanf("%d", &type);
        switch(type){
            case 1:
                scanf("%d %d", &dir, &val);
                if(now->next[dir] != NULL){
                    printf("Invalid\n");
                    break;
                }
                now->next[dir] = newNode(val);
                now->dyna[dir] = 1;
                now->next[dir]->next[(dir+2)%4] = now;
                break;
            case 2:
                scanf("%d", &dir);
                if(now->next[dir] == NULL){
                    printf("Invalid\n");
                    break;
                }
                now = now->next[dir];
                break;
            case 3:
                scanf("%d", &val);
                now->val = val;
                break;
            case 4:
                printf("%d\n", now->val);
                break;
        }
    }
    delete_node(head);
    return 0;
}