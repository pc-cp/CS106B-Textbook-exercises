
/*
 * File:E-4.cpp
 * -----------------------
 * Write a program that reads in a vector of integers from a data file
 * and then displays a histogram of those numbers, divided into
 * the ranges 0–9, 10–19, 20–29, and so forth,
 * up to the range containing only the value 100.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
#include "filelib.h"
#include "strlib.h"
#include "vector.h"
#include "map.h"
#include "error.h"
using namespace std;

/* Function prototype*/
void readVector(istream &is, Vector<int> &vec);
void displayVector(Vector<int> vec);
void displayHistograms(Vector<int> vec);

/* Main function */
int main(void)
{
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    Vector<int> vec;
    readVector(infile, vec);
    // displayVector(vec);
    infile.close();
    displayHistograms(vec);

    return 0;
}

void displayHistograms(Vector<int> vec)
{
    Vector<string> keys = {"00s", "10s", "20s", "30s", "40s", "50s", "60s", "70s", "80s", "90s", "100"};
    Map<string, int> histogram;
    for(string key: keys)
        histogram[key] = 0;

    for(int value: vec)
    {
        if(value <= 0 || value > 100) continue;
        switch(value/10)
        {
            case 0:
                histogram["00s"]++;
                break;
            case 1:
                histogram["10s"]++;
                break;
            case 2:
                histogram["20s"]++;
                break;
            case 3:
                histogram["30s"]++;
                break;
            case 4:
                histogram["40s"]++;
                break;
            case 5:
                histogram["50s"]++;
                break;
            case 6:
                histogram["60s"]++;
                break;
            case 7:
                histogram["70s"]++;
                break;
            case 8:
                histogram["80s"]++;
                break;
            case 9:
                histogram["90s"]++;
                break;
            case 10:
                histogram["100"]++;
                break;
            default:
                // cout << value << endl;
                error("error");
                break;
        }
    }
    for(string key : keys)
    {
        cout << left << setw(4) << key << ": ";
        for(int i = 0; i < histogram[key]; ++i)
            cout << "* ";
        cout << endl;
    }
}

void displayVector(Vector<int> vec)
{
    for(int value : vec)
        cout << right << fixed << setw(9) << value << endl;
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



