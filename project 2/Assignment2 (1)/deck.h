/*
STUDENT NAME                            CS-22-02-74261
FALL 2020                               PROFESSOR THURSTON
ASSIGNMENT #2
*/

#ifndef DECK_H
#define DECK_H

#include <iostream> //included ja
#include <vector>
#include <cstdlib>  // srand(), rand()
#include <ctime>    // time()
#include "card.h"   // Include card header file here
using namespace std;

class Deck
{
public:
    // class Constructor
    Deck();

    // Reset deck to new state (completely undealt)
    void resetDeck();

   

    // Get size of the undealt deck
    const int getSizeUndealtDeck();

    // Get size of the dealt deck
    const int getSizeDealtDeck();

    // Deal a single card
    Card dealCard();   // Is the dealCard() here an accessor or mutator function???

private:
    vector<Card> m_undealtDeck;  // Undealt cards
    vector<Card> m_dealtDeck;    // Dealt cards
};

#endif
