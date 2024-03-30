#include <iostream>
#include <ostream>
#include <string>
#include <mystring.h>
#include "error.h"

using namespace std;

MyString::MyString(std::string str) {
    capacity = str.size() * 2;
    c_str = new char[capacity];

    for(int i = 0; i <= str.size(); ++i) {
        if(i == str.size()) {
            c_str[i] = '\0';
        }
        else {
            c_str[i] = str[i];
        }
    }
    count = str.size();
}

MyString::~MyString() {
    delete [] c_str;
}

std::string MyString::toString() {
    string res = "";
    for(int i = 0; i < count; ++i) {
        res += c_str[i];
    }
    return res;
}

ostream & operator <<(ostream &os,  MyString str) {
    return os << str.toString();
}

int MyString::length() const{
    return count;
}

MyString MyString::substr(int start)  const{
    if(start >= count) {
        error("the index is outside the bounds of the string.");
    }
    string tmp = "";
    for(int i = start; i < count; ++i) {
        tmp += c_str[i];
    }

    return MyString(tmp);

}

MyString MyString::substr(int start, int n)  const{
    if(start >= count) {
        error("the index is outside the bounds of the string.");
    }
    int remainLen = count - start;
    int len = remainLen <= n ? remainLen : n;

    string tmp = "";
    for(int i = 0; i < len; ++i) {
        tmp += c_str[start + i];
    }

    return MyString(tmp);
}

MyString operator +(const MyString &lh, const MyString &rh) {
    string tmp = "";

    for(int i = 0; i < lh.length(); ++i) {
        tmp += lh.c_str[i];
    }

    for(int i = 0; i < rh.length(); ++i) {
        tmp += rh.c_str[i];
    }

    MyString res(tmp);
    return res;
}

MyString & MyString::operator +=(const MyString &rh) {

    if(this->capacity > this->length() + rh.length()) {
        ;
    }
    else {
        char *oldArray = this->c_str;

        capacity = (this->length() + rh.length()) * 2;
        this->c_str = new char [capacity];
        for(int i = 0; i < this->length(); ++i) {
            this->c_str[i] = oldArray[i];
        }
        delete [] oldArray;
    }
    for(int i = 0; i < rh.length(); ++i) {
        this->c_str[this->length() + i] = rh.c_str[i];
    }
    this->c_str[this->length() + rh.length()] = '\0';
    this->count += rh.count;
    return *this;
    // lh = lh + rh;
}

MyString & MyString::operator +=(const char &rh) {

    if(this->capacity > this->length()) {
        ;
    }
    else {
        char *oldArray = this->c_str;

        capacity = (this->length()+1) * 2;
        this->c_str = new char [capacity];
        for(int i = 0; i < this->length(); ++i) {
            this->c_str[i] = oldArray[i];
        }
        delete [] oldArray;
    }

    this->c_str[this->length()] = rh;
    this->c_str[this->length()+1] = '\0';
    this->count ++;

    return *this;

}

MyString & MyString::operator +=(const string &rh) {
    return *this += MyString(rh);
}


char & MyString::operator[] (int k) {
    if(k >= this->length()) {
        error("the index is outside the bounds of the string.");
    }
    return this->c_str[k];
}

bool operator==(const MyString &lh, const MyString &rh) {
    if(lh.length() != rh.length()) {
        return false;
    }
    else {
        for(int i = 0; i < lh.length(); ++i) {
            if(lh.c_str[i] != rh.c_str[i]) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const MyString &lh, const MyString &rh) {
    return !(lh == rh);
}

bool operator<(const MyString &lh, const MyString &rh) {
    for(int i = 0; i < lh.length() && i < rh.length(); ++i) {
        if(lh.c_str[i] != rh.c_str[i]) {
            return lh.c_str[i] < rh.c_str[i];
        }
    }

    if(lh.length() != rh.length()) {
        return lh.length() < rh.length();
    }
    return false;
}

bool operator<=(const MyString &lh, const MyString &rh) {
    return (lh == rh) || (lh < rh);
}

bool operator>(const MyString &lh, const MyString &rh) {
    return !(lh <= rh);
}

bool operator>=(const MyString &lh, const MyString &rh) {
    return !(lh < rh);
}


MyString::MyString(const MyString &src) {
    deepCopy(src);
}

MyString & MyString::operator=(const MyString &src) {
    if(this != &src) {
        delete [] c_str;
        deepCopy(src);
    }
    return *this;
}

void MyString::deepCopy(const MyString &src) {

    capacity = src.capacity;
    c_str = new char [capacity];
    for(int i = 0; i < src.length(); ++i) {
        c_str[i] = src.c_str[i];
    }
    c_str[src.length()] = '\0';

    count = src.count;
}


