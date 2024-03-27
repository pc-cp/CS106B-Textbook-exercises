
/* E-11-4.cpp
 * Rewrite the simple expression calculator from Chapter 6, exercise 11,
 * so that both the input and output values are represented in hexadecimal.
 */

#include <iostream>
#include "tokenscanner.h"
#include "simpio.h"

using namespace std;

const string symbolTable = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string integerToString1(int num, int base);
int stringToInteger1(string num, int base);

/* Function prototype */
void applyOperator(char op, Stack<string> &operandStack);

/* Main function */
int main(void)
{

    Stack<string> operandStack;

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
            if(isalnum(token[0]))
            {
                operandStack.push((token));
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
        string result = operandStack.peek();
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
void applyOperator(char op, Stack<string> &operandStack)
{
    int result;
    int rhs = stringToInteger1(operandStack.pop(), 16);
    int lhs = stringToInteger1(operandStack.pop(), 16);
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
    operandStack.push(integerToString1(result, 16));
}

string integerToString1(int num, int base) {
    unsigned int internalBitPattern = (unsigned int)num;
    string result = "";

    while(internalBitPattern) {
        char currentSymbol = symbolTable[internalBitPattern % base];
        result = currentSymbol + result;
        internalBitPattern /= base;
    }
    return result;
}
int stringToInteger1(string num, int base) {
    int result = 0;

    int P = 1;
    for(int i = num.size()-1; i >= 0; i--) {
        int index = symbolTable.find(num[i]);
        if(index >= base) {
            error("the digits is out of range for the specified base.");
        }
        result += P * index;
        P *= base;
    }
    return result;
}
