#include<stdio.h>
#include<stdlib.h>
int up(int *s, int x, int n){
    int l = 0, r = n;
    while(l < r){
        int mid = (l+r)/2;
        if(x < s[mid]) r = mid;
        else l = mid+1;
    }
    return l;
}
int low(int *s, int x, int n){
    int l = 0, r = n;
    while(l < r){
        int mid = (l+r)/2;
        if(x <= s[mid]) r = mid;
        else l = mid+1;
    }
    return l;
}
int cmp(const void *a, const void *b){
    return *(const int*)a-*(const int*)b;
}
int n, s[100005], q, x;
int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", s+i);
    qsort(s, n, sizeof(int), cmp);
    scanf("%d", &q);
    while(q--){
        scanf("%d", &x);
        printf("%d\n", up(s, x, n)-low(s, x, n));
    }
    return 0;
}