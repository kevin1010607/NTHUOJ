#include<stdio.h>
#define mod 1000000007
typedef struct{
    long long a[2][2];
}Mtx;
Mtx Mul(Mtx m1, Mtx m2){
    Mtx m;
    m.a[0][0] = ((m1.a[0][0]*m2.a[0][0])%mod+(m1.a[0][1]*m2.a[1][0])%mod)%mod;
    m.a[0][1] = ((m1.a[0][0]*m2.a[0][1])%mod+(m1.a[0][1]*m2.a[1][1])%mod)%mod;
    m.a[1][0] = ((m1.a[1][0]*m2.a[0][0])%mod+(m1.a[1][1]*m2.a[1][0])%mod)%mod;
    m.a[1][1] = ((m1.a[1][0]*m2.a[0][1])%mod+(m1.a[1][1]*m2.a[1][1])%mod)%mod;
    return m;
}
Mtx Power(long long n){
    Mtx m, unit, sqr;
    unit.a[0][0] = unit.a[0][1] = unit.a[1][0] = 1, unit.a[1][1] = 0;
    if(n == 1) return unit;
    sqr = Power(n/2);
    if(n%2 == 0) m = Mul(sqr, sqr);
    else {Mtx tmp = Mul(sqr, sqr); m = Mul(unit, tmp);}
    return m;
}
long long F(long long n){
    if(n==1 || n==2) return 1;
    Mtx m = Power(n-2);
    return (m.a[0][0]+m.a[0][1])%mod;
}
int main(void){
    long long n;
    while(~scanf("%lld", &n))
        printf("%lld\n", F(n));
    return 0;
}