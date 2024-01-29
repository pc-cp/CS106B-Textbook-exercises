
/*
 * File: E-3.cpp
 * -------------
 * prints the longest line in a file chosen by the user
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* Function prototypes */
string promptUserForFile(ifstream &infile, string prompt="");
string printLongestLine(ifstream &infile);

/* Main function */
int main(void)
{
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    cout << "longest line in file is: " << printLongestLine(infile) << endl;
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
 * Function: printLongestLine
 * Usage: string longestLine = printLongestLine(infile);
 * -----------------------------------------------------
 * Returns the content of the longest line in the file,
 * or the first longest line if there are multiple lines that are the longest.
 * Use a string variable ans to record the longest line so far, and update ans
 * if there is a line below it that is longer than it.
 */
string printLongestLine(ifstream &infile)
{
    string ans = "";
    string line;
    while(getline(infile, line))
    {
        if(line.length() > ans.length()) ans = line;
    }
    return ans;
}
