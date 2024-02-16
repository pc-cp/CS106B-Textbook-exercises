
#include <iostream>

using namespace std;

/* Function prototype */
bool isPalindrome(string str);

int main(void)
{
    string str;
    getline(cin, str);
    if(isPalindrome(str))
        cout << "palindrome" << endl;
    else
        cout << "not palindrome." << endl;
    return 0;
}


/*
 * Function: isPalindrome
 * Usage: if(isPalindrome(str)) . . .
 * ----------------------------------
 * Returns true if str is a palindrome, which is a string that
 * reads the same backwards and forwards. This implementation
 * uses the recursive insight that all strings of length 0 or 1
 * are palindromes and that longer strings are palindromes if
 * their first and last characters match and the remaining substring
 * is a palindrome.
 */

bool isPalindrome(string str)
{
    int len = str.length();
    if(len < 1)
        return true;
    else
        return str[0] == str[len-1] && isPalindrome(str.substr(1, len-2));
}

