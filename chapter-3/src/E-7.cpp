
/*
 * File: E-7.cpp
 * -------------
 * returns a new string consisting of the characters in str after removing all instances of the characters in remove.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "error.h"
using namespace std;


/* 函数原型 */
string removeCharacters(string str, string remove);

/* 主函数 */
int main(void)
{
    string str = "cntrrvltnrs";
    cout << removeCharacters(str, "aeiou");
    return 0;
}


/*
 * 函数名： removeCharacters(string str, string remove);
 * 使用方式： string newStr = removeCharacters(str, remove);
 * -------------------------------------------------------
 * 使用一个新的string类型，遍历整个str，若str[i]在remove里面(find函数)，则
 * 忽视str[i]，反之将str[i]加入新的string中，最后返回新的string。
 */

string removeCharacters(string str, string remove)
{
    string ans;
    for(int i = 0; i < str.length(); ++i)
    {
        if(remove.find(str[i]) == std::string::npos)
            ans += str[i];
    }
    return ans;
}
