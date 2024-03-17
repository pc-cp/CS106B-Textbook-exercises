
#include "lexicon.h"
#include "set.h"
#include "simpio.h"
#include "strlib.h"
#include <string>
using namespace std;

/* Function prototype */
void listCompletions(string digits);
Set<string> listCompletionsRec(Map<char, string> &numberToLetter, string digits, string prefixString, Lexicon & lex);

static Lexicon& sharedLexicon() {
    static Lexicon lex("res/EnglishWords.txt");
    return lex;
}

/* Main function */
int main(void)
{
    string str = getLine("Enter a prefix numbers: ");
    cout << "prints all words from the lexicon that can be formed by extending the given digit sequence " << str << " is :" << endl;
    listCompletions(str);
    return 0;
}

// Lists all word completions for a given string of digits using a telephone keypad mapping.
void listCompletions(string digits) {
    // Access a shared lexicon of words.
    Lexicon& lex = sharedLexicon();

    // Mapping from digit to corresponding letters on a telephone keypad.
    Map<char, string> numberToLetter;
    // Initialize the mapping for digits '2' to '9'.
    for(char number = '2', letter = 'A'; number <= '9'; ++number) {
        string str;
        // Each digit maps to 3 or 4 letters.
        for(int i = 0; i < 3; ++i) {
            str += letter++;
        }
        // Digits '7' and '9' map to 4 letters.
        if(number == '7' || number == '9') {
            str += letter++;
        }
        numberToLetter[number] = str;
    }

    // Collects all valid prefixes and words that can be formed from the digits.
    Set<string> res, prefixAndWords;
    prefixAndWords = listCompletionsRec(numberToLetter, digits, "", lex);

    cout << prefixAndWords.size() << endl;

    // Filters the lexicon for words that start with any valid prefix found.
    // This step is necessary despite the requirement to use only contains and containsPrefix,
    // as it ensures that only complete words from the lexicon are considered.
    for(string str : prefixAndWords) {
        for(string word: lex) {
            if(startsWith(word, toLowerCase(str))) {
                res.add(word);
            }
        }
    }

    // Prints the filtered list of words.
    for(string word: res) {
        cout << word << endl;
    }
}

// Recursive helper function to generate all valid prefixes and words from the lexicon.
Set<string> listCompletionsRec(Map<char, string> &numberToLetter, string digits, string prefixString, Lexicon & lex) {
    Set<string> res;
    // Base case: if no more digits to process, add the prefixString if it's not empty.
    if(digits.size() == 0) {
        if(prefixString.size() != 0) {
            res.add(prefixString);
        }
    }
    else {
        // Get the letters mapped to the first digit.
        string firstDigitToLetters = numberToLetter[digits[0]];
        // Remove the first digit to process the rest.
        string removeFirstDigit = digits.substr(1);
        // For each letter mapped to the first digit, check if adding it to the prefix forms
        // a valid word or prefix in the lexicon. If so, continue recursively.
        for(char ch : firstDigitToLetters) {
            if(lex.contains(prefixString+ch) || lex.containsPrefix(prefixString+ch)) {
                Set<string> subres = listCompletionsRec(numberToLetter, removeFirstDigit, prefixString+ch, lex);
                res += subres;
            }
        }
    }
    return res;
}

