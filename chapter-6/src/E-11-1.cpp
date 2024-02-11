
/*
 * E-11.cpp
 * --------
 * Write a program that implements a simple arithmetic calculator.
 * For each line of input, your program should display the result
 * of applying the operators from left to right.
 */

#include <iostream>
#include <cctype>
#include "stack.h"
#include "tokenscanner.h"
#include "simpio.h"
#include "strlib.h"
#include "error.h"

using namespace std;

/* Function prototype */
void applyOperator(char op, Stack<double> &operandStack);

/* Main function */
int main(void)
{

    Stack<double> operandStack;

    TokenScanner scanner;
    scanner.ignoreWhitespace();

    while(true)
    {
        string line = getLine("> ");
        if(line.length() == 0) break;

        scanner.setInput(line);
        bool readOperator = false;
        operandStack.clear();
        char ch;

        while(scanner.hasMoreTokens())
        {
            string token = scanner.nextToken();
            // cout << "token: " << token << endl;
            if(isnumber(token[0]))
            {
                operandStack.push(stringToDouble(token));
                if(readOperator)
                {
                    applyOperator(ch, operandStack);
                    readOperator = false;
                }
            }
            else
            {
                ch = token[0];
                readOperator = true;
            }
        }
        double result = operandStack.peek();
        cout << result << endl;
    }
    return 0;
}

/*
 * Function: applyOperator
 * Usage: applyOperator(op, operandStack);
 * ---------------------------------------
 * This function applies the operator to the top two elements on
 * the operand stack. Because the elements on the stack are popped in
 * reverse order, the right operand is popped before the left operand.
 */
void applyOperator(char op, Stack<double> &operandStack)
{
    double result;
    double rhs = operandStack.pop();
    double lhs = operandStack.pop();
    // cout << "op : " << op << endl;
    switch(op)
    {
        case '+': result = lhs + rhs; break;
        case '-': result = lhs - rhs; break;
        case '*': result = lhs * rhs; break;
        case '/': result = lhs / rhs; break;
        default: error("Illegal operator");
    }
    // cout << result << endl;
    operandStack.push(result);
}
