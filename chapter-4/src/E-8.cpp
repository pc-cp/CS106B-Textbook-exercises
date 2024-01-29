
/*
 * File: E-8.cpp
 * -------------
 * recognize and eliminate comments that occur in a source file
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
// #include "random.h"
using namespace std;

/* Function prototypes */
string promptUserForFile(ifstream &infile, string prompt="");
string promptUserForFile(ofstream &infile, string prompt="");
void removeComments(istream & is, ostream & os);

/* Main function */
int main(void)
{
    ifstream infile;
    ofstream outfile;
    promptUserForFile(infile, "Input file to read: ");
    promptUserForFile(outfile, "Input file to write: ");

    removeComments(infile, outfile);

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
 * Function: removeComments
 * Usage: removeComments(is, os);
 * -----------------------------------
 * recognize and eliminate comments (/ * ... and // ) that occur in a source file
 * 1. / *
 * 2. //
 */

void removeComments(istream & is, ostream & os)
{
    bool inComments = false;
    string line;
    while(getline(is, line))
    {
        int firstCommentsPosition_start = line.find("/*");
        int firstCommentsPosition_end = line.find("*/");
        int secondCommentsPosition = line.find("//");
        if(firstCommentsPosition_start != std::string::npos && firstCommentsPosition_end != std::string::npos && !inComments)
            os << line.substr(0, firstCommentsPosition_start) << line.substr(firstCommentsPosition_end+2) << endl;
        else if(firstCommentsPosition_start != std::string::npos && !inComments)
        {
            os << line.substr(0, firstCommentsPosition_start) << endl;
            inComments = true;
        }
        else if(firstCommentsPosition_end != std::string::npos && inComments)
        {
            os << line.substr(firstCommentsPosition_end + 2) << endl;
            inComments = false;
        }
        else if(!inComments && secondCommentsPosition != std::string::npos)
        {
            os << line.substr(0, secondCommentsPosition) << endl;
        }
        else if(!inComments)
            os << line << endl;
    }
}
