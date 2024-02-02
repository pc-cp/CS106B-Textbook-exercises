
/*
 * File: E-19_2.cpp
 * ----------------------
 * list the geographical locations of each area code in a data file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "error.h"
#include "map.h"
#include "strlib.h"

using namespace std;

/* Function prototype */
void readCodeFile(string filename, Map<string, string> &map);

/* Main function */
int main(void)
{
    Map<string, string> areaCodes;
    readCodeFile("AreaCodes.txt", areaCodes);

    while(true)
    {
        string input;
        cout << "Enter area code or state name: ";
        getline(cin, input);
        if(input == "") break;

        if(isdigit(input[0]))
        {
            if(areaCodes.containsKey(input))
            {
                cout << areaCodes.get(input) << endl;
            }
            else
            {
                cout << "There is no such state code" << endl;
            }
        }
        else if(isalpha(input[0]))
        {
            bool exist = false;
            for(string code: areaCodes)
            {
                if(areaCodes[code] == input)
                {
                    cout << code << endl;
                    exist = true;
                }
            }
            if(!exist)
            {
                cout << "There is no such state code" << endl;
            }
        }
    }
    return 0;
}

void readCodeFile(string filename, Map<string, string> &map)
{
    ifstream infile;
    infile.open(filename.c_str());
    if(infile.fail()) error("Can't read the data file");
    string line;
    while(getline(infile, line))
    {
        if(line.length() < 4 || line[3] != '-')
            error("Illegal data line: " + line);
        string code = line.substr(0, 3);
        map.put(code, line.substr(4));
    }
    infile.close();
}
