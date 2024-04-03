
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
    /* Type for linked list cell */
    struct Cell {
        ValueType data;         // The data value
        Cell *link;             // Link to the next cell
    };

    Cell *list;                 // Initial pointer in the list
    int count;                  // Number of elements

    /* Private method prototypes */
    void deepCopy(const MyStack<ValueType> &src);
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
 * The constructor must create an empty linked list and initialize the count.
 */
template<typename ValueType>
MyStack<ValueType>::MyStack() {
    list = NULL;
    count = 0;
}

/*
 * Implementation notes: MyStack destructor
 * ----------------------------------------
 * The destructor frees any heap memory that is allocated by the
 * implementation. Because clear frees each element it process,
 * this implementation of the destructor simply calls thet method.
 */
template <typename ValueType>
MyStack<ValueType>::~MyStack() {
    clear();
}


/*
 * Implementation notes: size, isEmpty
 * -----------------------------------
 * These methods use the count variable and therefore run in constant time.
 */
template <typename ValueType>
int MyStack<ValueType>::size() const {
    return count;
}

template <typename ValueType>
bool MyStack<ValueType>::isEmpty() const {
    return count == 0;
}

/*
 * Implementation notes: clear
 * ---------------------------
 * This method pops the stack until it is empty, thereby freeing each cell.
 */
template <typename ValueType>
void MyStack<ValueType>::clear() {

    while(count > 0) {
        pop();
    }
}

/*
 * Implementation notes: push
 * --------------------------
 * This method chains a new element noto the front of the list where it
 * becomes the top of the stack.
 */
template <typename ValueType>
void MyStack<ValueType>::push(ValueType value) {

    Cell *tmp = new Cell;
    tmp->data = value;
    tmp->link = list;
    list = tmp;
    count ++;

}
/*
 * Implementation notes: pop, peek
 * -------------------------------
 * These methods must check for an empty stack and report an error if
 * there is no top element. The pop method must free the cell to ensure
 * that the implementation does not leak memory as it executes.
 */
template <typename ValueType>
ValueType MyStack<ValueType>::pop() {
    if(isEmpty()) error("pop: Attempting to pop an empty stack");
    ValueType value = list->data;
    Cell *tmp = list;
    list = list->link;
    count--;
    delete tmp;
    return value;
}

/*
 *
 */
template <typename ValueType>
ValueType MyStack<ValueType>::peek() const {
    if(isEmpty()) error("peek: Attempting to peek at an empty stack");
    return list->data;
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * These methods follow the standard template, leaving the work to deepCopy.
 */
template<typename ValueType>
MyStack<ValueType>::MyStack(const MyStack<ValueType> &src) {
    deepCopy(src);
}

template <typename ValueType>
MyStack<ValueType>& MyStack<ValueType>::operator =(const MyStack<ValueType> &src) {
    if(this != &src) {
        clear();

        deepCopy(src);
    }
    return *this;
}


/*
 * Implementation notes: deepCopy
 * ------------------------------
 * The deepCopy method creates a copy of the cells in the linked list.
 * The variable tail keeps track of the last cell in the chain.
 */
template <typename ValueType>
void MyStack<ValueType>::deepCopy(const MyStack<ValueType> &src) {
    count = src.count;
    Cell *tail = NULL;
    for(Cell *cp = src.list; cp != NULL; cp = cp->link) {
        Cell *ncp = new Cell;
        ncp->data = cp->data;
        if(tail == NULL) {
            list = ncp;
        }
        else {
            tail->link = ncp;
        }
        tail = ncp;
    }
    if(tail != NULL) tail->link = NULL;
}

#endif _mystack_h
