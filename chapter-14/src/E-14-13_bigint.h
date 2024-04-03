#ifndef _bigint_h
#define _bigint_h

#include <iostream>

/*
 * Class: BigInt
 * -------------
 * The BigInt class represents large integers using a linked list to store digits.
 * This allows the BigInt class to handle integers larger than those that can be
 * represented by built-in data types. The class supports basic arithmetic operations,
 * including addition and multiplication, as well as utility functions.
 */

class BigInt {

public:
    // Constructors:
    // Initializes a new BigInt to zero.
    BigInt();
    // Initializes a new BigInt with an integer value.
    BigInt(int value);
    // Initializes a new BigInt with a string representing a large integer.
    BigInt(std::string value);

    // Destructor: Frees the linked list.
    ~BigInt();
    // Clears the BigInt, resetting it to zero.
    void clear();
     // Converts the BigInt to its string representation.
    std::string toString() const;
    // Returns the number of digits in the BigInt.
    int length() const;

    // Arithmetic operations:
    friend BigInt operator+(const BigInt &lp, const BigInt &rp);
    friend BigInt operator*(const BigInt &lp, const BigInt &rp);
    // Helper function for multiplication.
    friend BigInt helper(const BigInt &lp, const BigInt &rp, int rpr);

    // Copy constructor and assignment operator for deep copying:
    BigInt(const BigInt &src);
    BigInt & operator = (const BigInt &src);

     // Stream insertion operator to allow BigInt to be printed directly.
    friend std::ostream & operator << (std::ostream &os, const BigInt &bi);

private:
    // Internal representation of a digit and its link in the list:
    struct Cell {
        char digit;
        Cell *link;
    };

    Cell *list;
    int len;
    // Helper function for deep copying.
    void deepCopy(const BigInt & src);
};

// Declarations for arithmetic operations:
BigInt operator +(const BigInt &lp, const BigInt &rp);
BigInt operator *(const BigInt &lp, const BigInt &rp);
BigInt helper(const BigInt &lp, const BigInt &rp, int rpr);

std::ostream & operator << (std::ostream &os, const BigInt &bi);
#endif //_bigint_h
