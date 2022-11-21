#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b){
    const int *ia = (const int*)a;
    const int *ib = (const int*)b;
    return (*ia>*ib)-(*ia<*ib);
}
int main(void){
    int n, s[100005];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    qsort(s, n, sizeof(int), compare);
    int q, num;
    scanf("%d", &q);
    int idx = n-1;
    while(q--){
        scanf("%d", &num);
        while(s[idx] > num) idx--;
        printf("%d\n", idx+1);
    }
    return 0;
}