#include"function.h"

Complex CreateComplex(long long real, long long imag){
    Complex comp;
    comp.real = real;
    comp.imag = imag;
    return comp;
}
Complex Add(Complex comp1, Complex comp2){
    long long real = comp1.real+comp2.real;
    long long imag = comp1.imag+comp2.imag;
    return CreateComplex(real, imag);
}
Complex Sub(Complex comp1, Complex comp2){
    long long real = comp1.real-comp2.real;
    long long imag = comp1.imag-comp2.imag;
    return CreateComplex(real, imag);
}
Complex Mul(Complex comp1, Complex comp2){
    long long real = comp1.real*comp2.real-comp1.imag*comp2.imag;
    long long imag = comp1.real*comp2.imag+comp1.imag*comp2.real;
    return CreateComplex(real, imag);
}
void Compare(Complex* comp1, Complex* comp2){
    long long val1 = comp1->real*comp1->real+comp1->imag*comp1->imag;
    long long val2 = comp2->real*comp2->real+comp2->imag*comp2->imag;
    if(val1 < val2){
        Complex tmp = *comp1;
        *comp1 = *comp2;
        *comp2 = tmp;
    }
}