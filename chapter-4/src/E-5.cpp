
/*
 * File: E-5.cpp
 * -------------
 * reads a file and reports how many lines, words, and characters appear in it.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

/* Function prototypes */
string getRoot(string filename);
string getExtension(string filename);

/* Main function */
int main(void)
{
    string filename;
    cout << "Input filename: ";
    getline(cin, filename);
    cout << setw(15) << "Root: " << getRoot(filename) << endl;
    cout << setw(15) << "Extension: " << getExtension(filename) << endl;
    return 0;
}

/*
 * Function: getRoot
 * Usage: string root = getRoot(filename);
 * --------------------------------------------
 * Look for "." ,
 *      If it exists, root is filename.substr(0, dotPositions);
 *      If it doesn't exist, root is filename.
 */
string getRoot(string filename)
{
    int pos = filename.find(".");
    if(pos == std::string::npos)
        return filename;
    else
        return filename.substr(0, pos);
}

/*
 * Function: getExtension
 * Usage: string extension = getExtension(filename);
 * --------------------------------------------
 * Look for "." ,
 *      If it exists, the extension is filename.substr(dotPositions);
 *      If it doesn't exist then extension is ""
 */
string getExtension(string filename)
{
    string extension = "Not Exist!";
    int pos = filename.find(".");
    if(pos != std::string::npos)
        extension = filename.substr(pos);
    return extension;
}
