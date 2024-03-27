
/* E-11-3.cpp
 * Write overloaded versions of the integerToString
 * and stringToInteger functions that take a second
 * argument indicating the numeric base,
 * which can be any integer in the range 2
 * through 36 (the 10 digits plus the 26 letters).
 */

#include <iostream>
#include "vector.h"

using namespace std;

const string symbolTable = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string integerToString1(int num, int base);
int stringToInteger1(string num, int base);

int main() {
    cout << integerToString1(-1, 16) << endl;
    cout << stringToInteger1("111111", 2) << endl;
    return 0;
}

string integerToString1(int num, int base) {
    unsigned int internalBitPattern = (unsigned int)num;
    string result = "";

    while(internalBitPattern) {
        char currentSymbol = symbolTable[internalBitPattern % base];
        result = currentSymbol + result;
        internalBitPattern /= base;
    }
    return result;
}
int stringToInteger1(string num, int base) {
    int result = 0;

    int P = 1;
    for(int i = num.size()-1; i >= 0; i--) {
        int index = symbolTable.find(num[i]);
        if(index >= base) {
            error("the digits is out of range for the specified base.");
        }
        result += P * index;
        P *= base;
    }
    return result;
}
