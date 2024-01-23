
/*
 * File: E-1.cpp
 * -------------
 * Implement the function endsWith(str, suffix),
 * which returns true if str ends with suffix.
 */

#include <iostream>
#include <string>

using namespace std;

/* Function Prototype */
bool endWith(string str, string suffix);
bool endWith(string str, char suffix);


int main(void)
{
    if(endWith("abcde", 'e'))
        puts("Yes");
    else
        puts("No");
    return 0;
}

/*
 * Function: endWith(string str, string subffix)
 * Usage: if(endWith(str, string))
 *              ......
 * ---------------------------------------------
 * Implement the function endsWith(str, suffix),
 * which returns true if str ends with suffix.
 */
bool endWith(string str, string suffix)
{
    if(str.length() < suffix.length()) return false;
    for(int i = 0; i < suffix.length(); ++i)
    {
        if(str[str.length()-suffix.length()+i] != suffix[i]) return false;
    }
    return true;
}


bool endWith(string str, char suffix)
{
    string substr = "";
    substr += suffix;
    // cout << substr << endl;
    return endWith(str, substr);
}
