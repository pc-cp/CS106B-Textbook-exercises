/*
 * File: E-9.cpp
 * -------------
 * Write a program that asks the user for an input file,
 * an output file, and a string of letters to be eliminated.
 * The program should then copy the input file to the output file,
 * deleting any of the letters that appear in the string of censored letters,
 * no matter whether they appear in uppercase or lowercase form.
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
string promptUserForFile(ofstream &outfile, string prompt="");
void removeCensoredLetters(istream & is, ostream & os, string censored);

/* Main function */
int main(void)
{
    ifstream infile;
    ofstream outfile;
    string censored;
    promptUserForFile(infile, "Input file to read: ");
    promptUserForFile(outfile, "Input file to write: ");
    cout << "Input a string of letters to be eliminated: ";
    getline(cin, censored);

    removeCensoredLetters(infile, outfile, censored);

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
 * Function: removeCensoredLetters
 * Usage: removeCensoredLetters(is, os, censored);
 * -----------------------------------
 * Convert the censored string to lowercase first, so that it will be looked up aspect-wise.
 * For each character ch read from is, a lookup is performed in censored
 * and if the lookup is successful, it is not output, otherwise it is output to os.
 */

void removeCensoredLetters(istream & is, ostream & os, string censored)
{
    for(int i = 0; i < censored.length(); ++i)
        censored[i] = tolower(censored[i]);

    int ch;
    while((ch = is.get()) != EOF)
    {
        if(isalpha(char(ch)) && censored.find(tolower(ch)) != std::string::npos)
            continue;
        os.put(ch);
    }

}
