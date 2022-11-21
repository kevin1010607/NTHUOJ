#include"function.h"
void RleCodec::encode(){
    std::string tmp = "";
    int n = 0; char pre = code_str[0];
    code_str += ' ';
    for(char c:code_str){
        if(c != pre){
            while(n >= 26) tmp = tmp+"QZ"+pre, n -= 26;
            if(n) tmp = tmp+"Q"+(char)('A'+n-1)+pre;
            pre = c, n = 1;
        }
        else n++;
    }
    code_str = tmp;
    encoded = true;
}
void RleCodec::decode(){
    std::string tmp = "";
    int n;
    for(int i = 0; i < code_str.size(); i+=3){
        n = code_str[i+1]-'A'+1;
        while(n--) tmp += code_str[i+2];
    }
    code_str = tmp;
    encoded = false;
}