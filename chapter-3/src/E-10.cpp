
/*
 * File: E-10.cpp
 * -------------
 * returns a copy of str with every occurrence of c1(s1) replaced by c2(s2).
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "error.h"
using namespace std;


/* 函数原型 */
string replaceAll(string str, char c1, char c2);
string replaceAll(string str, string s1, string s2);

/* 主函数 */
int main(void)
{
    // string str = "commmmmitteeee";

    cout << replaceAll("nannies", 'n', 'd') << endl;
    cout << replaceAll("nannies", "n", "ddd") << endl;
    return 0;
}


/*
 * 函数名： replaceAll(string str, c1, c2)
 * 使用方式： string newStr = replaceAll(str, c1, c2)
 * ------------------------------------------------------------
 * 创建一个新的string 变量 newStr, 遍历str，如果str[i]为c1则将c2加入到newStr中，否则只需将str[i]将入newStr即可
 */

string replaceAll(string str, char c1, char c2)
{
    string newStr;
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] == c1) newStr += c2;
        else newStr += str[i];
    }
    return newStr;
}



/*
 * 函数名：replaceAll
 * 使用方式：string newStr = replaceAll(str, s1, s2)
 * ------------------------------------------------
 * 使用find函数查找确定s1的位置 pos，然后替换s2，下一次从 pos+s1.length()开始继续查询s1
 */
string replaceAll(string str, string s1, string s2)
{
    string newStr;

    for(int i = 0, start = 0; i < str.length(); )
    {
        if(str.find(s1, i) == std::string::npos)
        {
            newStr += str.substr(i);
            break;
        }
        else
        {
            int pos = str.find(s1, i);
            if(start < pos)
                newStr += str.substr(start, pos-start);
            newStr += s2;
            start = pos + s1.length();
            i = pos + s1.length();
        }
    }

    return newStr;
}
