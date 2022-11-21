#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
int main(void){
    int q;
    scanf("%d", &q);
    while(q--){
        long long n;
        scanf("%lld", &n);
        int idx = 0;
        int *binary = (int*)calloc(64, sizeof(int));
        while(n != 0){
            binary[idx++] = n%2;
            n /= 2;
        }
        int ans = -1;
        int flag = 1, tmp = 0;
        for(int i = 0; i < idx; i++){
            if(binary[i] == 1){
                if(flag) flag = 0;
                else{
                    ans = max(tmp, ans);
                    tmp = 0;
                }
            }
            else{
                if(!flag) tmp++;
            }
        }
        printf("%d\n", ans);
        free(binary);
    }
}