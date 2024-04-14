
#include <iostream>
#include <sstream>
#include <string>
#include "myset.h"

using namespace std;


int main() {
    MySet<char> s1, s2;
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;
    cout << "s1 + s2 = " << s1 + s2 << endl;
    cout << "s1 * s2 = " << s1 * s2 << endl;
    cout << "s1 - s2 = " << s1 - s2 << endl;
    return 0;
}
