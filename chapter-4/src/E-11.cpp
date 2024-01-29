
/*
 * File: E-11.cpp
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
string promptUserForFile(ifstream &infile, string prompt="");
string promptUserForFile(ofstream &outfile, string prompt="");
double stringToReal(string str);
string realToString(double real);

/* Main function */
int main(void)
{
    string str = "   11234.22  ";
    // cout << "Input your string: ";
    // getline(cin, str);
    cout << setw(15) << "real + real: " << stringToReal(str) * 2 << endl;
    cout << setw(15) << "str + str: " << realToString(stringToReal(str)) + realToString(stringToReal(str)) << endl;

    cout << "Task finished!" << endl;
    return 0;
}

/*
 * Function: promptUserForFile
 * Usage: string filename = promptUserForFile(infile, prompt);
 * -----------------------------------------------------------
 * Asks the user for the name of an input file and opens the reference
 * parameter infile that name, which is returned as the result of
 * the function. If the requested file does not exist, the user is
 * given additional chances to enter a valid file name. The optional
 * prompt argumnet is used to give the user more information about the
 * desired input file.
 */

string promptUserForFile(ifstream &infile, string prompt)
{
    while(true)
    {
        cout << prompt;
        string filename;
        getline(cin, filename);
        infile.open(filename.c_str());
        if(!infile.fail()) return filename;
        infile.clear();
        cout << "Unable to open that file. Try again." << endl;
        if(prompt == "") prompt = "Input file: ";
    }
}


string promptUserForFile(ofstream &outfile, string prompt)
{
    while(true)
    {
        cout << prompt;
        string filename;
        getline(cin, filename);
        outfile.open(filename.c_str());
        if(!outfile.fail()) return filename;
        outfile.clear();
        cout << "Unable to open that file. Try again." << endl;
        if(prompt == "") prompt = "Input file: ";
    }
}

/*
 * Function: stringToReal
 * Usage: doubel real = stringToReal(str);
 * ---------------------------------------
 * follow stringToInteger(string str) in pp.178
 */
double stringToReal(string str)
{
    istringstream stream(str);
    double value;
    stream >> value >> ws;
    if(stream.fail() || !stream.eof())
    {
        cout << "stringToReal: Illegal integer format." << endl;
        exit(EXIT_FAILURE);
    }
    return value;
}

/*
 * Function: realToString
 * Usage: string str = realToString(real);
 * ---------------------------------------
 * follow integerToString(int value) in pp.179
 */
string realToString(double real)
{
    ostringstream stream;
    stream << real;
    return stream.str();
}

