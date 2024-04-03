

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
     * linked list of the specified element type.
     */

private:
    struct Cell
    {
        ValueType value;
        Cell * link;
    };

    Cell *list;
    int count;

    void deepCopy(const MyVector<ValueType> &src);

};

/*
 * Implementation notes: MyVector constructor and deconstructor
 * ------------------------------------------------------------
 */

template <typename ValueType>
MyVector<ValueType>::MyVector() {
    list = NULL;
    count = 0;
}

template <typename ValueType>
MyVector<ValueType>::MyVector(int n, ValueType value) {
    count = n;
    while(n--) {
        add(value);
    }
}


template <typename ValueType>
MyVector<ValueType>::~MyVector() {
    clear();
}

/*
 * Implementation notes: size, isEmpty, clear
 * ------------------------------------------
 * These methods require only the count field and do not look at the data.
 */
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
    for(int i = 0; i < count; ++i) {
        remove(0);
    }
}


/*
 * Implementation notes: get, set
 * ------------------------------
 */
template <typename ValueType>
ValueType MyVector<ValueType>::get(int index) const {
    if(!(index >= 0 && index < count)) error("get: the index is not in the array index.");

    Cell *tmp = list;
    for(int i = 0; i < index; ++i) {
        tmp = tmp->link;
    }
    return tmp->value;

}

template <typename ValueType>
void MyVector<ValueType>::set(int index, ValueType value) {
    if(!(index >= 0 && index < count)) error("set: the index is not in the array index.");

    Cell *tmp = list;
    for(int i = 0; i < index; ++i) {
        tmp = tmp->link;
    }
    tmp->value = value;
}

/*
 * Implementation notes: add, insert, remove
 * -----------------------------------------
 */
template <typename ValueType>
void MyVector<ValueType>::insert(int index, ValueType value) {
    if(!(index >= 0 && index <= count)) error("insert: the index is not in the array index.");

    Cell *p = list, *q = NULL;

    for(int i = 0; i < index && p != NULL; ++i) {
        q = p;
        p = p->link;
    }

    Cell *tmp = new Cell;
    tmp->value = value;

    if(q == NULL) {
        tmp->link = list;
        list = tmp;
    }
    else {
        tmp->link = q->link;
        q->link = tmp;
    }

    count++;
}


template <typename ValueType>
void MyVector<ValueType>::remove(int index) {
    if(!(index >= 0 && index < count)) error("remove: the index is not in the array index.");

    Cell *p = head, *q = NULL;

    for(int i = 0; i < index && p != NULL; ++i) {
        q = p;
        p = p->link;
    }

    Cell *tmp = NULL;
    if(q == NULL) {
        tmp = head;
        head = head->link;

    }
    else {
        tmp = q->link;
        q->link = p->link;
    }
    delete tmp;
    count--;
}

template <typename ValueType>
void MyVector<ValueType>::add(ValueType value) {
    insert(count, value);
}

/*
 * Implementation notes: MyVector selection
 * ----------------------------------------
 * The following code implements traditional array selection using square
 * brackets for the index. To ensure that clients can assign to array
 * elements, this method uses an & to return the result by reference.
 */
template <typename ValueType>
ValueType& MyVector<ValueType>::operator [](int index) {
    if(!(index >= 0 && index < count)) error("operator []: the index is not in the array index.");
    Cell *tmp = head;

    for(int i = 0; i < index; ++i) {
        tmp = tmp->link;
    }

    return tmp->value;
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * These methods follow the standard template, leaving the work to deepCopy.
 */
template <typename ValueType>
MyVector<ValueType>::MyVector(const MyVector<ValueType> &src) {
    deepCopy(src);
}

template <typename ValueType>
MyVector<ValueType> & MyVector<ValueType>::operator =(const MyVector<ValueType> &src) {
    if(this != &src) {
        clear();
        deepCopy(src);
    }
    return *this;
}

/*
 * Implementation notes: deepCopy
 * ------------------------------
 * Copies the data from the src parameter into the current object.
 * All dynamic memory is reallocated to create a "deep copy" in
 * which the current object and the source object are independent.
 *
 */
template <typename ValueType>
void MyVector<ValueType>::deepCopy(const MyVector<ValueType> &src) {
    count = src.count;
    Cell *tmp = src.list;
    while(tmp) {
        add(tmp->value);
        tmp = tmp->link;
    }
}



#endif
