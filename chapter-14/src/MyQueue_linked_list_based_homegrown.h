
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
 * The array-based queue stores the elements in successive index
 * positions in an array, just as a stack does. What makes the queue
 * structure more complex is the need to avoiding shifting elements as
 * the the queue expands and contracts. In the array models, this goal is achieved
 * by keeping track of both the head and tail indices. The tail index increases by one
 * each time an element is enqueued, and the head index increases by one each time an
 * element is dequeued. Each index therefore marches toward the end of the allocated array
 * and will eventually reach the end. Rather than allocate new memory, this implementation
 * lets each index wrap around back to the beginning as if the ends of the array of elements
 * were joined to form a circle. This representation is called a ring buffer.
 *
 * The elements of the queue are stored in a dynamic array of the specified element type.
 * If the space in the array is ever exhausted, the implementation doubles the array capacity.
 * Note unused the queue capacity is reached when there is still one unsed element in the array.
 * If the queue is allowed to fill completely, the head and tail indices will have the same value,
 * and the queue will apear empty.
 */
private:
    struct Cell {
        ValueType data;
        Cell *link;
    };

    Cell *head;
    Cell *tail;
    int count;

    void deepCopy(const MyQueue<ValueType> &src);
};

/*
 * Implementaion section
 * ---------------------
 * Clients should not need to look at any of the code beyond this point.
 */

template <typename ValueType>
MyQueue<ValueType>::MyQueue() {
    head = tail = NULL;
    count = 0;
}

template <typename ValueType>
MyQueue<ValueType>::~MyQueue() {
    clear();
}


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

template <typename ValueType>
void MyQueue<ValueType>::deepCopy(const MyQueue<ValueType> &src) {
    Cell *headCp = src.head;
    while(headCp != NULL) {
        enqueue(headCp->data);
        headCp = headCp->link;
    }
}


#endif
