
/*
 * File: E-19.cpp
 * --------------
 * Write a program that reads in lines
 * from the user and translates each line either
 * to or from Morse code depending on the first character of the line:
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "map.h"
#include "grid.h"
#include "random.h"
using namespace std;

/* Constant */


/* Funciton prototype */
void characterToMorse(string input);
void morseToCharacter(string input);
/* Main function*/
int main(void)
{
    cout << "Morse code translator" << endl;
    string input;
    while(true)
    {
        cout << "> ";
        getline(cin, input);
        if(input == "") break;
        if(isalpha(input[0]))
            characterToMorse(input);
        else
            morseToCharacter(input);
    }
   return 0;
}

void characterToMorse(string input)
{
    Map<char, string> charToMorse;
    charToMorse['A'] = ".-";
    charToMorse['B'] = "-...";
    charToMorse['C'] = "-.-.";
    charToMorse['D'] = "-..";
    charToMorse['E'] = ".";
    charToMorse['F'] = "..-.";
    charToMorse['G'] = "--.";
    charToMorse['H'] = "....";
    charToMorse['I'] = "..";
    charToMorse['J'] = ".---";
    charToMorse['K'] = "-.-";
    charToMorse['L'] = ".-..";
    charToMorse['M'] = "--";
    charToMorse['N'] = "-.";
    charToMorse['O'] = "---";
    charToMorse['P'] = ".--.";
    charToMorse['Q'] = "--.-";
    charToMorse['R'] = ".-.";
    charToMorse['S'] = "...";
    charToMorse['T'] = "-";
    charToMorse['U'] = "..-";
    charToMorse['V'] = "...-";
    charToMorse['W'] = ".--";
    charToMorse['X'] = "-..-";
    charToMorse['Y'] = "-.--";
    charToMorse['Z'] = "--..";
    for(int i = 0; i < input.length(); ++i)
    {
        if(isalpha(input[i]))
        {
            cout << charToMorse[toupper(input[i])];
            if(i != input.length()-1)
                cout << ' ';
        }
    }
    cout << endl;
}
void morseToCharacter(string input)
{
    Map<string, char> morseToChar;
    morseToChar[".-"] = 'A';
    morseToChar["-..."] = 'B';
    morseToChar["-.-."] = 'C';
    morseToChar["-.."] = 'D';
    morseToChar["."] = 'E';
    morseToChar["..-."] = 'F';
    morseToChar["--."] = 'G';
    morseToChar["...."] = 'H';
    morseToChar[".."] = 'I';
    morseToChar[".---"] = 'J';
    morseToChar["-.-"] = 'K';
    morseToChar[".-.."] = 'L';
    morseToChar["--"] = 'M';
    morseToChar["-."] = 'N';
    morseToChar["---"] = 'O';
    morseToChar[".--."] = 'P';
    morseToChar["--.-"] = 'Q';
    morseToChar[".-."] = 'R';
    morseToChar["..."] = 'S';
    morseToChar["-"] = 'T';
    morseToChar["..-"] = 'U';
    morseToChar["...-"] = 'V';
    morseToChar[".--"] = 'W';
    morseToChar["-..-"] = 'X';
    morseToChar["-.--"] = 'Y';
    morseToChar["--.."] = 'Z';

    int start = -1;
    for(int i = 0; i < input.length(); ++i)
    {
        if(input[i] == '.' || input[i] == '-')
        {
            if(start == -1) start = i;
        }
        else
        {
            if(start >= 0)
            {
                cout << morseToChar[input.substr(start, i-start)];
                start = -1;
            }
        }
    }
    if(start >= 0) cout << morseToChar[input.substr(start)];
    cout << endl;
}

