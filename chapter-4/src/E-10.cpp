
/*
 * File: E-10.cpp
 * --------------
 * replaces tabs in an input file with the number of spaces
 * required to reach the next tab stop.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
// #include "random.h"
using namespace std;

const int TAB_STOP_LENGHTS  = 8;
/* Function prototypes */
string promptUserForFile(ifstream &infile, string prompt="");
string promptUserForFile(ofstream &outfile, string prompt="");
void substituteTabToSpace(istream & is, ostream & os);

/* Main function */
int main(void)
{
    ifstream infile;
    ofstream outfile;

    promptUserForFile(infile, "Input file to read: ");
    promptUserForFile(outfile, "Input file to write: ");

    // outfile << "0123456789000000000000000" << endl;
    // outfile << "\tbar"<< endl;
    // outfile << "foo\tbar" << endl;
    // outfile << "0123456789000000000000000" << endl;
    // outfile << "longerfoo\tbar" << endl;
    substituteTabToSpace(infile, outfile);
    infile.close();
    outfile.close();
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
 * Function: substituteTabToSpace
 * Usage: substituteTabToSpace(is, os);
 * ------------------------------------
 * Read in each character one by one, if the current character
 * is '\t' then calculate the position pos in the line where
 * it is located, and then determine the corresponding tabStop, the
 * Replace [pos, posTabStop) with a space
 * https://stackoverflow.com/questions/13094690/how-many-spaces-for-tab-character-t
 */
void substituteTabToSpace(istream & is, ostream & os)
{
    int ch, pos = -1, tapStop = -1;

    while((ch = is.get()) != EOF)
    {
        pos++;
        if(ch == '\t')
        {
            tapStop = (pos + TAB_STOP_LENGHTS) / TAB_STOP_LENGHTS * TAB_STOP_LENGHTS;
            for(int i = 0; i < tapStop-pos; ++i)
                os << ' ';
        }
        else if(ch == '\n')
        {
            pos = -1;
            os << char(ch);
        }
        else
            os << char(ch);
    }
}
