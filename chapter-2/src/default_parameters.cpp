/*
 * File: default_parameters.cpp
 * ----------------------------
 * Verify the default parameter mechanism of C++
 */

#include <iostream>
using namespace std;

void formatInColumns(int nColumns = 2);

int main()
{
  formatInColumns();
  return 0;
}

void formatInColumns(int nColumns)
{
  cout << nColumns << endl;
}
