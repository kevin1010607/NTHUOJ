#include "function.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int L, C;
    string command;
    
    cin >> L >> C;
    
    for (int i = 0; i < C; i++) {
        cin >> command;

        if (command == "INSERT") {
            insert(L);
        } 
        else if (command == "BOTTOM_ROW") {
            first_row(L, true);
        } 
        else if (command == "QUERY") {
            query(L);
        } 
        else if (command == "FLUSH") {
            flush();
        }
        else if (command == "RESET") {
            reset(L);
        }
    }
}