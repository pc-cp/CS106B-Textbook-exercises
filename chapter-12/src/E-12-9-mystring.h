
#ifndef _mystring_h
#define _mystring_h

#include <string>
#include <ostream>
class MyString {

public:
    MyString(std::string str);

    ~MyString();

    std::string toString();

    int length() const;
    MyString substr(int start) const;
    MyString substr(int start, int n) const;

    friend MyString operator+ (const MyString &lh, const MyString &rh);
    MyString &operator += (const MyString &rh);
    MyString &operator +=(const char &rh);
    MyString &operator +=(const std::string &rh);

    char & operator[] (int k);
    friend bool operator == (const MyString &lh, const MyString &rh);
    friend bool operator != (const MyString &lh, const MyString &rh);
    friend bool operator < (const MyString &lh, const MyString &rh);
    friend bool operator <= (const MyString &lh, const MyString &rh);
    friend bool operator > (const MyString &lh, const MyString &rh);
    friend bool operator >= (const MyString &lh, const MyString &rh);

    MyString(const MyString &src);

    MyString & operator= (const MyString &src);

private:
    char *c_str;
    int capacity;       // allocated size
    int count;          // effective size


    void deepCopy(const MyString &src);
};

MyString operator+ (const MyString &lh, const MyString &rh);
MyString &operator += (const MyString &lh, const MyString rh);
bool operator == (const MyString &lh, const MyString &rh);
bool operator != (const MyString &lh, const MyString &rh);
bool operator < (const MyString &lh, const MyString &rh);
bool operator <= (const MyString &lh, const MyString &rh);
bool operator > (const MyString &lh, const MyString &rh);
bool operator >= (const MyString &lh, const MyString &rh);


std::ostream & operator<< (std::ostream &os, const MyString str);


#endif
