
#include <iostream>
#include "bigint.h"

using namespace std;

int main() {

    BigInt bi;

    for(int i = 0; i <= 52; ++i) {
        bi = BigInt(1);
        for(int j = 0; j <= i; ++j) {
            if(j == 0) {
                bi = bi * BigInt(1);
            }
            else {
                bi = bi * BigInt(j);
            }
        }
        cout << bi << endl;
    }
    return 0;
}
