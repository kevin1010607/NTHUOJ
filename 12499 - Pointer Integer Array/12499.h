#include<stdlib.h>
int** malloc_ptr(int array_size){
    int **arr;
    arr = (int**)malloc(array_size*sizeof(int*));
    return arr;
}
void malloc_array(int **array, int array_size){
    *array = (int*)malloc(array_size*sizeof(int));
}
void pointer_ptr_to_array(int *array, int **ptr,int N){
    for(int i = 0; i < N; i++)
        ptr[i] = &array[i*(i+1)/2];
}