#include "function.h"
void IdiotSandwich::print(std::ostream &out){
    out << "An idiot sandwich with intelligence level " << getINT() << " only.";
}
void NormalSandwich::print(std::ostream &out){
    out << getName() << ". Masterpiece of sandwiches.";
}
Dish::~Dish(){
    delete food;
}
std::istream& operator>>(std::istream& in, Dish& d){
    std::string s;
    in >> s;
    if(s == "Ramsay"){
        int val;
        in >> val;
        d.food = new IdiotSandwich(val);
    }
    else{
        d.food = new NormalSandwich(s);
    }
    return in;
}