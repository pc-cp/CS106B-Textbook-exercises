/*
 * File: E-8-10.cpp
 * ---------------------
 * Generate all possible letter combinations that correspond to a given number,
 */

#include <iostream>
#include "map.h"
#include "set.h"
#include "simpio.h"

using namespace std;

/* Function prototype */
void listMnemonics(string numbers);
Set<string> listMnemonicsRec(Map<char, string> &numberToLetter, string &numbers);

/* Main function */

int main(void)
{
    string str = getLine("Enter a prefix numbers: ");
    cout << "possible letter combinations that correspond to that prefix " << str << " is :" << endl;

    listMnemonics(str);
    return 0;
}

// Generates and prints all possible letter combinations that the given
// telephone number can represent.
void listMnemonics(string numbers) {
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

    // Debugging code to print the mapping (commented out).
    // for(char key : numberToLetter) {
    //     cout << key << ' ' << numberToLetter[key] << endl;
    // }

    // Generate mnemonics.
    Set<string> res;
    res = listMnemonicsRec(numberToLetter, numbers);
    // Print the number of mnemonics found and list them.
    cout << res.size() << endl;
    for(string str : res) {
        cout << str << endl;
    }
}

/**
 * Recursive helper function to generate mnemonics.
 *
 * Arguments:
 * - numberToLetter: Mapping from digit to corresponding letters.
 * - numbers: The remaining telephone number to process.
 *
 * Returns a set of strings representing all possible letter combinations
 * for the given telephone number.
 *
 * The recursion shrinks the problem size by processing one digit at a time,
 * exploring all letter mappings for the first digit and appending them to
 * the mnemonics generated for the rest of the number.
 *
 * The base case is reached when there are no digits left to process, at which
 * point an empty string is added to the set to allow for concatenation in the
 * recursive step.
 */
 
Set<string> listMnemonicsRec(Map<char, string> &numberToLetter, string &numbers) {
    Set<string> res;

    // Base case: if there are no more digits to process, add an empty string.
    if(numbers.size() == 0) {
        res.add("");
    }
    else {
        // Get the letters mapped to the first digit.
        string firstNumberToLetters = numberToLetter[numbers[0]];
        // Remove the first digit to process the rest.
        string removeFirstNumberOfNumbers = numbers.substr(1);
        // Recursive call to process the remaining digits.
        Set<string> subres = listMnemonicsRec(numberToLetter, removeFirstNumberOfNumbers);
        // For each mnemonic generated for the remaining digits, prepend
        // each letter mapped to the first digit and add to the result set.
        for(string str: subres) {
            for(int i = 0; i < firstNumberToLetters.size(); ++i) {
                res.add(firstNumberToLetters[i] + str);
            }
        }
    }

    return res;
}
