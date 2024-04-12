/*
STUDENT NAME                            CS-22-02-74261
FALL 2020                               PROFESSOR THURSTON
ASSIGNMENT #2
Code implementation of the Card member functions
*/
#include "card.h"


/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
// get() --- Get card value
// - return the value from the member variable
int Card::get()
//changed from void to int as it is returning a int value ja
//int value being returned is from void card
{
    return m_cardValue;
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
// set() --- Set card value
// - set the value of the member variable
void Card::set(int newCardVal)
{
    m_cardValue = newCardVal;
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
string Card::getPip()
{
    return pips[m_cardValue % 13];
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
string Card::getSuit()
{
    return suits[m_cardValue / 13];
}


/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
// print() --- Print card value
// - print the card's value
// - Example display if member variable m_cardValue is 0
// - it should print "Ace of Hearts"
void Card::print(vector<string>& cardArt)
{
    int suit_number = m_cardValue / 13;
    int pip_number = m_cardValue % 13;

    cout << pips[pip_number] << " of " << suits[suit_number];

        for (int i = 0; i < 6; i++) {

            cout << cardArt[m_cardValue * 6 + i] << " ";      
            cout << "\n";
        }

    
    /*
    6 lines for each card
    "\n to create space
    */

}