#include "function.h"

#define ll long long int

int main(){
    int n, k;
    while( scanf("%d%d", &n, &k)!=EOF ){
        Node *head;
        head = createList(n);
        printf( "%d\n", solveJosephus(&head, k) );
        freeList(head);
    }
    return 0;
}