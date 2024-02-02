
/*
 * File:E-12.cpp
 * -------------
 * uses a stack to reverse a sequence of integers
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
#include "filelib.h"
#include "strlib.h"
#include "vector.h"
#include "map.h"
#include "set.h"
#include "error.h"
#include "grid.h"
#include "stack.h"
using namespace std;


/* Function prototype*/
void reverseSequenceOfIntegers(Stack<int> &stack);
/* Main function */
int main(void)
{
    Stack<int> stack;
    cout << "Enter a list of integers, ending with 0: " << endl;
    int value;
    while(true)
    {
        cout << "? ";
        cin >> value;
        if(value == 0) break;
        stack.push(value);
    }

    cout << "Those integers in reverse order are: " << endl;
    reverseSequenceOfIntegers(stack);
    return 0;
}

/*
 * Function: reverseSequenceOfIntegers
 * Usage: reverseSequenceOfIntegers(stack);
 * ----------------------------------------
 * If the stack is non-empty, pop the top element of the stack
 */
void reverseSequenceOfIntegers(Stack<int> &stack)
{
    while(!stack.isEmpty())
    {
        cout << right << setw(5) << stack.pop() << endl;
    }
}
