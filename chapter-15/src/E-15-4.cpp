
#include <iostream>
#include <cctype>
using namespace std;

int arr[26];

int romanToDecimal(const string &str);

int main () {
    int decimal;
    for(char ch = 'A'; ch < 'Z'; ++ch) {
        switch (ch) {
        case 'I':
            decimal = 1;
            break;
        case 'V':
            decimal = 5;
            break;
        case 'X':
            decimal = 10;
            break;
        case 'L':
            decimal = 50;
            break;
        case 'C':
            decimal = 100;
            break;
        case 'D':
            decimal = 500;
            break;
        case 'M':
            decimal = 1000;
            break;
        default:
            decimal = 0;
            break;
        }
        arr[ch-'A'] = decimal;
    }

    string input;
    cin >> input;
    cout << romanToDecimal(input) << endl;
    return 0;
}


int romanToDecimal(const string &str) {
    int res = 0;
    for(int i = 0; i < str.size(); ++i) {
        if(i == str.size()-1 || arr[toupper(str[i])-'A'] >= arr[toupper(str[i+1])-'A']) {
            res += arr[toupper(str[i])-'A'];
        }
        else {
            res -= arr[toupper(str[i])-'A'];
        }
    }
    return res;
}
