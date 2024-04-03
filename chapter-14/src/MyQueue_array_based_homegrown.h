
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

private:
    static const int INITIAL_CAPACITY = 10;

    ValueType *array;
    int capacity;
    int head;
    int tail;

    void expandCapacity();

    void deepCopy(const MyQueue<ValueType> &src);

};

template <typename ValueType>
MyQueue<ValueType>::MyQueue() {
    capacity = INITIAL_CAPACITY;
    array = new ValueType[capacity];
    head = tail = 0;
}


template <typename ValueType>
MyQueue<ValueType>::~MyQueue() {
    delete [] array;
}

template <typename ValueType>
int MyQueue<ValueType>::size() const {
    if(head <= tail) {
        return tail - head;
    }
    else {
        return tail + capacity - head;
    }
}

template <typename ValueType>
bool MyQueue<ValueType>::isEmpty() const {
    return head == tail;
}

template <typename ValueType>
void MyQueue<ValueType>::clear() {
    head = tail = 0;
}

template <typename ValueType>
void MyQueue<ValueType>::enqueue(ValueType value) {
    array[tail] = value;
    tail = (tail + 1) % capacity;

    if(tail == head) expandCapacity();
}

template <typename ValueType>
ValueType MyQueue<ValueType>::dequeue() {
    if(isEmpty()) error("dequeue: Attempting to dequeue an empty queue.");
    ValueType result = array[head];
    head = (head + 1) % capacity;
    return result;
}

template <typename ValueType>
ValueType MyQueue<ValueType>::peek() const {
    if(isEmpty()) error("peek: Attempting to peek at an empty queue.");
    return array[head];
}

template <typename ValueType>
MyQueue<ValueType>::MyQueue(const MyQueue<ValueType> &src) {
    deepCopy(src);
}


template <typename ValueType>
MyQueue<ValueType> & MyQueue<ValueType>::operator= (const MyQueue<ValueType> &src) {
    if(this != &src) {
        delete [] array;
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void MyQueue<ValueType>::deepCopy(const MyQueue<ValueType> &src) {
    capacity = src.capacity;
    array = new ValueType [capacity];
    head = src.head, tail = src.tail;

    if(head <= tail) {
        for(int i = head; i < tail; ++i) {
            array[i] = src.array[i];
        }
    }
    else {
        for(int i = 0; i < tail; ++i) {
            array[i] = src.array[i];
        }

        for(int i = head; i < capacity; ++i) {
            array[i] = src.array[i];
        }
    }
}


template <typename ValueType>
void MyQueue<ValueType>::expandCapacity() {
    ValueType *elementsInQueue = new ValueType[capacity];

    int pos = 0;

    for(int i = head; i < capacity; ++i) {
        elementsInQueue[pos ++] = array[i];
    }
    for(int i = 0; i < tail; ++i) {
        elementsInQueue[pos ++] = array[i];
    }


    capacity *= 2;
    array = new ValueType [capacity];
    for(int i = 0; i < pos; ++i) {
        array[i] = elementsInQueue[i];
    }

    head = 0, tail = pos;
    delete [] elementsInQueue;

}
#endif
