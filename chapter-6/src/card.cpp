
/*
 * File: card.cpp
 * --------------
 * This file implements the card.h interface.
 */
#include <iostream>
#include <string>
#include "strlib.h"
#include "card.h"

using namespace std;


extern const double ACE = 1;
extern const double JACK = 11;
extern const double QUEEN = 12;
extern const double KING = 13;

/*
 * Implementation notes: operator++ (prefix)
 * -----------------------------------------
 * ...
 */
Suit operator++(Suit &suit)
{
    suit = Suit(suit + 1);
    return suit;
}


/*
 * Implementation notes: operator++(suffix)
 * ----------------------------------------
 * ...
 */
Suit operator++(Suit &suit, int)
{
    Suit old = suit;
    suit = Suit(suit + 1);
    return old;
}


Card::Card()
{
    ;
}

Card::Card(string shortName)
{
    if(shortName.length() < 2 || shortName.length() > 3)
        error("shortName is illegal.");
    char suitToCharacter = shortName[shortName.length()-1];
    switch(suitToCharacter)
    {
        case 'C':
            suit = CLUBS;
            break;
        case 'D':
            suit = DIAMONDS;
            break;
        case 'H':
            suit = HEARTS;
            break;
        case 'S':
            suit = SPADES;
            break;
        default:
            error("not match suit.");
            break;
    }
    if(isalpha(shortName[0]))
    {
        if(shortName[0] == 'A')
            rank = 1;
        else if(shortName[0] == 'J')
            rank = 11;
        else if(shortName[0] == 'Q')
            rank = 12;
        else if(shortName[0] == 'K')
            rank = 13;
    }
    else
        rank = stringToInteger(shortName.substr(0, shortName.length()-1));
}

Card::Card(int crank, Suit csuit)
{
    rank = crank;
    suit = csuit;
}

/*
 * Implementation notes: Getters
 * -----------------------------
 * The getters return the value of the corresponding instance variable.
 */

int Card::getRank()
{
    return rank;
}

Suit Card::getSuit()
{
    return suit;
}


/*
 * Implementation notes: toString
 * ------------------------------
 * The implementation of toString uses the integerToString function
 * from the strlib.h interface.
 */
string Card::toString()
{
    string rankToString = "";
    if(rank == 1 || rank > 10)
    {
        switch(rank)
        {
            case 1:
                rankToString += "A";
                break;
            case 11:
                rankToString += "J";
                break;
            case 12:
                rankToString += "Q";
                break;
            case 13:
                rankToString += "K";
                break;
            default:
                error("rank error in Card::toString.");
                break;
        }
    }
    else
        rankToString += integerToString(rank);

    string suitToString = "";
    switch(suit)
    {
        case CLUBS:
            suitToString += "C";
            break;
        case DIAMONDS:
            suitToString += "D";
            break;
        case HEARTS:
            suitToString += "H";
            break;
        case SPADES:
            suitToString += "S";
            break;
        default:
            error("suit error in Card::toString.");
    }
    return rankToString+suitToString;
}

ostream & operator<<(ostream &os, Card card)
{
    return os << card.toString();
}

