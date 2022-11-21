#include "function.h"
long long GCD(long long a, long long b){
    while(a && b){
        if(a > b) a %= b;
        else b %= a;
    }
    return (a>b?a:b);
}
Fraction CreateFrac(long long numer, long long denom){
    Fraction frac;
    frac.numerator = numer;
    frac.denominator = denom;
    return frac;
}
void Reduction(Fraction* frac){
    long long gcd = GCD(frac->numerator, frac->denominator);
    frac->numerator /= gcd;
    frac->denominator /= gcd;
}
Fraction Add(Fraction frac1, Fraction frac2){
    long long numer = frac1.numerator*frac2.denominator+frac1.denominator*frac2.numerator;
    long long denom = frac1.denominator*frac2.denominator;
    long long gcd = GCD(numer, denom);
    return CreateFrac(numer/gcd, denom/gcd);
}
Fraction Sub(Fraction frac1, Fraction frac2){
    long long numer = frac1.numerator*frac2.denominator-frac1.denominator*frac2.numerator;
    long long denom = frac1.denominator*frac2.denominator;
    long long gcd = GCD(numer, denom);
    return CreateFrac(numer/gcd, denom/gcd);
}
Fraction Mul(Fraction frac1, Fraction frac2){
    long long numer = frac1.numerator*frac2.numerator;
    long long denom = frac1.denominator*frac2.denominator;
    long long gcd = GCD(numer, denom);
    return CreateFrac(numer/gcd, denom/gcd);
}
Fraction Div(Fraction frac1, Fraction frac2){
    long long numer = frac1.numerator*frac2.denominator;
    long long denom = frac1.denominator*frac2.numerator;
    long long gcd = GCD(numer, denom);
    return CreateFrac(numer/gcd, denom/gcd);
}
int Compare(Fraction frac1, Fraction frac2){
    return frac1.numerator*frac2.denominator > frac1.denominator*frac2.numerator;
}