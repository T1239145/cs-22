/*
STUDENT NAME                            CS-22-02-74261
FALL 2020                               PROFESSOR THURSTON
ASSIGNMENT #2
Code implementation of the Deck member functions
*/

#include "deck.h"


/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                        objects of card class cardinstance
                            random_card    *
                            new_card
 *                                                          *
 ************************************************************/
Deck::Deck() //--- default class constructor
{
    srand(time(0));
    for (int i=0; i < 52; i++)
    {
        Card cardInstance;
        cardInstance.set(i);// object  added ; ja
        m_undealtDeck.push_back(cardInstance); // should it be .get here()???
       
    }
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
void Deck::resetDeck() //changed void deck:: to void Deck::resetDeck ja calls class then object deck
{
    while (getSizeDealtDeck() != 0)
    {
       //not needed ja m_undealtDeck.push_back(m_dealtDeck.pop_back()); 
        int last_index = getSizeDealtDeck()-1;
        m_undealtDeck.push_back(m_dealtDeck[last_index]);
        m_dealtDeck.pop_back();

    }

}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
//   1. initialize random number generator
//          srand(time(0));
//   2. Create the deck of cards (52 Card objects)
//          loop 52 times
//             a. create an instance of the Card class
//             b. set the card instance to the value of the counter
//             c. add the card to the undealt deck vector

// reset() --- Reset the deck (completely undealt). We are moving all the cards in the dealt vector back to the undealt vector.
//   loop while the dealt deck is not empty
//       a. compute for the last index of the dealt deck vector and save it to a variable
//       b. get the Card from the last index in the dealt vector then,
//       c. push that Card back to the undealt vector
//       d. remove the last Card from the dealt vector

Card Deck::dealCard() // --- Deal a single card
{
    int random_index = rand() % getSizeUndealtDeck(); // gets random index in undealt deck
    Card random_card; // object 2 of card class object name random_card
    random_card.set(m_undealtDeck[random_index].get()); // set the random card to the correct value

    m_dealtDeck.push_back(random_card); // pushes the random card to the dealt deck
    m_undealtDeck[random_index] = m_undealtDeck.back(); // puts the back index value to the random index
    m_undealtDeck.pop_back(); // gets rid of the back value
    return random_card;

        //   1. get a random card through an random index
        //        - the random index will be rand() modulo the size of undealt deck
        //   2. using the random index, get the random card from the undealt deck and assign to a new instance of the Card
        //   3. then add a copy of the random card to the dealt deck vector
        //   4. swap the last card in the undealt deck with the random card in the undealt deck
        //   5. remove the last card in the dealt deck
        //   6. return the random card

}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
const int Deck::getSizeUndealtDeck() // --- return size of undealt deck
{
    return m_undealtDeck.size();
}

const int Deck::getSizeDealtDeck()   // --- return size of dealt deck
{
    return m_dealtDeck.size();
}


/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
 