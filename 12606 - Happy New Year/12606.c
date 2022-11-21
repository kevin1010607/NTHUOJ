#include<stdio.h>
int main(void){
    int n, x, tmp;
    int M = -1, m = 1500000000;
    scanf("%d", &n);
    scanf("%d", &x);
    while(n--){
        scanf("%d", &tmp);
        if(tmp > M) M = tmp;
        if(tmp < m) m = tmp;
    }
    if(x>=m && x<=M){
        printf("%d\n", 2*(M-m));
    }
    else{
        if(M > x) printf("%d\n", 2*(M-x));
        else printf("%d\n", 2*(x-m));
    }
    return 0;
}