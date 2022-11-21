#include<stdio.h>
long long FastPower(long long x, long long y, long long m){
    if(y == 0) return 1%m;
    if(y == 1) return x%m;
    long long product = FastPower(x, y/2, m);
    product = (product*product)%m;
    if(y%2 == 0) return product;
    else return (x%m*product)%m;
}
int main(void){
    long long x, y, m;
    scanf("%lld %lld %lld", &x, &y, &m);
    printf("%lld\n", FastPower(x, y, m));
    return 0;
}