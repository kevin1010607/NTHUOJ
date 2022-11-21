#include<stdio.h>
#define mod 1000000007
typedef struct{
    long long a[3][3];
}Mtx;
Mtx Mul(Mtx m1, Mtx m2){
    Mtx m;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            m.a[i][j] = 0;
            for(int k = 0; k < 3; k++){
                m.a[i][j] = (m.a[i][j]+(m1.a[i][k]*m2.a[k][j])%mod)%mod;
            }
        }
    }
    return m;
}
Mtx Power(long long n){
    Mtx unit, m, sqr;
    unit.a[0][0] = unit.a[0][2] = unit.a[1][0] = unit.a[2][1] = 1;
    unit.a[1][1] = unit.a[1][2] = unit.a[2][0] = unit.a[2][2] = 0;
    unit.a[0][1] = 2;
    if(n == 1) return unit;
    sqr = Power(n/2);
    m = Mul(sqr, sqr);
    if(n%2 == 0) return m;
    else return Mul(unit, m);
}
long long P(long long n){
    if(n == 1) return 1;
    if(n == 2) return 12;
    if(n == 3) return 13;
    Mtx m = Power(n-3);
    return (13*m.a[0][0]+12*m.a[0][1]+m.a[0][2])%mod;
}
int main(void){
    int t;
    long long n;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        printf("%lld\n", P(n));
    }
    return 0;
}