
/*
 * File: E-7.cpp
 * -------------
 * Write a program that reads characters from an input file
 * and displays them on the console after making the appropriate random substitutions.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "random.h"
using namespace std;

const int ALPHA_NUMBER = 26;
/* Function prototypes */
string promptUserForFile(ifstream &infile, string prompt="");
void randomSubstitutions(ifstream &infile);

/* Main function */
int main(void)
{
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    randomSubstitutions(infile);
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

/*
 * Function: randomSubstitutions
 * Usage: randomSubstitutions(infile);
 * -----------------------------------
 * replace every uppercase character in the input
 * by a random uppercase character and every lowercase character
 * by a random lowercase one. Nonalphabetic characters should remain unchanged.
 */
void randomSubstitutions(ifstream &infile)
{
    int ch;
    char start;
    while((ch = infile.get()) != EOF)
    {
        if(isalpha(ch))
        {
            if(ch >= 'A' && ch <= 'Z')
                start = 'A';
            else
                start = 'a';
            ch = (ch - start + randomInteger(0, ALPHA_NUMBER-1))%ALPHA_NUMBER + start;
        }
        cout << char(ch);
    }

}
