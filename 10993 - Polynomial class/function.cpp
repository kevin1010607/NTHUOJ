#include"function.h"
#define max(a,b) (((a)>(b))?(a):(b))
Polynomial::Polynomial():greatestPower(0){
    for(int i = 0; i < 101; i++) coefficients[i] = 0;
}
Polynomial::Polynomial(const int n, const int coe[51]):greatestPower(n){
    for(int i = 0; i < 101; i++) coefficients[i] = (i<=n?coe[i]:0);
}
Polynomial Polynomial::add(const Polynomial poly) const{
    Polynomial ans;
    ans.greatestPower = max(greatestPower, poly.greatestPower);
    for(int i = 0; i <= ans.greatestPower; i++) ans.coefficients[i] = coefficients[i]+poly.coefficients[i];
    while(ans.coefficients[ans.greatestPower]==0 && ans.greatestPower!=0) ans.greatestPower--;
    return ans;
}
Polynomial Polynomial::subtract(const Polynomial poly) const{
    Polynomial ans;
    ans.greatestPower = max(greatestPower, poly.greatestPower);
    for(int i = 0; i <= ans.greatestPower; i++) ans.coefficients[i] = coefficients[i]-poly.coefficients[i];
    while(ans.coefficients[ans.greatestPower]==0 && ans.greatestPower!=0) ans.greatestPower--;
    return ans;
}
Polynomial Polynomial::multiplication(const Polynomial poly) const{
    Polynomial ans;
    ans.greatestPower = greatestPower+poly.greatestPower;
    for(int i = 0; i <= greatestPower; i++){
        for(int j = 0; j <= poly.greatestPower; j++){
            ans.coefficients[i+j] += coefficients[i]*poly.coefficients[j];
        }
    }
    while(ans.coefficients[ans.greatestPower] == 0) ans.greatestPower--;
    return ans;
}
void Polynomial::output() const{
    for(int i = greatestPower; i >= 0; i--) std::cout << coefficients[i] << (i!=0?" ":"");
}