
/*
 * File: mystack.h
 * -----------------
 * This interface exports a template version of the Stack class.
 */

#ifndef _mystack_h
#define _mystack_h

#include "error.h"

/*
 * Class: MyStack<ValueType>
 * ----------------
 * This class implements a stack of the specified value type.
 */
template <typename ValueType>
class MyStack{
public:
    /*
     * Constructor: MyStack
     * Usage: MyStack<ValueType> stack;
     * -------------------------------
     * Initializes a new empty stack.
     */
    MyStack();

    /*
     * Destructor: ~MyStack
     * Usage: (usually implicit)
     * -------------------------
     * Frees any heap storage associated with this stack.
     */

    ~MyStack();

    /*
     * Method: size
     * Usage: int nElems = stack.size();
     * -------------------------------
     * Returns the number of values in this stack.
     */
    int size() const;

    /*
     * Method: isEmpty
     * Usage: if(stack.isEmpty()) . . .
     * -------------------------------
     * Returns true if this stack contains no elements.
     */
    bool isEmpty() const;

    /*
     * Method: clear
     * Usage: stack.clear();
     * --------------------
     * Removes all elements from this stack.
     */
    void clear();

    /*
     * Method: push
     * Usage: stack.push(value);
     * ---------------------
     * Pushes the specified value onto this stack.
     */
    void push(ValueType value);

    /*
     * Method: pop
     * Usage: ValueType ch = stack.pop();
     * ----------------------------
     * Remove the top element from this stack and return it. This
     * method signals an error if called on an empty stack.
     */
    ValueType pop();

    /*
     * Method: peak
     * Usage: ValueType top = stack.peak();
     * -----------------------------------
     * Returns the value of top element from this stack without
     * removing it. Raises an error if called on an empty stack.
     */
    ValueType peek() const;

    /*
     * Copy constructor and assignment operator
     * ----------------------------------------
     * These methods implement deep copying for stack.
     */

    MyStack(const MyStack<ValueType> &src);
    MyStack<ValueType> &operator=(const MyStack<ValueType> &src);

    /*
     * The private section of the class goes here.
     */

    /* Private section */

    /*
     * Implementation notes
     * ---------------------
     * This version of the stack.h interface uses a dynamic array to store
     * the elements of the stack. The array begins with INITIAL_CAPACITY
     * elements and doubles the size whenever it runs out of space. This
     * discipline guarantees that the push method has O(1) amortized cost.
     */
private:
    /* Private constants */
    static const int INITIAL_CAPACITY = 10;
    /* Instance variables */

    ValueType *array;        // Dynamic array of the elements.
    int capacity;       // Allocated size of that array
    int count;          // The number of stack elements

    /* Private function prototype (helper function)*/
    void expandCapacity();

    /* copies the data from the src parameter into the current object. */
    void deepCopy(const MyStack<ValueType> &src);

    /*
     * Standard methods: copy constructor and assignment operator
     * ----------------------------------------------------------
     * The following lines make it illegal to copy a MyStack by defining
     * private versions of the copy constructor and assignment operator.
     */
    // MyStack(const MyStack<TypeValue> &src) {}
    // MyStack<ValueType> & operator=(const MyStack<TypeValue> &src) {return *this;}

};


/*
 * Implementation section
 * ----------------------
 * C++ requires that the implementation for a template class be available
 * to that compiler whenever that type is used. The effect of this
 * restriction is that header files must include the implementation.
 * Clients should not need to look at any of the code beyond this point.
 */

/*
 * Implementation notes: MyStack constructor
 * -----------------------------------------
 * The constructor must allocate the array storage for the stack elements
 * and initialize the fields of the object.
 */

template <typename ValueType>
MyStack<ValueType>::MyStack() {
    capacity = INITIAL_CAPACITY;
    array = new ValueType[capacity];
    count = 0;
}

/*
 * Implementation notes: ~MyStack
 * ------------------------------
 * The deconstructor frees any heap memory allocated by the class, which
 * is just the dynamic array of elements.
 */
template <typename ValueType>
MyStack<ValueType>::~MyStack() {
    delete [] array;
}

/*
 * Method: size, isEmpty, clear
 */

template <typename ValueType>
int MyStack<ValueType>::size() const {
    return count;
}

template <typename ValueType>
bool MyStack<ValueType>::isEmpty() const {
    return count == 0;
}

template <typename ValueType>
void MyStack<ValueType>::clear() {
    count = 0;
}


/*
 * Implemenation notes: push
 * -------------------------
 * This function must first check to see whether there is enough room for
 * the value and expand the array storage if necessary.
 */
template <typename ValueType>
void MyStack<ValueType>::push(ValueType value) {
    if(count == capacity) expandCapacity();
    array[count++] = value;
}


/*
 * Implementation notes: pop, peek
 * -------------------------------
 * These function must check for an empty stack and report an
 * error if there is no top element.
 */

template <typename ValueType>
ValueType MyStack<ValueType>::pop() {
    if(isEmpty()) error("pop: Attempting to pop an empty stack");
    return array[--count];
}

template <typename ValueType>
ValueType MyStack<ValueType>::peek() const {
    if(isEmpty()) error("peek: Attempting to peek at an empty stack");
    return array[count-1];
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * These methods follow the standard template, leaving the word to deepCopy.
 */

template <typename ValueType>
MyStack<ValueType>::MyStack(const MyStack<ValueType> &src) {
    deepCopy(src);
}

template <typename ValueType>
MyStack<ValueType>& MyStack<ValueType>::operator =(const MyStack<ValueType> &src) {
    if(this != &src) {
        delete array;
        deepCopy(src);
    }
    return *this;
}

/*
 * Implementation notes: deepCopy
 * ------------------------------
 * Copies the data from the src parameter into the current object.
 * All dynamic memory is reallocated to create a "deep copy" in which
 * the current object and the source object are independent.
 * //The capacity is set so the stack has some room to expand.
 */

template <typename ValueType>
void MyStack<ValueType>::deepCopy(const MyStack<ValueType> &src) {
    capacity = src.capacity;
    this->array = new ValueType[capacity];

    for(int i = 0; i < src.count; ++i) {
        array[i] = src.array[i];
    }
    count = src.count;
}


/*
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This private method doubles the capacity of the elements array whenever
 * it runs out of space. To do so, it must copy the pointer to the old
 * array, allocate a new array with twice the capacity, copy the values
 * from the old array to the new one, and finally free the old storage.
 */
template <typename ValueType>
void MyStack<ValueType>::expandCapacity() {
    ValueType * oldArray = array;
    capacity *= 2;
    array = new ValueType[capacity];
    for(int i = 0; i < count; ++i) {
        array[i] = oldArray[i];
    }
    delete []oldArray;

}


#endif _mystack_h
