
/*
 * File: E-20.cpp
 * ------------------
 * the first position at which the DNA strand s1 can attach to the strand s2.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
#include "error.h"
using namespace std;

/* Function prototypes */
int findDNAMatch(string s1, string s2, int start = 0);
int findDNAMatch2(string s1, string s2, int start = 0);

/* Main program */
int main()
{
    cout << findDNAMatch("TTGCC", "TAACGGTACGTC") << endl;
    cout << findDNAMatch("TTGCC", "TAACGGTACGTC", 2) << endl;
    cout << findDNAMatch("TGC", "TAACGGTACGTC") << endl;
    cout << findDNAMatch("TGC", "TAACGGTACGTC", 3) << endl;
    cout << "----------------------------------------------" << endl;
    cout << findDNAMatch2("TTGCC", "TAACGGTACGTC") << endl;
    cout << findDNAMatch2("TTGCC", "TAACGGTACGTC", 2) << endl;
    cout << findDNAMatch2("TGC", "TAACGGTACGTC") << endl;
    cout << findDNAMatch2("TGC", "TAACGGTACGTC", 3) << endl;
    return 0;
}

/*
 * Function: findDNAMatch
 * Usage: int pos = findDNAMatch(s1, s2, start)
 * -----------------------------------------------------------
 * 换个思路，首先得到s2可以对应的链，然后调用find函数完事～，实在不行kmp走起
 */

int findDNAMatch(string s1, string s2, int start)
{
    string s;
    for(int i = 0; i < s2.length(); ++i)
    {
        char ch;
        switch(s2[i])
        {
            case 'A':
                ch = 'T';
                break;
            case 'T':
                ch = 'A';
                break;
            case 'C':
                ch = 'G';
                break;
            case 'G':
                ch = 'C';
                break;
            default:
                error("Unrecognized base.");
                break;
        }
        s += ch;
    }

    if(s.find(s1, start) == std::string::npos)
        return -1;
    return s.find(s1, start);
}


int ne[100];  // 保证s1的长度小于100
int findDNAMatch2(string s1, string s2, int start)
{
    string s;
    for(int i = 0; i < s2.length(); ++i)
    {
        char ch;
        switch(s2[i])
        {
        case 'A':
            ch = 'T';
            break;
        case 'T':
            ch = 'A';
            break;
        case 'C':
            ch = 'G';
            break;
        case 'G':
            ch = 'C';
            break;
        default:
            error("Unrecognized base.");
            break;
        }
        s += ch;
    }

    s = " " + s;
    s1 = " " + s1;

    // 构建ne数组
    for(int i = 2, j = 0; i < s1.length(); ++i)
    {
        while(j && s1[i] != s1[j+1]) j = ne[j];
        if(s1[i] == s1[j+1]) j++;
        ne[i] = j;
    }

    int pos = -1;
    for(int i = 1, j = 0; i < s.length(); ++i)
    {
        while(j && s[i] != s1[j+1]) j = ne[j];
        if(s[i] == s1[j+1]) j++;
        if(j == s1.length()-1)
        {
            if(i-j >= start)
            {
                pos = i-j;
                break;
            }
            j = ne[j];
        }
    }
    return pos;
}
