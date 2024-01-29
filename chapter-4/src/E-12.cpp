
/*
 * File: E-12.cpp
 * --------------
 * write the code necessary to implement stringToReal and realToString.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
// #include "error.h"
// #include "random.h"
using namespace std;


/* Function prototypes */
int getInteger(string prompt);
double getReal(string prompt);
string getLine(string prompt);

/* Main function */
int main(void)
{
    // int value_i = getInteger("input your value(integer): ");
    // cout << "value_i: " << value_i << endl;
    // double value_d = getReal("input your value(floating): ");
    // cout << "value_d: " << value_d << endl;
    string value_s = getLine("input your value(string): ");
    cout << "value_s: " << value_s << endl;

    cout << "Task finished!" << endl;
    return 0;
}

/*
 * Function: getInteger
 * Usage: int n = getInteger(prompt);
 * ----------------------------------
 * Requests an integer value from the user. The function begins by
 * printint the prompt string on the console and then waits for the
 * user to enter a line of input data. If that line contains a
 * single integer, the function returns the corresponding integer
 * value. If the input is not a legal integer or if extraneous
 * characters (other than whitespace) appear on the input line,
 * the implementation gives the user a chance to reenter the value.
 */

int getInteger(string prompt)
{
    int value;
    string line;
    while(true)
    {
        cout << prompt;
        getline(cin, line);
        istringstream stream(line);
        // stream >> std::noskipws;
        stream >> value >> ws;
        // if(!stream.fail() && stream.eof()) break;
        if(stream.eof()) break;
        cout << "Illegal integer format. Try again." << endl;
    }
    return value;
}

/*
 * Function: getReal
 * Usage: double x = getReal(prompt);
 * ----------------------------------
 * Reads a complete line from cin and scans it as a floating-point numbers. If the scan succeeds, the
 * floating-point value is returned. If the input is not a legal number or if extraneous character (other
 * than  whitespace) appear in the string, the user is given a chance to reenter the value. If supplied, the
 * optional prompt string is printed before reading the value.
 */
double getReal(string prompt)
{
    double value = 0.0;
    string line;
    while(true)
    {
        cout << prompt;
        getline(cin, line);
        istringstream stream(line);
        stream >> value;
        // cout << value << endl;
        // cout << stream.fail() << endl;
        // cout << stream.eof() << endl;
        if(!stream.fail() && stream.eof()) break;
        cout << "Illegal real format. Try again." << endl;
    }
    return value;
}
/* Function: getLine
 * Usage: string line = getLine(prompt);
 * -------------------------------------
 * Reads a line of text from cin and returns that line as a string. The newline character that terminates the
 * input is not stored as part of the return value. If supplied, the optional prompt string is printed before
 * reading the value.
 */
string getLine(string prompt)
{
    string line;
    while(true)
    {
        cout << prompt;
        if(getline(cin, line)) break;
        cout << "Illegal string format. Try again." << endl;
    }
    return line;
}
