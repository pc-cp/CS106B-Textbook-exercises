
/*
 * File: tokenscanner.cpp
 * ----------------------
 * This file implements the TokenScanner class. Most of the methods
 * are straightforward enough to require no additional documentation.
 */

#include <cctype>
#include <string>
#include "strlib.h"
#include "tokenscanner.h"

TokenScanner::TokenScanner()
{
    /* Empty */
}

TokenScanner::TokenScanner(std::string str)
{
    setInput(str);
}

void TokenScanner::setInput(std::string str)
{
    buffer = str;
    cp = 0;
}

bool TokenScanner::hasMoreTokens()
{
    if(ignoreWhitespaceFlag) skipWhitespace();
    return cp < buffer.length();
}

/*
 * Implementation notes: nextToken
 * -------------------------------
 * This method starts by looking at the character at the current character
 * indicated by the index cp. If that index is past the end of the string,
 * nextToken returns the empty string. If that character is alphanumberic,
 * nextToken scans ahead until it finds the end of that word; if not,
 * nextToken returns that character as a one-character string.
 */

std::string TokenScanner::nextToken()
{
    if(ignoreWhitespaceFlag) skipWhitespace();
    if(cp >= buffer.length()) return "";

    if(scanStringsFlag)
    {
        if(buffer[cp] == '\'' || buffer[cp] == '\"')
        {
            return readStrings();
        }
    }
    if(!tokens.isEmpty())
    {
        return tokens.pop();
    }
    if(scanNumbersFlag)
    {
        if(isdigit(buffer[cp]))
        {
            return readNumbers();
        }
    }

    if(isalpha(buffer[cp]))
    {
        int start = cp;
        while(cp < buffer.length() && isalpha(buffer[cp]))
            cp++;
        return buffer.substr(start, cp-start);
    }
    else
    {
        return std::string(1, buffer[cp++]);
    }
}

/*
 * Implementation notes: saveToken
 * -------------------------------
 * Saves the specified token as part of this scanner's internal state so that
 * it will be returned on the next call to nextToken. The library implementation
 * allows clients to save any number of tokens, which are then delivered in a stack-like fashion.
 */
void TokenScanner::saveToken(std::string token)
{
    tokens.push(token);
}


/*
 * Implementation notes: ignoreWhitespace and skipWhitespace
 * ---------------------------------------------------------
 * This ignoreWhitespace method simply sets a flag. The private method
 * skipWhitespace is called only if that flag is ture.
 */

void TokenScanner::ignoreWhitespace()
{
    ignoreWhitespaceFlag = true;
}

void TokenScanner::skipWhitespace()
{
    while(cp < buffer.length() && isspace(buffer[cp]))
        cp ++;
}

/*
 * Implementation notes: scanStrings
 * ---------------------------------
 * Similar to ignoreWhitespace.
 */
void TokenScanner::scanStrings()
{
    scanStringsFlag = true;
}


std::string TokenScanner::readStrings()
{
    int begin = cp;
    cp ++;

    bool end = false;
    if(buffer[begin] == '\'')
    {
        while(cp < buffer.length() && !end)
        {
            if(buffer[cp] == '\'') end = true;
            cp++;
        }
    }
    else
    {
        while(cp < buffer.length() && !end)
        {
            if(buffer[cp] == '\"') end = true;
            cp++;
        }
    }
    return buffer.substr(begin, cp-begin);
}



/*
 *
 */

void TokenScanner::scanNumbers()
{
    scanNumbersFlag = true;
}

std::string TokenScanner::readNumbers()
{
    int begin = cp;
    if(finiteStateMachineS0())
    {
        if(finiteStateMachineS1())
        {
            while(finiteStateMachineS1())
                cp++;
            if(finiteStateMachineS2())
            {
                while(finiteStateMachineS2())
                    cp++;
                if(finiteStateMachineS3())
                {
                    cp++;
                    if(finiteStateMachineS4())
                        cp++;
                    if(finiteStateMachineS5())
                    {
                        while(finiteStateMachineS5())
                            cp++;
                    }

                }


            }
            if(finiteStateMachineS3())
            {
                cp++;
                if(finiteStateMachineS4())
                    cp++;
                if(finiteStateMachineS5())
                {
                    while(finiteStateMachineS5())
                        cp++;
                }

            }
        }
    }
    return buffer.substr(begin, cp-begin);
}


/*
 * Function: . . .
 * ---------------
 * Simulate relative state of the Finite-state machine.
 */
bool TokenScanner::finiteStateMachineS0()
{
    return true;
}
bool TokenScanner::finiteStateMachineS1()
{
    if(cp < buffer.length() && isdigit(buffer[cp]))
        return true;
    return false;
}

bool TokenScanner::finiteStateMachineS2()
{
    if(cp < buffer.length() && (buffer[cp] == '.' || isdigit(buffer[cp])))
        return true;
    return false;
}
bool TokenScanner::finiteStateMachineS3()
{
    if(cp < buffer.length() && toupper(buffer[cp]) == 'E' )
        return true;
    return false;
}
bool TokenScanner::finiteStateMachineS4()
{
    if(cp < buffer.length() && (buffer[cp] == '+' || buffer[cp] == '-'))
        return true;
    return false;
}
bool TokenScanner::finiteStateMachineS5()
{
    if(cp < buffer.length() && isdigit(buffer[cp]))
        return true;
    return false;
}
