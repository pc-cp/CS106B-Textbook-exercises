
/* E-11-1.cpp
 * generates the bit patterns for the binary representation
 * of all integers that can be represented using the specified number of bits.
 *
 */

#include <iostream>
#include "set.h"

using namespace std;

void generateBinaryCode(int nBits);
Set<string> generateBinaryCodeRec(int nBits);
int main() {
    int nBits;

    while (true) {
        cin >> nBits;
        if(nBits <= 0) {
            cout << "input should > 0." << endl;
            continue;
        }
        generateBinaryCode(nBits);
    }
    return 0;
}

void generateBinaryCode(int nBits) {
    cout << generateBinaryCodeRec(nBits) << endl;
}


Set<string> generateBinaryCodeRec(int nBits) {
    Set<string> res;
    if(nBits == 0) {
        res += "";
    }
    else {
        Set<string> subres = generateBinaryCodeRec(nBits-1);
        for(string elem: subres) {
            res += "0" + elem;
            res += "1" + elem;
        }
    }
    return res;
}
