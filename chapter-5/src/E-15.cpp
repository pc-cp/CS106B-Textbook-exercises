
/*
 * File:E-15.cpp
 * -------------
 * implements the roll(n, k) operation on the specified stack.
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
void roll(Stack<char> & stack, int n, int k);
/* Main function */
int main(void)
{
    Stack<char> stack;
    cout << "Input your elements for stack, ending with 0:" << endl;
    while(true)
    {
        string str;
        getline(cin, str);
        if(str[0] == '0') break;
        stack.push(str[0]);
    }
    // cout << stack.size() << endl;
    cout << "Input the number of n and k:";
    int n, k;
    cin >> n >> k;
    roll(stack, n, k);
    // cout << "--------" << endl;
    // cout << stack.size() << endl;
    while(!stack.isEmpty())
    {
        cout << stack.pop() << endl;
    }
    return 0;
}

void roll(Stack<char> & stack, int n, int k)
{
    if(n < 0 || k < 0 || n > stack.size())
        error("roll: argument out of range");

    Stack<char> temp;
    for(int i = 0; i < k; ++i)
    {
        char topStackElement = stack.peek();
        for(int j = 0; j < n; ++j)
        {
            if(j == 0) stack.pop();
            else temp.push(stack.pop());
        }
        for(int j = 0; j < n; ++j)
        {
            if(j == 0) stack.push(topStackElement);
            else stack.push(temp.pop());
        }
    }
}
