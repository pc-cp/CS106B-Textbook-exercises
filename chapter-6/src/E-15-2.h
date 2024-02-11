
/*
 * File: tokenscanner.h
 * --------------------
 * This file exports a simple TokenScanner class that divides a string
 * into individual logical units called tokens.
 */
#ifndef _tokenscanner_h
#define _tokenscanner_h

#include <string>
#include "stack.h"

/*
 * class: TokenScanner
 * -------------------
 * This class is used to represent a single instance of a scanner.
 * In this simplified version of the class, tokens come in two forms:
 *
 * 1. Strings of consecutive letters and digits representing words
 * 2. One-character strings representing punctuation or separators
 *
 * The use of the TokenScanner class is illustrated by the following code
 * pattern, which reads the tokens in the string variable input:
 *
 *          TokenScanner scanner;
 *          scanner.setInput(input);
 *          while(scanner.hasMoreTokens())
 *          {
 *              string token = scanner.nextToken();
 *              . . . process the token . . .
 *          }
 * This version of the TokenScanner class includes the ignoreWhitespace
 * method. The other options available in the library version of the
 * class are included as exercises in the text.
 */
class TokenScanner
{
public:
    /*
     * Constructor: TokenScanner
     * Usage: TokenScanner scanner;
     *        TokenScanner scanner(str);
     * ---------------------------------
     * Initializes a scanner object. The initial token stream comes from
     * the string str, if it is specified. The default constructor creates
     * a scanner with an empty token stream.
     */
    TokenScanner();
    TokenScanner(std::string str);

    /*
     * Method: setInput
     * Usage: scanner.setInput(str);
     * -----------------------------
     * Sets the input for this scanner to the specified string. Any
     * previous input string is discarded.
     */

    void setInput(std::string str);


    /*
     * Method: hasMoreTokens
     * Usage: if(scanner.hasMoreTokens()) . . .
     * ----------------------------------------
     * Returns true if there are additional tokens for this scanner to read.
     */
    bool hasMoreTokens();

    /*
     * Method: nextToken
     * Usage: token = scanner.nextToken();
     * -----------------------------------
     * Returns the next token from this scanner. If called when no tokens
     * are available, nextToken returns the empty string.
     */

    std::string nextToken();

    /*
     * Method: saveToken(token)
     * Saves the specified token as part of this scanner's internal state
     * so that it will be returned on the next call to nextToken.
     */
    void saveToken(std::string token);

    /*
     * Method: ignoreWhitespace()
     * Usage: scanner.ignoreWhitespace();
     * ----------------------------------
     * Tells the scanner to ignore whitespace characters. By default, the
     * nextToken method treats whitespace characters (typically spaces and
     * tabs) just like any other punctuation mark and returns them as
     * single-character tokens. Calling
     *      scanner.ignoreWhitespace();
     * changes this behavior so that the scanner ignore whitespace characters.
     */

    void ignoreWhitespace();


    /*
     * Method: scanStrings()
     * Usage: scanner.scanString();
     * ----------------------------
     * Tells the scanner to return a string enclosed in quotation marks as a
     * single token. The quotation marks (which may be either single or double
     * quotes) are included in the scanned token so that clients can differentiate
     *  strings from other token types.
     */
    void scanStrings();

    /*
     * Method: scanNumbers()
     * Usage: scanner.scanNumbers();
     * -----------------------------
     * Tells the scanner to recognize any legal number as a single token. The
     * syntax for numbers is the same as that used in C++;
     */
    void scanNumbers();

    /* Declare the functions as friends */

private:
    /* Instance variable */
    std::string buffer;     /* The input string containing the tokens */
    int cp;                 /* The current position in the buffer */
    bool ignoreWhitespaceFlag;  /* Flag set by a call to ignoreWhitespace */
    bool scanStringsFlag;       /* Tells the scanner to return a string enclosed in quotation marks as a single token. */
    bool scanNumbersFlag;       /* Flag set by a call to scanNumbers*/
    Stack<std::string> tokens;   /* for saveToken method. */


    /* Private methods */
    void skipWhitespace();
    std::string readStrings();
    std::string readNumbers();


    /*
     * Function: . . .
     * ---------------
     * Simulate relative state of the Finite-state machine.
     */
    bool finiteStateMachineS0();
    bool finiteStateMachineS1();
    bool finiteStateMachineS2();
    bool finiteStateMachineS3();
    bool finiteStateMachineS4();
    bool finiteStateMachineS5();
};



#endif
