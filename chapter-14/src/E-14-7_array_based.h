

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
    static const int INITIAL_CAPACITY = 10;

    ValueType *array;
    int capacity;
    int head;
    int tail;
    // Private method prototypes.
    void expandCapacity();

    void deepCopy(const MyQueue<ValueType> &src);

    void mySwap(ValueType &a, ValueType &b);
};

/*
 * Implementaion section
 * ---------------------
 * Clients should not need to look at any of the code beyond this point.
 */

/*
 * Implementation notes: Queue constructor
 * ---------------------------------------
 * The constructor allocates the array storage and initializes the fields.
 */
template <typename ValueType>
MyQueue<ValueType>::MyQueue() {
    capacity = INITIAL_CAPACITY;
    array = new ValueType[capacity];
    head = tail = 0;
}


/*
 * Implementation notes: ~Queue
 * ----------------------------
 * The destructor frees any memory that is allocated by the implementation.
 */
template <typename ValueType>
MyQueue<ValueType>::~MyQueue() {
    delete [] array;
}

/*
 * Implementation notes: size
 * --------------------------
 * The size is calculated from head and tail using modular arithmetric.
 */
template <typename ValueType>
int MyQueue<ValueType>::size() const {
    return (tail + capacity - head) % capacity;

}

/*
 * Implementation notes: isEmpty
 * -----------------------------
 * The queue is empty whenever the head and tail pointer are equal. This
 *  interpretation means that the queue must always leave one unused space.
 */
template <typename ValueType>
bool MyQueue<ValueType>::isEmpty() const {
    return head == tail;
}

/*
 * Implementation notes: clear
 * ---------------------------
 * The clear method need not take account of where in the ring buffer any
 * existing data is stored and can simply reset the head and tail indices.
 */
template <typename ValueType>
void MyQueue<ValueType>::clear() {
    head = tail = 0;
}

/* Implementation notes: enqueue
 * ------------------------------
 * This method must first check to see whether there is enough room for
 * the element and expand the array storage if necessary. Because it is
 * otherwise impossible to differentiate the case when a queue is empty
 * from when it is completely full, this implementation expands the queue
 * when the size is one less than the capacity.
 */
template <typename ValueType>
void MyQueue<ValueType>::enqueue(ValueType value) {
    if(size() == capacity - 1) expandCapacity();
    array[tail] = value;
    tail = (tail + 1) % capacity;


}

/*
 * Implementation notes: dequeue, peek
 * -----------------------------------
 * These methods must check for an empty queue and report an
 * error if there is no first element.
 */
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


/*
 * Implementation notes: reverse
 * -----------------------------
 * use double pointer to traverse the elements in the queue.
 */

template <typename ValueType>
void MyQueue<ValueType>::reverse() {
    int i = head, j = (tail-1 + capacity) % capacity;
    while(i != j) {
        mySwap(array[i], array[j]);
        i = (i + 1) % capacity;
        j = (j - 1 + capacity) % capacity;
    }
}

/*
 * Implementation notes: Deep copying support.
 * -------------------------------------------
 * These methods implement deep copying for queues.
 */
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
    int count = src.size();
    capacity = count + INITIAL_CAPACITY;
    array = new ValueType[capacity];
    for(int i = 0; i < count; ++i) {
        array[i] = src.array[(src.head + i) % src.capacity];
    }
    head = 0;
    tail = count;
}


/*
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This private method doubles the capacity of the dynamic array whenever
 * it runs out of space. For simplicity, this implementation also shifts
 * all the elements back to the beginning of the array.
 */
template <typename ValueType>
void MyQueue<ValueType>::expandCapacity() {
    int count = size();
    ValueType *oldArray = array;
    array = new ValueType[2 * capacity];
    for(int i = 0; i < count; ++i) {
        array[i] = oldArray[(head + i) % capacity];
    }
    capacity *= 2;
    head = 0;
    tail = count;
    delete [] oldArray;

}


/*
 * Method: mySwap
 * --------------
 * helper function to reverse function.
 */
template <typename ValueType>
void MyQueue<ValueType>::mySwap(ValueType &a, ValueType &b) {
    ValueType tmp;
    tmp = a;
    a = b;
    b = tmp;
}
#endif
