
/*
 * File: E-12-2.cpp
 * allocates enough memory for the C-style string str
 * and then copies the characters—along with
 * the terminating null character—into the newly allocated memory.
 */

#include <iostream>
#include "error.h"
using namespace std;

char *copyCString(char *str);

int main() {

    char str[] = "hi";
    char *p = copyCString(str);
    cout << sizeof(p) << ' ' << strlen(p) <<' ' << p << endl;
    delete [] p;
    return 0;
}

char *copyCString(char *str) {
    int len = 0;
    while(str[len]) {
        len++;
    }

    char *des = new char [len+1];

    for(int i = 0; str[i]; ++i) {
        des[i] = str[i];
    }
    des[len] = '\0';
    return des;
}
