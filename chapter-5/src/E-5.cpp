
/*
 * File:E-5.cpp(hist.h)
 * ------------
 * Extend the flexibility of the previous exercise by defining a hist.h interface that gives clients more control over the format of the histogram.
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
void displayHistograms(int min_element, int max_element, Vector<int> &data);

/* Main function */
// int main(void)
// {
//     ifstream infile;
//     promptUserForFile(infile, "Input file: ");
//     Vector<int> vec;
//     readVector(infile, vec);
//     displayVector(vec);
//     infile.close();
//     displayHistograms(20, 80, vec);

//     return 0;
// }

void displayHistograms(int min_element, int max_element, Vector<int> &data)
{
    Vector<string> keys;
    for(int value = min_element; value <= max_element; value += 10)
        keys.add(integerToString(value / 10) + "0s");

    Map<string, int> histogram;
    for(string key: keys)
        histogram[key] = 0;

    for(int value: data)
    {
        if(value <= min_element || value > max_element) continue;
        string prefix = integerToString(value / 10) + "0s";
        histogram[prefix] ++;
    }

    for(string key : keys)
    {
        // if(key == "") continue;
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
