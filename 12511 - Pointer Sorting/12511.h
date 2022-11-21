#include<math.h>
#include<stdlib.h>
void bubble_sort(int *a, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int** s(int* a,int len){
    bubble_sort(a, len);
    int l = (int)sqrt(len);
    int **arr = (int**)malloc(l*sizeof(int*)+len*sizeof(int));
    for(int i = 0; i < l; i++)
        arr[i] = &a[l*i];
    return arr;
}
