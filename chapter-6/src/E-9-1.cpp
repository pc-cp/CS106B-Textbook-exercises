
/*
 * E-9.cpp
 * -------
 * Reimplement the RPN calculator from Figure 5-4 so 
 * that it performs its internal calculations using 
 * rational instead of floating-point numbers.
 */

#include <iostream>
#include <cctype>
#include <string>
#include "error.h"
#include "simpio.h"
#include "stack.h"
#include "strlib.h"
#include "rational.h"
using namespace std;

/* Function prototype */
void applyOperator(char op, Stack<Rational> &operandStack);
void helpCommand();

/* Main program */
int main(void)
{
    cout << "RPN Calculator Simulation (type H for help)" << endl;
    Stack<Rational> operandStack;

    while(true)
    {
        string line = getLine("> ");
        if(line.length() == 0) line = "Q";
        char ch = toupper(line[0]);

        if(ch == 'Q')
        {
            break;
        }
        else if(ch == 'C')
        {
            operandStack.clear();
        }
        else if(isdigit(ch))
        {
            int num, den;
            if(line.find("/") == string::npos)
            {
                num = stringToInteger(line.substr(0));
                den = 1;
            }
            else
            {
                int positionOfDivisionSign = int(line.find("/"));
                num = stringToInteger(line.substr(0, positionOfDivisionSign));
                den = stringToInteger(line.substr(positionOfDivisionSign+1));
            }
            Rational temp(num, den);
            operandStack.push(temp);
        }
        else
        {
            applyOperator(ch, operandStack);
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
void applyOperator(char op, Stack<Rational> &operandStack)
{
    Rational result;
    Rational rhs = operandStack.pop();
    Rational lhs = operandStack.pop();
    switch(op)
    {
        case '+': result = lhs + rhs; break;
        case '-': result = lhs - rhs; break;
        case '*': result = lhs * rhs; break;
        case '/': result = lhs / rhs; break;
        default: error("Illegal operator");
    }
    cout << result << endl;
    operandStack.push(result);
}


/*
 * Function: helpCommand
 * Usage: helpCommand();
 * ---------------------
 * This function generates a help message for the user.
 */

void helpCommand()
{
    cout << "Enter expressions in Reverse Polish Notation," << endl;
    cout << "in which operators follow the operands to which" << endl;
    cout << "they apply, Each line consists of a number, an" << endl;
    cout << "operator, or one of the following commands: " << endl;
    cout << " Q -- Quit the program" << endl;
    cout << " H -- Display this help message" << endl;
    cout << " C -- Clear the calculator stack" << endl;
}
