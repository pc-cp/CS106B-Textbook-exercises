

/*
 * File: _mypqueue_h
 * --------------
 * This interface exports a template version of the PriorityQueue class.
 */
#ifndef _mypqueue_h
#define _mypqueue_h

#include "error.h"

/*
 * Class: MyPQueue<ValueType>
 * -------------------------
 * This class implements a PriorityQueue of the specified value type.
 */
template <typename ValueType>
class MyPQueue {
public:
    /*
     * Constructor: MyPQueue
     * Usage: MyPQueue<ValueType> queue;
     * ------------------------------
     * Initializes a new empty pqueue.
     */
    MyPQueue();

    /*
     * Destructor: ~MyPQueue
     * Usage: (usually implicit)
     * -------------------------
     * Frees any heap storage associated with this queue.
     */
    ~MyPQueue();

    /*
     * Method: size
     * Usage: int n = pqueue.size();
     * ----------------------------
     * Returns the number of values in the queue.
     */
    int size() const;

    /*
     * Method: isEmpty
     * Usage: if(pqueue.isEmpty()) . . .
     * --------------------------------
     * Returns true if the pqueue contains no elements.
     */
    bool isEmpty() const;

    /*
     * Method: clear
     * Usage: pqueue.clear();
     * ---------------------
     * Removes all elements from this pqueue.
     */
    void clear();


    /*
     * Method: enqueue
     * Usage: pqueue.enqueue(value);
     * ----------------------------
     * Adds value to the end of the pqueue.
     */
    void enqueue(ValueType value, double priority);

    /*
     * Method: dequeue
     * Usage: ValueType first = pqueue.dequeue();
     * -----------------------------------------
     * Removes and returns the first value in the pqueue. This
     * method signals an error if called on an empty pqueue.
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
    MyPQueue(const MyPQueue<ValueType> &src);
    MyPQueue<ValueType> & operator = (const MyPQueue<ValueType> & src);

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
        double priority;
        Cell *link;
    };

    Cell *head;
    Cell *tail;
    int count;

    void deepCopy(const MyPQueue<ValueType> &src);

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
 * Implementation notes: MyPQueue constructor
 * ---------------------------------------
 * The constructor creates an empty linked list and sets the count to 0.
 */
template <typename ValueType>
MyPQueue<ValueType>::MyPQueue() {
    head = tail = NULL;
    count = 0;
}

/*
 * Implementation notes: ~MyQueue destructor
 * -----------------------------------------
 * The destructor frees any heap memory allocated by the queue.
 */
template <typename ValueType>
MyPQueue<ValueType>::~MyPQueue() {
    clear();
}

/*
 * Implementation notes: size, isEmpty, clear
 * ------------------------------------------
 * These methods use the count Variable and therefore run in constant time.
 */
template <typename ValueType>
int MyPQueue<ValueType>::size() const {
    return count;
}

template <typename ValueType>
bool MyPQueue<ValueType>::isEmpty() const {
    return count == 0;
}

template <typename ValueType>
void MyPQueue<ValueType>::clear() {
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
void MyPQueue<ValueType>::enqueue(ValueType value, double priority) {
    Cell *tmp = new Cell;
    tmp->data = value;
    tmp->priority = priority;
    tmp->link = NULL;
    // pqueue is empty
    if(head == NULL) {
        tail = head = tmp;

    }
    else {
        Cell *p = head, *q = NULL;
        while(p != NULL && p->priority <= tmp->priority) {
            q = p;
            p = p->link;
        }
        // tmp should be the first element
        if(q == NULL) {
            tmp->link = head;
            head = tmp;
        }
        // q is the last cell that priority <= tmp.priority
        else {
            tmp->link = q->link;
            q->link = tmp;
            // if q is tail, then new tail is tmp
            if(q == tail) {
                tail = tmp;
            }
        }

    }
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
ValueType MyPQueue<ValueType>::dequeue() {
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
ValueType MyPQueue<ValueType>::peek() const {
    if(isEmpty()) error("peek: Attempting to peek at an empty queue.");
    return head->data;
}

/*
 * Implementation notes: reverse
 * -----------------------------
 * use iterative algorithm
 */

template <typename ValueType>
void MyPQueue<ValueType>::reverse() {
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
MyPQueue<ValueType>::MyPQueue(const MyPQueue<ValueType> &src) {
    deepCopy(src);
}

template <typename ValueType>
MyPQueue<ValueType> & MyPQueue<ValueType>::operator =(const MyPQueue<ValueType> &src) {
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
void MyPQueue<ValueType>::deepCopy(const MyPQueue<ValueType> &src) {
    Cell *headCp = src.head;
    while(headCp != NULL) {
        enqueue(headCp->data, headCp->priority);
        headCp = headCp->link;
    }
}


#endif
