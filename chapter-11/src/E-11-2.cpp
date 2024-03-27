
/* E-11-2.cpp
 * generates the Gray code patterns for the specified number of bits
 */

#include <iostream>
#include "vector.h"

using namespace std;

void generateGrayCode(int nBits);
Vector<string> generateGrayCodeRec(int nBits);
int main() {
    int nBits;

    while (true) {
        cin >> nBits;
        if(nBits <= 0) {
            cout << "input should > 0." << endl;
            continue;
        }
        generateGrayCode(nBits);
    }
    return 0;
}

void generateGrayCode(int nBits) {
    cout << generateGrayCodeRec(nBits) << endl;
}


Vector<string> generateGrayCodeRec(int nBits) {
    Vector<string> res;
    if(nBits == 0) {
        res += "";
    }
    else {
        Vector<string> subres = generateGrayCodeRec(nBits-1);
        for(string elem: subres) {
            res += "0" + elem;
        }
        for(int i = subres.size()-1; i >= 0; i--) {
            res += "1" + subres[i];
        }

    }
    return res;
}
