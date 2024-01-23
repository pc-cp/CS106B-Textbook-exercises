
/*
 * File: E-12.cpp
 * --------------
 * returns the plural of word formed by following these standard English rules
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "error.h"
using namespace std;


/* 函数原型 */
string createRegularPlural(string word);

/* 主函数 */
int main(void)
{

    cout << createRegularPlural("City") << endl;
    cout << createRegularPlural("Day") << endl;
    cout << createRegularPlural("apple") << endl;
    return 0;
}


/*
 * 函数名： createRegularPlural(word)
 * 使用方式： string newStr = createRegularPlural(word);
 * ------------------------------------------------------------
 * 实现方式：首先确定word的长度必须大于等于2，否则直接返回。然后截取倒数后面两个字串进行规则的匹配
 * 1. 最后一个字母为's', 'x', 'z' 则直接加上"es"返回
 * 2. 该字串为"ch, sh"，则同1
 * 3. 若最后一个字母为y，且倒数第二个字母不为'a', 'e', 'i', 'o', 'u'中的一个，则将'y'变成"ies"。
 * 4. 若上述情况都不满足的话，直接加's'即可。
 */
string createRegularPlural(string word)
{
    if(word.length() == 1) return word;
    string newStr = word.substr(word.length()-1-1, 2);
    // cout << newStr << endl;
    if(newStr[1] == 's' || newStr[1] == 'x' || newStr[1] == 'z' || newStr == "ch" || newStr == "sh")
        return word + "es";
    else if(newStr[1] == 'y' && newStr[0] != 'a' && newStr[0] != 'e' && newStr[0] != 'i' && newStr[0] != 'o' && newStr[0] != 'u')
        return word.substr(0, word.length()-1) + "ies";
    else
        return word + 's';
}
