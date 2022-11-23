#include<stdio.h>
#define maxn 90
long long n, d[maxn];
int main(void){
    d[1] = 1;
    for(int i = 2; i < maxn; i++) d[i] = d[i-1]+d[i-2];
    while(~scanf("%lld", &n)){
        for(int i = maxn-2; i >= 0; i--){
            if(n < d[i]) continue;
            if((n-d[i])%d[i+1] == 0){
                printf("%lld\n", (n-d[i])/d[i+1]);
                break;
            }
        }
    }
    return 0;
}
// find the regular pattern
// 0   1   1   2   3   5   8  13  21  34  55 ...
// 1   2   3   5   8  13  21  34  55  89 144 ...
// 2   3   5   8  13  21  34  55  89 144 233 ...
// 3   4   7  11  18  29  47  76 123 199 322 ...
// 4   5   9  14  23  37  60  97 157 254 411 ...
// 5   6  11  17  28  45  73 118 191 309 500 ...
// 6   7  13  20  33  53  86 139 225 364 589 ...