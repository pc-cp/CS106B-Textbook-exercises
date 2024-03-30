
#include <iostream>
#include "charstack.h"

using namespace std;

int main() {
    CharStack cstk;
    cout << sizeof(CharStack) << endl;
    cout << sizeof cstk << endl;
    for(int i = 0; i < 26; ++i) {
        cstk.push(char('A' + i));
    }
    cout << sizeof cstk << endl;
    // while(!cstk.isEmpty()) {
    //     cout << cstk.pop() << endl;
    // }

    return 0;
}
