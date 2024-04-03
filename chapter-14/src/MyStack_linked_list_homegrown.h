
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
    struct Cell
    {
        ValueType data;
        Cell *link;
    };

    Cell *list;
    int count;


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

template<typename ValueType>
MyStack<ValueType>::MyStack() {
    list = NULL;
    count = 0;
}

template <typename ValueType>
MyStack<ValueType>::~MyStack() {
    Cell *p = list, *q = NULL;
    while(p != NULL) {
        q = p->link;
        delete p;
        p = q;
    }
    list = NULL;
}

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

    Cell *p = list, *q = NULL;
    while(p != NULL) {
        q = p->link;
        delete p;
        p = q;
    }
    list = NULL;
    count = 0;
}

template <typename ValueType>
void MyStack<ValueType>::push(ValueType value) {

    Cell *tmp = new Cell;
    tmp->data = value;
    tmp->link = list;
    list = tmp;
    count ++;

}

template <typename ValueType>
ValueType MyStack<ValueType>::pop() {
    ValueType value = list->data;
    Cell *tmp = list;
    list = list->link;
    delete tmp;
    return value;
}

template <typename ValueType>
ValueType MyStack<ValueType>::peek() const {
    return list->data;
}

template<typename ValueType>
MyStack<ValueType>::MyStack(const MyStack<ValueType> &src) {
    deepCopy(src);
}

template <typename ValueType>
MyStack<ValueType>& MyStack<ValueType>::operator =(const MyStack<ValueType> &src) {
    if(this != &src) {

        Cell *p = this->list, *q = NULL;
        while(p != NULL) {
            q = p->link;
            delete p;
            p = q;
        }
        this->list = NULL;
        count =  0;

        deepCopy(src);
    }
    return *this;
}


template <typename ValueType>
void MyStack<ValueType>::deepCopy(const MyStack<ValueType> &src) {

    this->list = NULL;

    Cell *p = src.list;
    if(p != NULL) {
        Cell *tmp = new Cell;
        tmp->data = p->data;
        tmp->link = NULL;

        this->list = tmp;

        p = p->link;


        Cell *q = this->list;
        while(p != NULL) {
            Cell *tmp = new Cell;
            tmp->data = p->data;
            tmp->link = NULL;

            q->link = tmp;
            q = q->link;

            p = p->link;
        }

    }
    count = src.count;
}

#endif _mystack_h
