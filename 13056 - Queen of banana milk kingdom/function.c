#include<string.h>
#include<stdlib.h>
#include"function.h"
Monkey* CreateMonkeyArray(int n){
    Monkey *arr;
    arr = (Monkey*)malloc(n*sizeof(Monkey));
    return arr;
}
void FreeMonkeyArray(Monkey* mon, int n){
    for(int i = 0; i < n; i++)
        free(mon[i].name);
    free(mon);
}
void SetVal(Monkey* mon, int id, int num, char name[]){
    mon[id].num = num;
    mon[id].name = (char*)malloc((strlen(name)+1)*sizeof(char));
    strcpy(mon[id].name, name);
}
int Compare(Monkey* mon, int id1, int id2){
    if(mon[id1].num > mon[id2].num) return 0;
    if(mon[id1].num < mon[id2].num) return 1;
    return strcmp(mon[id2].name, mon[id1].name);
}
void Swap(Monkey* mon, int id1, int id2){
    Monkey tmp = mon[id1];
    mon[id1] = mon[id2];
    mon[id2] = tmp;
}