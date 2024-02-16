

/*
 * File: E-7-10.cpp
 * Write a recursive function that
 * takes a string as argument and
 * returns the reverse of that string.
 */
#include <iostream>
#include <string>

using namespace std;

/* Function prototype */
string reverse(string str);

int main(void)
{
    cout << reverse("program") << endl;
    return 0;
}
/*
 * Function: reverse
 * Usage: string str = reverse("program");
 * ---------------------------------------
 * Write a recursive function that
 * takes a string as argument and returns the reverse of that string.
 */
string reverse(string str)
{
    int len = str.length();
    if(len == 0) return string("");
    else return str[len-1] + reverse(str.substr(0, len-1));
}
