
/*
 * File:E-3.cpp
 * -----------------------
 * returns the standard deviation of the data distribution.
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
using namespace std;

/* Function prototype*/
void readVector(istream &is, Vector<double> &vec);
void displayVector(Vector<double> vec);
double mean(Vector<double> &data);
double stddev(Vector<double> & data);

/* Main function */
int main(void)
{
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    Vector<double> vec;
    readVector(infile, vec);
    displayVector(vec);
    infile.close();
    double std = stddev(vec);
    cout << "The std of the above collection is: " << fixed << setw(9) << setprecision(4) << std << endl;
    return 0;
}

/* Function: stddev
 * Usage: double std = stddev(data);
 * ---------------------------------
 * Using a temporary variable std, first get the sigma,
 * then divide by the number of elements in the set at the end of the traversal,
 * finally use sqrt function.
 */
double stddev(Vector<double> & data)
{
    double ave = mean(data);
    double std = 0;
    for(double value: data)
    {
        std += pow(ave-value, 2);
    }

    return sqrt(std/data.size());
}

/*
 * Function: mean
 * Usage: double ave = mean(data);
 * -------------------------------
 * Using a temporary variable ave, first get the sum of the set,
 * then divide by the number of elements in the set at the end of the traversal.
 */
double mean(Vector<double> &data)
{
    double ave = 0;
    for(double value: data)
        ave += value;
    return ave/data.size();
}

void displayVector(Vector<double> vec)
{
    for(double value : vec)
        cout << right << fixed << setw(9) << setprecision(4) << value << endl;
    cout << endl;
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

