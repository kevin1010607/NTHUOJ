#include<iostream>
#include<set>
#include"function.h"
using namespace oj;
void oj::insert(std::map<int, String> &m, int key, const std::string &str){
    std::string s = str;
    if(m.find(key) != m.end()) s += m.at(key).str, m.erase(key);
    m.insert(std::pair<int, String>(key, String(s)));
}
void oj::output(const std::map<int, String> &m, int begin, int end){
    for(auto i:m) if(i.first>=begin && i.first<=end) std::cout << i.second << ' ';
}
void oj::erase(std::map<int, String> &m, int begin, int end){
    std::set<int> s;
    for(auto i:m) if(i.first>=begin && i.first<=end) s.insert(i.first);
    for(auto i:s) m.erase(i);
}
std::ostream& oj::operator<<(std::ostream &o, const std::map<int, String> &m){
    for(auto i:m) o << i.second << ' ';
    return o;
}