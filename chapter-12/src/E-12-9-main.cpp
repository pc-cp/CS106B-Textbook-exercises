
/*
 * File: E-12-9.cpp
 * define a class called MyString that approximates the behavior of the string class from the Standard C++ libraries.
 */

#include <iostream>
#include <cassert>
#include "mystring.h"

using namespace std;

int main() {
    MyString str(string("012345678"));
    assert(str == string("012345678"));
    assert(str.length() == 9);
    MyString str2 = str.substr(3);
    assert(str2 == string("345678"));
    assert(str2.length() == 6);
    MyString str3 = str.substr(4, 2);
    assert(str3 == string("45"));
    assert(str3.length() == 2);
    str3 += str2;
    assert(str3 == string("45345678"));
    assert(str3.length() == 8);
    str2 = str + str3;
    assert(str2 == string("01234567845345678"));
    cout << str << endl;
    assert(str[2] == '2');

    cout << str2 << ' ' << str3 << endl;
    // 012345678 <  01234567845345678
    assert((str < str2));
    // 01234567845345678 < 45345678
    assert((str2 < str3));
    // 45345678 > 012345678
    assert((str3 > str));

    MyString str4 = str;
    assert((str4 ==  str));

    str += '9';
    assert(str == string("0123456789"));
    assert(str.length() == 10);

    str += string("AB");
    assert(str == string("0123456789AB"));
    assert(str.length() == 12);

    cout << "MyString unit test succeeded" << endl;
    return 0;
}
