
/*
 * E-15.cpp
 * --------
 * finite-state machine,
 */

#include <iostream>
#include <cctype>
#include "stack.h"
#include "map.h"
#include "tokenscanner.h"
#include "simpio.h"
#include "strlib.h"
#include "error.h"

using namespace std;

/* Function prototype */
void applyOperator(char op, Stack<double> &operandStack);
double getRightValueOfAssignment(TokenScanner & scanner, Map<string, double> symbolTable);

/* Main function */
int main(void)
{
    Map<string, double> symbolTable;

    TokenScanner scanner;
    scanner.ignoreWhitespace();
    // scanner.scanStrings();
    scanner.scanNumbers();

    while(true)
    {
        string line = getLine("> ");
        if(line.length() == 0) break;

        scanner.setInput(line);

        bool readOperatorEqual = false;
        if(line.find("=") == string::npos)
            readOperatorEqual = false;
        else
            readOperatorEqual = true;

        if(readOperatorEqual)
        {
            string key = scanner.nextToken();
            scanner.nextToken();        // =
            double value = getRightValueOfAssignment(scanner, symbolTable);
            symbolTable.put(key, value);
        }
        else
        {
            if(isnumber(line[0]))
            {
                double value = getRightValueOfAssignment(scanner, symbolTable);
                cout << value << endl;
            }
            else // get(value)
            {
                string key = scanner.nextToken();
                cout << symbolTable.get(key) << endl;
            }
        }
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

/*
 * Function: getRightValueOfAssignment
 * Usage: double value = getRightValueOfAssignment(scanner, symbolTable);
 * ------------------------------------------
 * Get the result of the expression on the right side
 * of the assignment statement as the value in the symbolTable.
 */
double getRightValueOfAssignment(TokenScanner & scanner, Map<string, double> symbolTable)
{
    Stack<double> operandStack;
    bool readOperator = false;
    char ch;

    while(scanner.hasMoreTokens())
    {
        string token = scanner.nextToken();
        // cout << "token: " << token << endl;
        if(isdigit(token[0]))
        {
            operandStack.push(stringToDouble(token));
            if(readOperator)
            {
                applyOperator(ch, operandStack);
                readOperator = false;
            }
        }
        else if(isalpha(token[0]))
        {
            if(!symbolTable.containsKey(token))
            {
                error("Variables should be assigned before being used.");
            }
            else
            {
                operandStack.push(symbolTable[token]);
                if(readOperator)
                {
                    applyOperator(ch, operandStack);
                    readOperator = false;
                }
            }
        }
        else
        {
            ch = token[0];
            readOperator = true;
        }
    }
    return operandStack.peek();
}
