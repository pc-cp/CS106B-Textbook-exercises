
#include <iostream>
#include "IntArray.h"
#include "error.h"

using namespace std;

/*
 * Implementation notes: constructor and destructor
 * ------------------------------------------------
 * The constructor must allocate the array storage for the array element
 * and initialize to 0. The deconstructor frees any heap memory allocated
 * by the class, which is just the array of elements.
 */
IntArray::IntArray(int n) {
    capacity = n;
    array = new int [capacity];
    // for(int i = 0; i < capacity; ++i) {
    //     array[i] = 0;
    // }
}

IntArray::~IntArray() {
    delete [] array;
}



/*
 * Implementation notes: size, isEmpty, clear
 * ------------------------------------------
 * These methods are each a single line and need no detailed documentaion.
 */

int IntArray::size() {
    return capacity;
}

int IntArray::get(int k) {
    if(k >= capacity) {
        error("k is outside the vector bounds.");
    }
    return array[k];
}


void IntArray::put(int k, int value) {
    if(k >= capacity) {
        error("k is outside the vector bounds.");
    }
    array[k] = value;
}


int & IntArray::operator[](int k) {
    if(k >= capacity) {
        error("k is outside the vector bounds.");
    }
    return this->array[k];
}

// assignment operator
IntArray & IntArray::operator=(const IntArray &src) {
    if(this != &src) {
        delete [] array;
        deepCopy(src);
    }
    return *this;
}
// copy constructor
IntArray::IntArray(const IntArray &src) {
    deepCopy(src);
}

void IntArray::deepCopy(const IntArray &src) {
    capacity = src.capacity;
    array = new int[capacity];
    for(int i = 0; i < capacity; ++i) {
        array[i] = src.array[i];
    }
}

