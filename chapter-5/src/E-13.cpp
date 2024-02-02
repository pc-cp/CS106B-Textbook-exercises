
/*
 * File:E-13.cpp
 * -------------
 * reverses the elements in the queue.
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
#include "queue.h"

using namespace std;


/* Function prototype*/
void reverseSequenceOfIntegers(Queue<int> &queue);
/* Main function */
int main(void)
{
    Queue<int> queue;
    cout << "Enter a list of integers, ending with 0: " << endl;
    int value;
    while(true)
    {
        cout << "? ";
        cin >> value;
        if(value == 0) break;
        queue.enqueue(value);
    }

    cout << "Those integers in reverse order are: " << endl;
    reverseSequenceOfIntegers(queue);
    return 0;
}

/*
 * Function: reverseSequenceOfIntegers
 * Usage: reverseSequenceOfIntegers(queue);
 * ----------------------------------------
 * If the queue contains elements,
 * the head element is put into the stack and then the elements
 * in the stack are taken out of the stack
 */
void reverseSequenceOfIntegers(Queue<int> &queue)
{
    Stack<int> stack;
    while(!queue.isEmpty())
    {
        stack.push(queue.dequeue());
    }
    while(!stack.isEmpty())
    {
        cout << stack.pop() << endl;
    }
}
