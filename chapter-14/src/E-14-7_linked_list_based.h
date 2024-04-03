

/*
 * File: _queue_h
 * --------------
 * This interface exports a template version of the Queue class.
 */
#ifndef _myqueue_h
#define _myqueue_h

#include "error.h"

/*
 * Class: MyQueue<ValueType>
 * -------------------------
 * This class implements a queue of the specified value type.
 */
template <typename ValueType>
class MyQueue {
public:
    /*
     * Constructor: Queue
     * Usage: Queue<ValueType> queue;
     * ------------------------------
     * Initializes a new empty queue.
     */
    MyQueue();

    /*
     * Destructor: ~Queue
     * Usage: (usually implicit)
     * -------------------------
     * Frees any heap storage associated with this queue.
     */
    ~MyQueue();

    /*
     * Method: size
     * Usage: int n = queue.size();
     * ----------------------------
     * Returns the number of values in the queue.
     */
    int size() const;

    /*
     * Method: isEmpty
     * Usage: if(queue.isEmpty()) . . .
     * --------------------------------
     * Returns true if the queue contains no elements.
     */
    bool isEmpty() const;

    /*
     * Method: clear
     * Usage: queue.clear();
     * ---------------------
     * Removes all elements from this queue.
     */
    void clear();


    /*
     * Method: enqueue
     * Usage: queue.enqueue(value);
     * ----------------------------
     * Adds value to the end of the queue.
     */
    void enqueue(ValueType value);

    /*
     * Method: dequeue
     * Usage: ValueType first = queue.dequeue();
     * -----------------------------------------
     * Removes and returns the first value in the queue. This
     * method signals an error if called on an empty queue.
     */
    ValueType dequeue();

    /*
     * Method: peek
     * Usage: ValueType first = queue.peek();
     * --------------------------------------
     * Returns the first value in the queue, without removing it. This
     * method signals an error if called on an empty queue.
     */

    ValueType peek() const;

    /*
     * Method: reverse
     * Usage: queue.reverse();
     * -----------------------
     * reverses the elements in the queue.
     */
    void reverse();

    /*
     * Copy constructor and assignment operator
     * ----------------------------------------
     * These methods implement deep copying for queues.
     */
    MyQueue(const MyQueue<ValueType> &src);
    MyQueue<ValueType> & operator = (const MyQueue<ValueType> & src);

    /*
 * Private section
 *
 * Implementation notes
 * --------------------
 * The list-based queue uses a linked list to store the elements
 * of the queue. To ensure that adding a new element to the tail
 * of the queue is fast, the data structure maintains a pointer to the last cell
 * in the queue as well as the first. If the queue is empty, both the head pointer
 * and the tail pointer are set to NULL.
 *
 */

private:
    /* Type for linked list cell. */
    struct Cell {
        ValueType data;
        Cell *link;
    };

    Cell *head;
    Cell *tail;
    int count;

    void deepCopy(const MyQueue<ValueType> &src);

    // Cell * helper(Cell *head);
};

/*
 * Implementaion section
 * ---------------------
 * C++ requires that the implementation for a template class be available
 * to that compiler whenever that type is used. The effect of this
 * restriction is that header files must include the implementation.
 * Clients should not need to look at any of the code beyond this point.
 */

/*
 * The main caveat is that this implementation/forward declaration convention
 * doesn't hold true for code that uses templates. Template code will still be
 * handed to you as .h files, but it (usually) is implemented directly in
 * the .h file, and won't have accompanying .cpp files.
 *
 * https://stackoverflow.com/questions/2887465/c-header-and-implementation-files-what-to-include
 */

/*
 * Implementation notes: MyQueue constructor
 * ---------------------------------------
 * The constructor creates an empty linked list and sets the count to 0.
 */
template <typename ValueType>
MyQueue<ValueType>::MyQueue() {
    head = tail = NULL;
    count = 0;
}

/*
 * Implementation notes: ~MyQueue destructor
 * -----------------------------------------
 * The destructor frees any heap memory allocated by the queue.
 */
template <typename ValueType>
MyQueue<ValueType>::~MyQueue() {
    clear();
}

/*
 * Implementation notes: size, isEmpty, clear
 * ------------------------------------------
 * These methods use the count Variable and therefore run in constant time.
 */
template <typename ValueType>
int MyQueue<ValueType>::size() const {
    return count;
}

template <typename ValueType>
bool MyQueue<ValueType>::isEmpty() const {
    return count == 0;
}

template <typename ValueType>
void MyQueue<ValueType>::clear() {
    while(count > 0) {
        dequeue();
    }
}

/*
 * Implementation notes: enqueue
 * -----------------------------
 * This method allocates a new list cell and chains it in at the tail of
 * the queue. If the queue is currently empty, the new cell must also
 * become the head in the queue.
 */
template <typename ValueType>
void MyQueue<ValueType>::enqueue(ValueType value) {
    Cell *tmp = new Cell;
    tmp->data = value;
    tmp->link = NULL;

    if(head == NULL) {
        head = tmp;
    }
    else {
        tail->link = tmp;
    }
    tail = tmp;
    count ++;
}

/*
 * Implementation notes: dequeue, peek
 * -----------------------------------
 * These methods must check for an empty queue and report an error if
 * there is no first element. The dequeue method must also check for
 * the case in which the queue becomes empty and set both the head
 * and tail pointer to NULL.
 */
template <typename ValueType>
ValueType MyQueue<ValueType>::dequeue() {
    if(isEmpty()) error("dequeue: Attempting to dequeue an empty queue.");
    Cell *tmp = head;
    ValueType result = tmp->data;

    head = head->link;
    if(head == NULL) {
        tail = NULL;
    }

    count--;
    delete tmp;
    return result;
}

template <typename ValueType>
ValueType MyQueue<ValueType>::peek() const {
    if(isEmpty()) error("peek: Attempting to peek at an empty queue.");
    return head->data;
}

/*
 * Implementation notes: reverse
 * -----------------------------
 * use iterative algorithm
 */

template <typename ValueType>
void MyQueue<ValueType>::reverse() {
    if(count >= 2) {
        Cell *p = head, *q = p->link, *r;
        while(q) {
            r = q->link;
            q->link = p;
            p = q;
            q = r;
        }
        tail = head;
        tail->link = NULL;
        head = p;
    }
}

/*
 * Implementaion notes: copy constructor and assignment operator
 * -------------------------------------------------------------
 * These methods follow the standard template, leaving the work to deepCopy.
 */
template <typename ValueType>
MyQueue<ValueType>::MyQueue(const MyQueue<ValueType> &src) {
    deepCopy(src);
}

template <typename ValueType>
MyQueue<ValueType> & MyQueue<ValueType>::operator =(const MyQueue<ValueType> &src) {
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
 * This implementation simply walks down the linked list in the
 * source object and enqueue each value in the destination.
 */
template <typename ValueType>
void MyQueue<ValueType>::deepCopy(const MyQueue<ValueType> &src) {
    Cell *headCp = src.head;
    while(headCp != NULL) {
        enqueue(headCp->data);
        headCp = headCp->link;
    }
}


#endif
