
/*
 * File: myvector.h
 * ----------------
 * This interface exports the MyVector template class, which provides an
 * efficient safe, convenient replacement for the array type in C++/
 */

#ifndef _myvector_h
#define _myvector_h

#include "error.h"
/*
 * Class: MyVector<ValueType>
 * --------------------------
 * This class stores an ordered list of values similart to an array. It
 * supports traditional array selection using square brackets, but also
 * supports inserting and deleting elements.
 */
template <typename ValueType>
class MyVector {
public:
    /*
     * Constructor: MyVector
     * Usage: MyVector<ValueType> vec;
     *        MyVector<ValueType> vec(n, value);
     * -----------------------------------------
     * Initializes a new Vector object. The first form creates an empty vector;
     * the second creates a Vector of size n in which each element is initialized
     * to the specified value or the default value for the element type.
     */

    MyVector();
    MyVector(int n, ValueType value = ValueType());


    /*
     * Destructor: ~MyVector
     * Usage: (usually implicit)
     * -------------------------
     * Frees any heap storage allocated by this vector.
     */

    ~MyVector();

    /*
     * Method: size
     * Usage: int n = vec.size();
     * --------------------------
     * Returns the number of values in this vector.
     */

    int size() const;

    /*
     * Method: isEmpty();
     * Usage: if(vec.isEmpty()) . . .
     * ------------------------------
     * Returns true if this vector contains no elements.
     */

    bool isEmpty() const;

    /*
     * Method: clear
     * Usage: vec.clear();
     * -------------------
     * Removes all elements from this vector.
     */
    void clear();

    /*
     * Method: get
     * Usage: ValueType value = vec.get(index);
     * ----------------------------------------
     * Returns the element at the specified index in this vector. This method
     * signals an error if the index is not in the array index.
     */

    ValueType get(int index) const;

    /*
     * Method: set
     * Usage: vec.set(index, value);
     * -----------------------------
     * Replaces the element at the specified index in this vector with a new
     * value. The previous value at that index is overwritten. This method
     * signals an error if the index is not in the array range.
     */

    void set(int index, ValueType value);

    /*
     * Method: insert
     * Usage: vec.insert(index, value);
     * ----------------------------
     * Inserts the element into this vector before the specified index. All
     * subsequent elements are shifted one position to the right. This method
     * signals an error if the index is outside the range from 0 up to end
     * including the length of the vector.
     */

    void insert(int index, ValueType value);

    /*
     * Method: remove
     * Usage: vec.remove(index);
     * -------------------------
     * Removes the element at the specified from this vector. All
     * subsequent elements are shifted one position to the left. This
     * method signals an error if the index is outside the array range.
     */
    void remove(int index);

    /*
     * Method: add
     * Usage: vec.add(value);
     * ----------------------
     * Adds a new value to the end of this vector.
     */

    void add(ValueType value);

    /*
     * Operator: []
     * Usage: vec[index]
     * -----------------
     * Overloads [] to select elements from this vector. This extension
     * enables the use of traditional array notation to get or set individual
     * elements. This method signals an error if the index is outside the
     * array range.
     */

    ValueType & operator[] (int index);

    /*
     * Copy constructor and assignment operator
     * ----------------------------------------
     * These methods implement deep copyint for vectors.
     */
    MyVector(const MyVector<ValueType> &src);
    MyVector<ValueType> & operator=(const MyVector<ValueType> &src);

    /*
     * Private section
     * Notes on the representation
     * ---------------------------
     * This version of the vector.h interface stores the elements in a
     * dynamic array of the specified element type. If the space in the
     * array is ever exhausted, the implementation doubles the array capacity.
     */

private:
    static const int INITIAL_CAPACITY = 10;

    ValueType *array;
    int capacity;
    int count;

    void deepCopy(const MyVector<ValueType> &src);
    void expandCapacity();

};

template <typename ValueType>
MyVector<ValueType>::MyVector() {
    capacity = INITIAL_CAPACITY;
    array = new ValueType[capacity];
    count = 0;
}

template <typename ValueType>
MyVector<ValueType>::MyVector(int n, ValueType value) {
    capacity = n;
    array = new ValueType[capacity];
    for(int i = 0; i < capacity; ++i) {
        array[i] = value;
    }
    count = capacity;
}


template <typename ValueType>
MyVector<ValueType>::~MyVector() {
    delete [] array;
}

template <typename ValueType>
int MyVector<ValueType>::size() const {
    return count;
}

template <typename ValueType>
bool MyVector<ValueType>::isEmpty() const {
    return count == 0;
}

template <typename ValueType>
void MyVector<ValueType>::clear() {
    count = 0;
}

template <typename ValueType>
ValueType MyVector<ValueType>::get(int index) const {
    if(!(index >= 0 && index < count)) error("get: the index is not in the array index.");
    return array[index];
}

template <typename ValueType>
void MyVector<ValueType>::set(int index, ValueType value) {
    if(!(index >= 0 && index < count)) error("set: the index is not in the array index.");

    array[index] = value;
}

template <typename ValueType>
void MyVector<ValueType>::insert(int index, ValueType value) {
    if(!(index >= 0 && index < count)) error("insert: the index is not in the array index.");
    if(count == capacity) expandCapacity();
    for(int i = count; i > index; i--) {
        array[i] = array[i-1];
    }
    set(index, value);
    count++;
}


template <typename ValueType>
void MyVector<ValueType>::remove(int index) {
    if(!(index >= 0 && index < count)) error("remove: the index is not in the array index.");
    if(isEmpty()) error("remove: the array is empty.");
    for(int i = index; i < count-1; i ++) {
        array[i] = array[i+1];
    }
    count--;
}

template <typename ValueType>
void MyVector<ValueType>::add(ValueType value) {
    if(count == capacity) expandCapacity();
    array[count] = value;
    count ++ ;
}

template <typename ValueType>
ValueType& MyVector<ValueType>::operator [](int index) {
    if(!(index >= 0 && index < count)) error("operator []: the index is not in the array index.");
    return array[index];
}

template <typename ValueType>
MyVector<ValueType>::MyVector(const MyVector<ValueType> &src) {
    deepCopy(src);
}

template <typename ValueType>
MyVector<ValueType> & MyVector<ValueType>::operator =(const MyVector<ValueType> &src) {
    if(this != &src) {
        delete [] array;
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void MyVector<ValueType>::deepCopy(const MyVector<ValueType> &src) {
    capacity = src.capacity;
    count = src.count;
    array = new ValueType[capacity];
    for(int i = 0; i < count; ++i) {
        array[i] = src.array[i];
    }
}

template <typename ValueType>
void MyVector<ValueType>::expandCapacity() {
    ValueType * oldArray = array;

    capacity *= 2;
    array = new ValueType[capacity];
    for(int i = 0; i < count; ++i) {
        array[i] = oldArray[i];
    }
    delete [] oldArray;
}

#endif
