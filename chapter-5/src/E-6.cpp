
/*
 * File:E-6.cpp
 * ------------
 * Write a program that uses the sieve of Eratosthenes
 * to generate a list of the primes between 2 and 1000.
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
#include "set.h"
#include "error.h"
using namespace std;

/* Function prototype*/
Set<int> generatePrime(int start, int end);
/* Main function */
int main(void)
{
    Set<int> primes = generatePrime(2, 1000);

    for(int prime: primes)
        cout << right << setw(5) << prime << endl;
    return 0;
}


Set<int> generatePrime(int start, int end)
{
    Set<int> datas, datasCopy, primes;
    for(int i = start; i <= end; ++i)
    {
        datas.add(i);
        datasCopy.add(i);
    }

    for(int value: datas)
    {
        if(!datasCopy.contains(value)) continue;
        primes.add(value);
        for(int times = 2; times <= end/value; ++times)
            datasCopy.remove(times * value);
    }
    return primes;
}
