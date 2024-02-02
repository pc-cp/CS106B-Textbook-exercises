
/*
 * File: E-23.cpp
 * --------------
 * From: https://github.com/heavy3/programming-abstractions/blob/master/05-collections/readerEx.05.22/main.cpp
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "lexicon.h"

using namespace std;

const string LINE = string(60, '-') + '\n';
const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

/* Function prototype */
void banner(int wordLength);
void getScrabbleWords(Lexicon lex, int wordLength, string alphabet,
                      Set<string> & scrabbleWords);
void showScrabbleWords(Set<string> &scrabbleWords, int wordLength);

// Main function
int main(void)
{
    Set<string> scrabbleWords;
    Lexicon english("EnglishWords.dat");

    int wordLength = 3;
    banner(wordLength);
    getScrabbleWords(english, wordLength, ALPHABET, scrabbleWords);
    showScrabbleWords(scrabbleWords, wordLength);

    return 0;
}

// Function definitions

/*
 *  Function: banner
 *  Usage: banner(wordLength);
 *  --------------------------
 *  Displays the purpose of the program on the console.
 */
void banner(int N)
{
    cout << "This program displays all " << N << "-letter,, 'Scrabble-friendly',"
         << endl
         << "words in the Standford English lexicon formed by prepending" << endl
         << "or appending a letter to all " << N-1 << "-letter words."
         << endl;
    cout << LINE;
}

/*
 * Function: getScrabbleWords
 * Usage: getScrabbleWords(lex, N, alphabetString, ScrabbleWords);
 * ---------------------------------------------------------------
 * Returns a set of N-length words that can be constructed by
 * either prepending or appending a letter to an (N-1)-length word.
 */
void getScrabbleWords(Lexicon lex, int N, string alphabet, Set<string> &scrabbleWords)
{
    Set<string> actualNLengthWords;
    for(string word: lex)
    {
        if(word.length() == N)
            actualNLengthWords.add(word);
    }

    Set<string> frankeNLengthWords;
    for(string word: lex)
    {
        if(word.length() == (N-1))
            for(char ch : alphabet)
            {
                string prependw = ch + word;
                string appendw = word + ch;
                frankeNLengthWords.add(prependw);
                frankeNLengthWords.add(appendw);
            }
    }

    scrabbleWords = actualNLengthWords * frankeNLengthWords;
}

void showScrabbleWords(Set<string> &scrabbleWords, int N)
{
    for(string word: scrabbleWords)
        cout << word << endl;

    cout << scrabbleWords.size()
         << "\tScrabble-friendly word of length " << N << endl
         << "\tcreated by prepending/appending a letter to another word."
         << endl;
}
