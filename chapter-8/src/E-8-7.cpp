
#include <iostream>
#include "card.h"
#include "vector.h"

using namespace std;

//
int countFifteens(Vector<Card> & cards);
int countFifteensRec(Vector<Card> & cards, int target);
int main() {

    // for (Suit suit = CLUBS; suit <= SPADES; suit++) {
    //     for (int rank = ACE; rank <= KING; rank++) {
    //         cout << " " << Card(rank, suit);
    //     } cout << endl;
    // }
    // return 0;


    // compile error？
    // HashSet<Card> inputCards;
    Vector<Card> cards;
    cout << "输入5张不同的纸牌(10S/AD)：" << endl;
    int cardNumbers = 0;
    while(true) {
        cout << "input " << cardNumbers+1 << ": ";
        string shortName;
        getline(cin, shortName);
        Card currentCard(shortName);
        // if(inputCards.contains(currentCard)) {
        //     cout << "输入的纸牌与之前的输入重复，请重新输入." << endl;
        //     continue;
        // }
        // else {
            cards.insert(cardNumbers, currentCard);
            cardNumbers++;
            if(cardNumbers == 5) {
                break;
            }
        // }
    }
    Vector<Card> fixCards;
    cardNumbers = 0;
    for(Card card : cards) {
        // cout << card << endl;
        if(card.getRank() > 10) {
            Card currentCard(10, card.getSuit());
            fixCards.insert(cardNumbers, currentCard);
        }
        else {
            fixCards.insert(cardNumbers, card);
        }
        cardNumbers++;
    }

    cout << countFifteens(fixCards) << endl;

    return 0;
}

int countFifteens(Vector<Card> & cards) {
    return countFifteensRec(cards, 15);
}

// Counts the number of subsets of cards that sum up to a target value.
// This is a recursive function that reduces the problem size by either including
// a card in the sum or excluding it, thus exploring all combinations.
// The base case occurs when there are no cards left to consider.
int countFifteensRec(Vector<Card> &cards, int target) {
    // Base case: if there are no cards left, check if the target sum has been achieved.
    if(cards.isEmpty()) {
        return target == 0 ? 1 : 0; // Return 1 if target is met, otherwise 0.
    }
    else {
        // Take the first card to consider its value in the sum.
        Card firstCard = cards.get(0);
        Vector<Card> removeFirstCard = cards;
        removeFirstCard.remove(0); // Prepare for recursive calls by removing the first card.
        // Recursively count subsets by:
        // 1. Including the first card's value in the target sum,
        // 2. Excluding the first card and keeping the target sum unchanged.
        // The total count is the sum of counts from both approaches.
        return countFifteensRec(removeFirstCard, target-firstCard.getRank())
               + countFifteensRec(removeFirstCard, target);
    }
}
