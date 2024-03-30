
/*
 * File: charstack.cpp
 * -------------------
 * This file implements the CharStack class.
 */

#include "charstack.h"
#include "error.h"

using namespace std;

/*
 * Implementation notes: constructor and destructor
 * ------------------------------------------------
 * The constructor must allocate the array storage for the stack elements
 * and initialize the field of the object. The destructor frees any heap
 * memory allocated by te class, which is just the array of elements.
 */

CharStack::CharStack() {
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    count = 0;
}

/*
 * Implementation notes: ~CharStack
 * --------------------------------
 * The destructor frees any heap memory allocated by the class, which
 * is just the dynamic array of elements.
 */

CharStack::~CharStack() {
    delete [] array;
}

/*
 * Implementation notes: size, isEmpty, clear
 * ------------------------------------------
 * These methods are each a single line and need no detailed documentaion.
 */

int CharStack::size() {
    return count;
}

bool CharStack::isEmpty() {
    return count == 0;
}

void CharStack::clear() {
    count = 0;
}

/*
 * Implementaion notes: push
 * -------------------------
 * This function must first check to see whether there is enough room for
 * teh character and expand the array storage if necessary.
 */

void CharStack::push(char ch) {
    if(count == capacity) expandCapacity();
    array[count ++] = ch;
}

/*
 * Implementation notes: pop, peak
 * -------------------------------
 * These functions mush check for an empty stack and report an error
 * if there is no top element.
 *
 */
char CharStack::pop() {
    if(isEmpty()) error("pop: Attempting to pop an empty stack");
    return array[--count];
}

char CharStack::peak() {
    if(isEmpty()) error("peak: Attempting to peek at an empty stack.");
    return array[count-1];
}

/*
 * Implementation notes: expandCapacity
 * -------------------------------------
 * This private method doubles the capacity of the elements array whenever
 * it runs out of space. To do so, it must copy the pointer to the old
 * array, allocate a new array with twice the  capacity, copy the characters
 * from the old array to the new one, and finally free the old storage.
 */

void CharStack::expandCapacity() {
    char *oldArray = array;
    capacity *= 2;
    array = new char[capacity];
    for(int i = 0; i < count; ++i) {
        array[i] = oldArray[i];
    }
    delete [] oldArray;
}

