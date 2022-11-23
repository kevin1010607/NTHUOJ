#include "function.h"

void DynamicallySetArraySize(int **ary, int size){
    // TODO
	*ary = (int*)malloc(size*sizeof(int));
	for(int i = 0; i < size; i++) scanf("%d", (*ary)+i);
}

void PrintArray(int *ary, int size){
    // TODO
	for(int i = 0; i < size; i++)
        printf("%d%c", ary[i], " \n"[i==size-1]);
}