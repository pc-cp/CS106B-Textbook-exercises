
/*
 * File: ReverseFile.cpp
 * ---------------------
 * This program displays the lines of an input file in reverse order.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "filelib.h"
#include "vector.h"
using namespace std;

/* Main program */

int main()
{
    ifstream infile;
    Vector<string> lines;
    promptUserForFile(infile, "Input file: ");
    readEntireFile(infile, lines);
    infile.close();
    for (int i = lines.size() - 1; i >= 0; i--)
    {
        cout << lines[i] << endl;
    }
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

// string promptUserForFile(ifstream &infile, string prompt)
// {
//     while(true)
//     {
//         cout << prompt;
//         string filename;
//         // getline(cin, filename);
//         cin >> filename;
//         infile.open(filename.c_str());
//         if(!infile.fail()) return filename;
//         infile.clear();
//         cout << "Unable to open that file. Try again." << endl;
//         if(prompt == "") prompt = "Input file: ";
//     }

// }


// void readEntireFile(istream &is, vector<string> &lines)
// {
//     string line;
//     while(getline(is, line))
//     {
//         lines.push_back(line);
//     }
// }
