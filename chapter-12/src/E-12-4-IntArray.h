
#ifndef _intarray_h
#define _intarray_h

class IntArray {
public:

    /*
     * Constructor: IntArray
     * Usage: IntArray arr(n)
     * ----------------------
     * Initialize an array of n elements, each with a value of 0.
     */
    IntArray(int n);

    /*
     * Deconstructor: ~IntArray
     * Usage: (usually implicit)
     * -------------------------
     * Frees any heap storage associated with this array.
     */
    ~IntArray();

    /*
     * Method: size
     * Usage: int nElems = arr.size();
     * -------------------------------
     * Returns the number of elements in this array.
     */
    int size();

    /*
     * Method: get
     * Usage: int value = arr.get(k);
     * ------------------------------
     * Return the element at position k.
     * If k is outside the vector bound, it
     * call error with an appropriate message.
     */

    int get(int k);

    /*
     * Method: put
     * Usage: arr.put(k, value);
     * -------------------------
     * assigns value to the element at position k.
     * As with get, the put method should call error if k is out of bounds.
     */
    void put(int k, int value);


private:
    // static const int CAPACITY_ARRAY = 10;
    int capacity;                   // allocatedSize
    int *array;                     // dynamic array of integer.
    // int effectiveSize;              // Current count of integers.

    // o prevent clients from copying IntArray objects.
    // Definition necessary to make copying illegal

    // assignment operator
    IntArray & operator=(const IntArray &src) {return *this;}
    // copy constructor
    IntArray(const IntArray &src) {}

};

#endif // _intarray_h
