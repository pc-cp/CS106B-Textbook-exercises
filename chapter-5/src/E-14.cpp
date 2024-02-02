
/*
 * File:E-14.cpp
 * -------------
 * Write a program that checks whether the bracketing
 * operators (parentheses, brackets, and curly braces) in a string are properly matched.
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
bool checkBracketMatch(string input);
/* Main function */
int main(void)
{
    string line;
    cout << "Input your string: ";
    getline(cin, line);

    if(checkBracketMatch(line))
        cout << "Match. " << endl;
    else
        cout << "Not Match. " << endl;

    return 0;
}

/*
 * Function: checkBracketMatch
 * Usage: if(checkBracketMatch(input))
 *              ...
 * -----------------------------------
 * Use stack to check for matches of parentheses in a sequence,
 * when the current character ch is '{'/'('/'[',
 * then into the stack when the current character ch is '}'/')'/']',
 * then match with the top element of the stack
 *      i.e. { ---- }
 *           ( ---- )
 *           [ ---- ]
 * If the match is successful,
 * the current element will be out of the stack and the next element
 * will continue, and vice versa will be false.
 */
bool checkBracketMatch(string input)
{
    Map<char, int> openBrackets;
    openBrackets['{'] = 0;
    openBrackets['['] = 1;
    openBrackets['('] = 2;
    Map<char, int> closeBrackets;
    closeBrackets['}'] = 0;
    closeBrackets[']'] = 1;
    closeBrackets[')'] = 2;

    Stack<char> stack;
    for(char ch : input)
    {
        if(openBrackets.containsKey(ch))
        {
            stack.push(ch);
        }
        else if(closeBrackets.containsKey(ch))
        {
            if(stack.isEmpty()) return false;
            char topStackElement = stack.pop();
            if(openBrackets[topStackElement] != closeBrackets[ch])
                return false;
        }
    }
    if(!stack.isEmpty()) return false;
    return true;
}
