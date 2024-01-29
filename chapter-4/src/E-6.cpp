
/*
 * File: E-6.cpp
 * -------------
 * Write the code for defaultExtension
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

/* Function prototypes */
string getRoot(string filename);
string getExtension(string filename);
string defaultExtension(string filename, string ext);

/* Main function */
int main(void)
{
    string filename, ext;
    cout << "Input filename: ";
    getline(cin, filename);
    cout << "Input extension: ";
    getline(cin, ext);

    cout << defaultExtension(filename, ext) << endl;
    return 0;
}

/*
 * Function: defaultExtension
 * Usage: string afterFilename = defaultExtension(filename, ext)
 * -------------------------------------------------------------
 * which adds ext to the end of filename if it doesn’t already have an extension.
 * If filename already has an extension, that name is returned unchanged.
 * ext includes a star before the dot, defaultExtension removes any existing
 * extension from filename and adds the new one (minus the star).
 */

string defaultExtension(string filename, string ext)
{
    int starPosition = ext.find("*");
    if(starPosition != std::string::npos)
    {
        string root = getRoot(filename);
        string extension = getExtension(ext);
        return root + extension;
    }
    else
    {
        int dotPosition = filename.find(".");
        if(dotPosition == std::string::npos)
        {
            string root = getRoot(filename);
            string extension = getExtension(ext);
            return root + extension;
        }
        else
            return filename;
    }

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
    string extension = "";
    int pos = filename.find(".");
    if(pos != std::string::npos)
        extension = filename.substr(pos);
    return extension;
}
