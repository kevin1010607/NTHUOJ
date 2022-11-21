#include<stdio.h>
#include<stdlib.h>
int n;
int a[100005];
int cmp(const void *a, const void *b){
    const int *ia = (const int*)a;
    const int *ib = (const int*)b;
    return (*ia>*ib)-(*ia<*ib);
}
int upper(int num){
    int l = 0, r = n, mid;
    while(l < r){
        mid = (l+r)/2;
        if(num < a[mid]) r = mid;
        else l = mid+1;
    }
    return r;
}
int lower(int num){
    int l = 0, r = n, mid;
    while(l < r){
        mid = (l+r)/2;
        if(num <= a[mid]) r = mid;
        else l = mid+1;
    }
    return r;
}
int main(void){
    int q, num;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    scanf("%d", &q);
    while(q--){
        scanf("%d", &num);
        printf("%d\n", upper(num)-lower(num));
    }
    return 0;
}