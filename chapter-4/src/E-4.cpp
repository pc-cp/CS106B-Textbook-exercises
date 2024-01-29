
/*
 * File: E-4.cpp
 * -------------
 * reads a file and reports how many lines, words, and characters appear in it.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

/* Function prototypes */
string promptUserForFile(ifstream &infile, string prompt="");
void printLinesWordsCharacters(ifstream &infile);

/* Main function */
int main(void)
{
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    printLinesWordsCharacters(infile);
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
 * Usage: printLinesWordsCharacters(infile);
 * -----------------------------------------
 * In order to count how many characters and words,
 * it is necessary to use character by character to read the content of the file,
 * how many lines, and directly count the newline characters.
 */
void printLinesWordsCharacters(ifstream &infile)
{
    int characters = 0, words = 0, lines = 0;
    int start = -1, pos = -1;
    int ch;
    while((ch = infile.get()) != EOF)
    {
        characters ++;
        pos++;
        // if(isalnum(ch))
        if(!isspace(ch))
        {
            if(start == -1) start = pos;
        }
        else
        {
            if(start >= 0)
            {
                words ++ ;
                start = -1;
            }
            if(ch == '\n')
                lines ++;
        }
    }
    cout << "Chars: " << setw(10) << characters << endl;
    cout << "Words: " << setw(10) << words << endl;
    cout << "Lines: " << setw(10) << lines << endl;
}
