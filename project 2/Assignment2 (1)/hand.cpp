/*
STUDENT NAME                            CS-22-02-74261
FALL 2020                               PROFESSOR THURSTON
ASSIGNMENT #2
Code implementation of the Hand member functions
*/

#include "hand.h" //changed pokerHand to hand error 1 ja

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
// newCard() --- Put new card from deck into given location in the hand
// 1. deal a card from the deck
// 2. assign the card to the location in the hand array
void Hand::newCard(Deck& deck, int location)
{
    Card new_card = deck.dealCard();// card class object 1 new_card ja
    m_hand[location] = new_card;
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
// newHand() --- Get all new cards
// 1. loop for zero to the number of cards on hand (NUM_CARDS_ON_HAND)
// a. get a new card by calling another member function using the loop counter as the location
void Hand::newHand(Deck& deck)
{
    for (int i=0; i < NUM_CARDS_ON_HAND; i++)
    {
        Hand::newCard(deck, i);
    }
}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
// exchangeCards() --- Determine cards to exchange and exchange them
// 1. declare an integer variable to store number of exchanges
// 2. Prompt and ask the user for how many cards to exchange between [1 to 5] (make sure to validate user input)
// 3. loop based on the number of exchanges to make
// declare integer position
// if user wants all card replaced, then
// position = loop counter
// otherwise,
// Prompt and ask the user for the position of the card on hand to exchange (make sure to validate user input)
// get a new card and replace the card at the identified position
void Hand::exchangeCards(Deck& deck)
{
    int num_of_exchanges;
    cout << "How many cards would you like to exchange (1-5): "; // gets number of cards to be exchanged
    cin >> num_of_exchanges;

    while (num_of_exchanges > 5 || num_of_exchanges < 1) // validates input
    {
        cout << "Please enter a number (1-5): ";
        cin >> num_of_exchanges;
    }

    for (int i=0; i < num_of_exchanges; i++) // looping through number of exchanges
    {
        int position = i; // positioned to be changed is i
        if (num_of_exchanges != NUM_CARDS_ON_HAND) // if number of exchanges is less than total hand count
        {
            cout << "Enter a position in hand of card to exchange: ";
            cin >> position; // gets position to be replaced
            while (position > 5 || position < 1) // validates input
            {
                cout << "Please enter a number (1-5): ";
                cin >> position;
            }
            position--;

        }
        Hand::newCard(deck, position); // replaces card at position
    }

}

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *                                                          *
 *                                                          *
 ************************************************************/
// print() --- print the hand
// 1. loop for zero to the number of cards on hand
// a. print out location of the card on hand followed by
// b. print card pip value and card suit value

void Hand::print(vector<string>& cardArt)
{
    for (int i=0; i < NUM_CARDS_ON_HAND; i++)
    {
        cout << "Card " << i+1 << " is the ";
        m_hand[i].print(cardArt);
        cout << endl;
    }
}
