#include<stdio.h>
int len(int num){
    int idx = 0;
    int tmp = num+1;
    while(num != 0){
        num /= 10;
        tmp /= 10;
        idx++;
    }
    if(tmp != 0) idx++;
    return idx;
}
int main(void){
    int t, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        printf("%lld\n", (long long)a*(len(b)-1));
    }
    return 0;
}