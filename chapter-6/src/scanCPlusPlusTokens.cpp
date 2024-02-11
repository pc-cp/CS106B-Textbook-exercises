

#include "tokenscanner.h"
/*
 * Function: scanCPlusPlusTokens
 * Usage: scanCPlusPlusTokens(scanner);
 * ------------------------------------
 * Sets the necessary options for the  scanner so that it can
 * read C++ source code/
 */

void scanCPlusPlusTokens(TokenScanner & scanner)
{
    scanner.ignoreWhitespace();
    scanner.ignoreComments();
    scanner.scanNumbers();
    scanner.scanStrings();
    scanner.addWordCharacters("_");
    scanner.addOperator("++");
    scanner.addOperator("--");
    scanner.addOperator("==");
    scanner.addOperator("!=");
    scanner.addOperator("<=");
    scanner.addOperator(">=");
    scanner.addOperator("<<");
    scanner.addOperator(">>");
    scanner.addOperator("&&");
    scanner.addOperator("||");
    scanner.addOperator("+=");
    scanner.addOperator("-=");
    scanner.addOperator("*=");
    scanner.addOperator("%=");
    scanner.addOperator("^=");
    scanner.addOperator("&=");
    scanner.addOperator("|=");
    scanner.addOperator("<<=");
    scanner.addOperator(">>=");
    scanner.addOperator("->");
    scanner.addOperator("::");

}
