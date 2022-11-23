#include<stdio.h>
int TS(int x, int *arr, int l, int r){
    if(l > r) return 0;
    int mid1 = l+(r-l)/3, mid2 = mid1+(r-l)/3;
    if(x < arr[mid1]) return TS(x, arr, l, mid1-1);
    else if(x > arr[mid2]) return TS(x, arr, mid2+1, r);
    else if(x>arr[mid1] && x<arr[mid2]) return TS(x, arr, mid1+1, mid2-1);
    else return x==arr[mid1]?mid1+1:mid2+1;
}
int n, q, x, v, s[2000005];
int main(void){
    while(~scanf("%d %d", &n, &q)){
        for(int i = 0; i < n; i++) scanf("%d", s+i);
        while(q--){
            scanf("%d", &x);
            v = TS(x, s, 0, n-1);
            if(v) printf("%d\n", v);
            else printf("Break your bridge!\n");
        }
    }
    return 0;
}