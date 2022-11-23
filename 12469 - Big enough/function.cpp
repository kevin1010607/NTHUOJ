#include "function.h"
#include <cstring>
istream& operator>>(istream& in, BigInt& b){
    b.sign = 1;
    string s; in >> s;
    int start = 0, size = s.size();
    if(s[0] == '-') start = 1, size--, b.sign = -1;
    b.l = (size+4)/5;
    memset(b.m, 0, sizeof(b.m));
    for(int i = b.l-1; i >= 0; i--){
        int t = (i==b.l-1)?((size+4)%5+1):5;
        while(t--) b[i] = 10*b[i]+s[start++]-'0';
    }
    return in;
}
ostream& operator<<(ostream& out, BigInt b){
    if(b.sign == -1) out << '-';
    out << b[b.l-1];
    for(int i = b.l-2; i >= 0; i--){
        out.width(5);
        out.fill('0');
        out << b[i];
    }
    return out;
}
BigInt BigInt::operator+(const BigInt& y){
    BigInt res;
    long long sum = 0, idx = 0;
    while(idx<this->l || idx<y.l || sum){
        sum += ((*this)[idx]*this->sign+y[idx]*y.sign);
        res[idx++] = sum%100000;
        sum /= 100000;
    }
    idx--;
    while(idx>0 && res[idx]==0) idx--;
    res.sign = res[idx]<0?-1:1;
    if(res.sign == -1) for(int i = 0; i <= idx; i++) res[i] = -res[i];
    for(int i = 0; i < idx; i++)
        if(res[i] < 0) res[i] += 100000, res[i+1]--;
    while(idx>0 && res[idx]==0) idx--;
    res.l = idx+1;
    return res;
}
BigInt BigInt::operator-(const BigInt& y){
    BigInt t(y);
    t.sign = -t.sign;
    return *this+t;
}