#include"function.h"
#include<string.h>

BigInt::BigInt():sign(true){
    for(int i = 0; i < N; i++) bigInt[i] = 0;
}
BigInt::BigInt(char *s):sign(true){
    for(int i = 0; i < N; i++) bigInt[i] = 0;
    int len = strlen(s);
    for(int i = 0, idx = len-1; idx >= 0; i++, idx-=WIDTH){
        for(int j = WIDTH-1; j >= 0; j--){
            if(idx-j >= 0) bigInt[i] = 10*bigInt[i]+(s[idx-j]-'0');
        }
    }
}
BigInt::BigInt(const BigInt &num){
    *this = num;
}
BigInt& BigInt::operator = (const BigInt &num){
    sign = num.sign;
    for(int i = 0; i < N; i++) bigInt[i] = num.bigInt[i];
    return *this;
}
bool BigInt::operator < (BigInt num){
    if(sign != num.sign) return sign < num.sign;
    for(int i = N-1; i >= 0; i--){
        if(bigInt[i] < num.bigInt[i]) return sign;
        else if(bigInt[i] > num.bigInt[i]) return !sign;
    }
    return false;
}
bool BigInt::operator > (BigInt num){
    return num < *this;
}
bool BigInt::operator == (BigInt num){
    if(sign != num.sign) return false;
    for(int i = 0; i < N; i++){
        if(bigInt[i] != num.bigInt[i]) return false;
    }
    return true;
}
bool BigInt::operator >= (BigInt num){
    return !(*this < num);
}
bool BigInt::operator <= (BigInt num){
    return !(*this > num);
}
BigInt BigInt::operator + (BigInt num){
    for(int i = 0; i < N-1; i++){
        bigInt[i] += num.bigInt[i];
        bigInt[i+1] += bigInt[i]/BASE;
        bigInt[i] %= BASE;
    }
    return *this;
}
BigInt BigInt::operator - (BigInt num){
    if(sign){
        if(*this < num){
            *this = num-*this;
            sign = false;
        }
        else{
            for(int i = 0; i < N; i++){
                bigInt[i] -= num.bigInt[i];
                if(bigInt[i] < 0){
                    bigInt[i] += BASE;
                    bigInt[i+1]--;
                }
            }
        }
    }
    else *this+num;
    return *this;
}
istream& operator >> (istream& in, BigInt& num){
    char c[BigInt::N*BigInt::WIDTH+5];
    in >> c;
    num = BigInt(c);
    return in;
}
ostream& operator << (ostream& out, BigInt& num){
    if(!num.sign) out << '-';
    int idx = BigInt::N-1, first = 1;
    while(idx && num.bigInt[idx]==0) idx--;
    for(int i = idx; i >= 0; i--){
        if(first) printf("%d", num.bigInt[i]), first = 0;
        else printf("%0*d", BigInt::WIDTH, num.bigInt[i]);
    }
    return out;
}
void solution(BigInt &tanjiro, BigInt &zenitsu, BigInt &inosuke, int n){
    while(n--){
        BigInt num;
        cin >> num;
        if(inosuke>=tanjiro && inosuke>=zenitsu) inosuke-num;
        else if(tanjiro >= zenitsu) tanjiro-num;
        else zenitsu-num;
    }
}