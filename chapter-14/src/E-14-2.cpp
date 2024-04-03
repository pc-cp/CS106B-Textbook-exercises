
/*
 * File: E-14-2.cpp
 * Write a sort.h interface that exports a polymorphic version of the sort function that works with any base type that implements the standard relational operators.
 */
#include <iostream>
#include "vector.h"
#include "mysort.h"
#include "random.h"

using namespace std;
int main() {
    Vector<int> vec1;
    for(int i = 0; i < 5; ++i) {
        vec1.add(randomInteger(0, 100));
    }

    cout << vec1 << endl;

    mySort(vec1);
    cout << vec1 << endl;


    Vector<double> vec2;
    for(int i = 0; i < 5; ++i) {
        vec2.add(randomReal(0, 100.0));
    }
    cout << vec2 << endl;
    mySort(vec2);
    cout << vec2 << endl;


    return 0;
}
