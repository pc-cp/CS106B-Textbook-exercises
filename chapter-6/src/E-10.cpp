
/*
 * E-10.cpp
 * -------
 * Write a program that checks the spelling of all words in a file.
 * reference: https://github.com/heavy3/programming-abstractions/blob/master/06-class-design/readerEx.06.10/main.cpp
 */

#include <iostream>
#include <cctype>
#include "tokenscanner.h"
#include "lexicon.h"
#include "filelib.h"
#include "error.h"

const std::string HEADER = "CS106B Programming Abstractions in C++: Ex 6.10\n";
const std::string DETAIL = "SpellChecker";
const std::string BANNER = HEADER + DETAIL;
const std::string PROMPT = "Input file: ";
const std::string LEXFAIL = " is not in the directionary";

int main(void)
{
    std::cout << BANNER << std::endl << std::endl;

    ifstream infile;
    std::string filename;

    Lexicon english("EnglishWords.dat");
    filename = promptUserForFile(infile, PROMPT);
    TokenScanner scanner(infile);
    scanner.ignoreWhitespace();

    while(scanner.hasMoreTokens())
    {
        std::string token = scanner.nextToken();
        if(isalpha(token[0]))
        {
            if(!english.contains(token))
            {
                std::cout << '"' << token << '"' << LEXFAIL << std::endl;
            }
        }
    }
    return 0;
}
