
/*
 * File:E-1.cpp
 * -----------------------
 * Write the overloaded functions
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include "filelib.h"
#include "strlib.h"
#include "vector.h"
using namespace std;

/* Function prototype*/

void readVector(istream &is, Vector<int> &vec);
void readVector(istream &is, Vector<double> &vec);
void readVector(istream &is, Vector<string> &vec);
// void displayVector(Vector<int> vec);
void displayVector(Vector<double> vec);
// void displayVector(Vector<string> vec);

/* Main function */
int main(void)
{
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    Vector<double> vec;
    readVector(infile, vec);
    displayVector(vec);
    readVector(infile, vec);
    displayVector(vec);
    readVector(infile, vec);
    displayVector(vec);
    infile.close();
    displayVector(vec);
    return 0;
}

void displayVector(Vector<double> vec)
{
    for(double value : vec)
        cout << right << fixed << setw(9) << setprecision(4) << value << endl;
    cout << endl;
}

void readVector(istream &is, Vector<int> &vec)
{
    vec.clear();
    string line;
    while(getline(is, line))
    {
        if(line == "")
            break;
        vec.add(stringToInteger(line));
    }
}
void readVector(istream &is, Vector<double> &vec)
{
    vec.clear();
    string line;
    while(getline(is, line))
    {
        if(line == "")
            break;
        vec.add(stringToDouble(line));
    }
}
void readVector(istream &is, Vector<string> &vec)
{
    {
        vec.clear();
        string line;
        while(getline(is, line))
        {
            if(line == "")
                break;
            vec.add(line);
        }
    }
}
