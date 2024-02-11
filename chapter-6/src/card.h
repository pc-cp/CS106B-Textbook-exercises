
/*
 * File: card.h
 * ------------
 * This interface exports an enumerated type called Suit (CLUBS, DIAMONDS, HEARTS, SPADES) and class called Card.
 */

#ifndef _card_h
#define _card_h

#include <iostream>
#include <string>

/* Constants */
extern const double ACE;
extern const double JACK;
extern const double QUEEN;
extern const double KING;

/*
 * Type: Suit
 * ----------
 * This enumerated type is used to represent the four suits:
 * CLUBS, DIAMONDS, HEARTS, SPADES.
 */
enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

/*
 * Function: operator++
 * Usage: ++suit
 * -------------
 * overload prefix form.
 */
Suit operator++(Suit &suit);

/*
 * Function: operator++
 * Usage: suit++
 * --------------
 * overload suffix form.
 */
Suit operator++(Suit &suit, int);

/*
 * Class: Card
 * -----------
 * Defines a Card class suitable for representing a standard playing card,
 * which is identified by two components: a rank and a suit.
 */

class Card
{
public:
    /*
     * Constructor: Card
     * Usage: Card card;
     *        Card card(string);
     *        Card card(crank, csuit);
     * -----------------------------
     * Creates a Card object. The default constructor creates the card that can later
     * be assigned a value. The single-argument form creates a card that takes a short
     * string name like "10S" or "JD", and the two-argument form creates a card that
     * takes separate values for the rank and the suit.
     */

    Card();
    Card(std::string shortName);
    Card(int crank, Suit csuit);

    /*
     * Method: toString()
     * Usage: string str = card.toString();
     * ------------------------------------
     * Returns the string representation of this card number.
     */

    std::string toString();

    /*
     * Implementation notes: Getters
     * -----------------------------
     * The getters return the value of the corresponding instance variable.
     */

    int getRank();
    Suit getSuit();

    /* Instance variable */
private:

    int rank;       /* The rank is stored as an integer between 1 and 13 in which an ace is a 1, a jack is an 11, a queue is a 12, and a king is 13. */
    Suit suit;      /* The suit is one of the four constants in the following enumeration type */

};

/*
 * Operator: <<
 * Usage: cout << card
 * -------------------
 * Overloads the << operator so that it is able to display Card values.
 */

std::ostream & operator<<(std::ostream &os, Card card);

#endif
