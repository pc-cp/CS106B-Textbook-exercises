
#include <iostream>
#include <iomanip>
using namespace std;

typedef unsigned char * byte_pointer;

void showBits(unsigned short x);

int main() {
    string operand1, operand2;
    cout << "Enter x: ";
    cin >> operand1;
    cout << "Enter y: ";
    cin >> operand2;

    unsigned short x = 0, y = 0;
    for(int i = 0; i < operand1.size(); ++i) {
        unsigned short digit = operand1[i]-'0';
        x += (digit << (operand1.size()-1-i));
    }
    // showBits(x);
    for(int i = 0; i < operand2.size(); ++i) {
        unsigned short digit = operand2[i]-'0';
        y += (digit << (operand2.size()-1-i));
    }

    cout << setw(10) << right << "x & y = ";
    showBits(x & y);
    cout << setw(10) << right << "x | y = ";
    showBits(x | y);
    cout << setw(10) << right << "x ^ y = ";
    showBits(x ^ y);
    cout << setw(10) << right << "~y = ";
    showBits(~y);
    cout << setw(10) << right << "x &~y = ";
    showBits(x &~y);
    return 0;
}

void showBits(unsigned short x) {
    int bits = (sizeof x) * 8;
    for(int i = bits-1; i >= 0; i--) {
        cout << ((x >> i) & 1);
    }
    cout << endl;
}
