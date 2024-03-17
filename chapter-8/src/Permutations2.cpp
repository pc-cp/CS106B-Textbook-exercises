

#include <iostream>
#include <string>
#include "set.h"
using namespace std;

/* Function prototype */
Set<string> generatePermutations(string str);

int main(void)
{
    Set<string> set = generatePermutations("ABC");
    for(auto s : set)
        cout << s << endl;

    return 0;
}

Set<string> generatePermutations(string str)
{
    Set<string> res;
    int len = str.length();
    if(len == 0)
    {
        string index = string("");
        res.add(index);
        return res;
    }
    else
    {
        for(int i = 0; i < len; ++i)
        {
            string index = string("") + str[i];
            string strExceptIndex = str.substr(0, i) + str.substr(i+1);
            Set<string> subres = generatePermutations(strExceptIndex);
            for(auto s: subres)
            {
                res.add(index + s);
            }
        }
    }
    return res;
}
