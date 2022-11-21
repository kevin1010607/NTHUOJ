#include<stdio.h>
#define maxn 105
int main(void){
    int N;
    scanf("%d", &N);
    int prime_val[maxn];
    prime_val[0] = 2;
    int prime_num = 1;

    for(int i = 3; i <= N; i++){
        int prime_flag = 1;
        for(int j = 2; j < i; j++){
            if(i%j == 0){
                prime_flag = 0;
                break;
            }
        }
        if(prime_flag)
            prime_val[prime_num++] = i;
    }

    int prime_cnt[maxn] = {};
    for(int i = 0; i < prime_num; i++){
        int t = prime_val[i];
        int ans = 0;
        while(t <= N){
            ans += N/t;
            t *= prime_val[i];
        }
        prime_cnt[i] = ans;
    }

    unsigned long long factor = 1;
    for(int i = 0; i < prime_num; i++){
        factor *= (prime_cnt[i]+1);
    }
    printf("%llu", factor);
    return 0;
}

