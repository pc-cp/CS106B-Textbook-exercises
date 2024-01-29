/*
 * File: E-2.cpp
 * Usage: double chill = windChill(t, v);
 * ----------------------------------------------
 * a function windChill that takes the values of t and v and returns the wind chill.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

const int WIND_START = 0;
const int WIND_END = 60;
const int TEMPERATURE_START = 40;
const int TEMPERATURE_END = -45;

/* Function prototype */
void printWindChillTable();
int windChill(int t, int v);
void error(string msg);

/* Main program */
int main(void)
{
    printWindChillTable();
    return 0;
}

int windChill(int t, int v)
{
    if(v == 0)
        return t;
    if(t > 40)
    {
        error("If the temperature is greater than 40°F, the wind chill is undefined.");
    }
    return int(35.74 + 0.6215 * t - 35.75 * pow(v, 0.16) + 0.4275 * t * pow(v, 0.16));
}

void printWindChillTable()
{
    for(int wind = WIND_START; wind <= WIND_END; wind += 5)
    {
        if(wind == WIND_START)
            cout << "Calm " << " ";
        else
            cout << setw(3) << wind << "   ";

        for(int temperature = TEMPERATURE_START; temperature >= TEMPERATURE_END; temperature -= 5)
        {
            cout << setw(5) << windChill(temperature, wind) << " ";
        }
        cout << endl;
    }
}

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}
