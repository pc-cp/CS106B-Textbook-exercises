
/*
 * File: E-12-1.cpp
 * Write a function createIndexArray(n) that allocates
 * a dynamic array of n integers in which each integer is
 * initialized to its own index.
 */

#include <iostream>
#include "error.h"
using namespace std;

int *createIndexArray(int n);

int main() {
    int n;
    cin >> n;

    int *p = createIndexArray(n);
    for(int i = 0; i < n; ++i) {
        cout << p[i] << ' ';
    }

    delete [] p;
    return 0;
}


int * createIndexArray(int n) {
    int *p = new int [n];
    if(p == NULL) {
        error("There is not enough memory in the heap area.");
    }

    for(int i = 0; i < n; ++i) {
        p[i] = i;
    }

    return p;
}
