
#include "bigint.h"
#include "error.h"
#include "strlib.h"

// Default constructor initializes BigInt as 0.
BigInt::BigInt() {

    list = new Cell;
    list->digit = '0';
    len = 1;
}

/*
 * Tail insertion constructor for integer values. Converts an integer value
 * into a linked list of digits, preserving the order. If the value is 0,
 * initializes a single '0' digit. Otherwise, extracts each digit from the
 * integer and appends it to the list.
 */
BigInt::BigInt(int value) {

    if(value == 0) {
        list = new Cell;
        list->digit = '0';
        len = 1;
    }
    else {
        list = NULL;
        len = 0;
        Cell *p = list;
        while(value) {
            int digit = value % 10;
            Cell *tmp = new Cell;

            tmp->digit = integerToChar(digit);
            tmp->link = NULL;

            if(list == NULL) {
                list = tmp;
            }
            else {
                p->link = tmp;
            }
            p = tmp;
            len ++;
            value /= 10;
        }
    }
}

/*
 * Head insertion constructor for string values. Converts a string of digits
 * into a linked list, inserting each character at the head to preserve the
 * original order in the string.
 */
BigInt::BigInt(std::string value) {
    if(value.empty()) {
        list = new Cell;
        list->digit = '0';
        len = 1;
    }
    else {

        list = NULL;
        len = 0;

        for(int i = 0; i < value.size(); i++) {
            Cell *tmp = new Cell;
            tmp->digit = value[i];
            tmp->link = list;
            list = tmp;
            len ++;
        }
    }
}

// Clears the linked list of digits, effectively resetting the BigInt to NULL.
BigInt::~BigInt() {
    clear();
}

void BigInt::clear() {
    Cell *tmp = list, *q = NULL;

    while(tmp != NULL) {
        q = tmp->link;
        delete tmp;
        tmp = q;
    }
    list = NULL;
    len = 0;
}
// Returns a string representation of the BigInt by traversing the linked list.
std::string BigInt::toString() const{
    std::string res = "";
    Cell *tmp = list;
    while(tmp) {
        res = tmp->digit + res;
        tmp = tmp->link;
    }

    return res;
}
// Returns the number of digits in the BigInt.
int BigInt::length() const {
    return len;
}

/*
 * Implements addition of two BigInts. Iterates over each linked list
 * digit-by-digit, summing the values and handling carry. Constructs the
 * result string in reverse order to manage carry and then returns the BigInt
 * representation of the sum.
 */
BigInt operator +(const BigInt &lp, const BigInt &rp) {
    std::string res = "";

    int carry = 0;
    BigInt::Cell *plp = lp.list, *prp = rp.list;

    for(int i = 0; i < lp.length() || i < rp.length(); ++i) {
        if(i < lp.length()) {
            carry += charToInteger(plp->digit);
            plp = plp->link;
        }
        if(i < rp.length()) {
            carry += charToInteger(prp->digit);
            prp = prp->link;
        }

        res = integerToChar(carry%10) + res;
        carry /= 10;
    }
    if(carry) res = integerToChar(carry) + res;

    return BigInt(res);
}

/*
 * Implements multiplication of two BigInts using a helper method. The helper
 * method applies the grade-school multiplication algorithm digit by digit.
 */
BigInt operator *(const BigInt &lp, const BigInt &rp) {
    return helper(lp, rp, rp.length()-1);
}

/*
 * Helper function for multiplication. Multiplies a BigInt by each digit of
 * another BigInt and sums the intermediate results, accounting for place value.
 */

BigInt helper(const BigInt &lp, const BigInt &rp, int rpr) {
    BigInt res;

    if(rpr == -1) {
        return res;
    }
    else {
        int value = charToInteger(rp.toString()[rpr]);
        while(value--) {
            res = res + lp;
        }

        BigInt subres = helper(lp, rp, rpr-1);

        BigInt subresBase;
        int base = 10;
        for(int i = 0; i < base; ++i) {
            subresBase = subresBase + subres;
        }

        res = res + subresBase;
        return res;
    }

}


// Copy constructor: Performs a deep copy of a BigInt.
BigInt::BigInt(const BigInt &src) {
    deepCopy(src);
}

// Assignment operator: Ensures deep copy and handles self-assignment.
BigInt& BigInt::operator =(const BigInt &src) {
    if(this != &src) {
        clear();
        deepCopy(src);
    }
    return *this;
}

// Helper function for deep copying a BigInt.
void BigInt::deepCopy(const BigInt &src) {
    std::string res = "";
    Cell *tmp = src.list;

    while(tmp != NULL) {
        res = tmp->digit + res;
        tmp = tmp->link;
    }

    list = NULL;
    len = 0;

    if(res.size() == 0) {
        list = new Cell;
        list->digit = '0';
        len = 1;
    }
    else {
        for(int i = 0; i < res.size(); i++) {
            Cell *tmp = new Cell;
            tmp->digit = res[i];
            tmp->link = list;
            list = tmp;
            len ++;
        }
    }
}

// Overloads the << operator to enable direct output of BigInt objects.
std::ostream & operator << (std::ostream &os, const BigInt &bi) {
    return os << bi.toString();
}
