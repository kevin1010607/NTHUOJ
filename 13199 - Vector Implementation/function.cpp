#include"function.h"
using namespace oj;
Vector::~Vector(){clear(), delete[] arr_;}
Vector::Vector():size_(0),cap_(0),arr_(nullptr){}
Vector::Vector(const Vector &rhs):size_(0),arr_(nullptr){*this = rhs;}
Vector& Vector::operator=(const Vector &rhs){
    clear(), delete[] arr_;
    size_ = rhs.size_, cap_ = rhs.cap_, arr_ = new value_type*[cap_];
    for(int i = 0; i < size_; i++) arr_[i] = new value_type(rhs.arr_[i][0]);
    return *this;
}
reference Vector::front(){return arr_[0][0];}
reference Vector::back(){return arr_[size_-1][0];}
reference Vector::operator[](size_type pos){return arr_[pos][0];}
const_reference Vector::operator[](size_type pos) const{return arr_[pos][0];}
size_type Vector::capacity() const{return cap_;}
size_type Vector::size() const{return size_;}
void Vector::clear(){
    for(int i = 0; i < size_; i++) delete (void*)(arr_[i]);
    size_ = 0;
}
bool Vector::empty() const{return size_ == 0;}
void Vector::erase(size_type pos){
    delete (void*)(arr_[pos]), size_--;
    for(int i = pos; i < size_; i++) arr_[i] = arr_[i+1];
}
void Vector::insert(size_type pos, size_type cnt, const_reference val){
    size_type tmp = (cap_==0?1:cap_);
    while(size_+cnt > tmp) tmp *= 2;
    reserve(tmp), size_ += cnt;
    for(int i = size_-1; i >= pos+cnt; i--) arr_[i] = arr_[i-cnt];
    for(int i = 0; i < cnt; i++) arr_[pos+i] = new value_type(val);
}
void Vector::pop_back(){erase(size_-1);}
void Vector::pop_front(){erase(0);}
void Vector::push_back(const_reference val){insert(size_, 1, val);}
void Vector::push_front(const_reference val){insert(0, 1, val);}
void Vector::reserve(size_type new_capacity){
    if(new_capacity <= cap_) return;
    value_type **tmp = new value_type*[cap_ = new_capacity];
    for(int i = 0; i < size_; i++) tmp[i] = arr_[i];
    delete[] arr_, arr_ = tmp;
}
void Vector::shrink_to_fit(){
    value_type **tmp = new value_type*[cap_ = size_];
    for(int i = 0; i < size_; i++) tmp[i] = arr_[i];
    delete[] arr_, arr_ = tmp;
}