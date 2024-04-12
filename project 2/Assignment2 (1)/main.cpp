/*
Justin Anderson                       
FALL 2024                            PROFESSOR THURSTON
section 31675
ASSIGNMENT #2
Instructions
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "card.h"
#include "deck.h"
#include "hand.h"
//vectors,ctime,cstdlib
using namespace std;

/************************************************************
 *                        FunctionName                      *
 * Function description                                     *
 *   // classes defined are card,hand,deck
 *mydeck is object
 * myhand is object
 * 2 object of card class are cardinstance, random_card
 * Which of the following functions in the DealPokerHands program returns an object of the Card class?
 hand::exchangeCards*
 ************************************************************/
vector<string> readCard();

int main()
{
    vector<string> cardArt = readCard();
    string repeat = "Y";
    Deck myDeck;//class Deck object myDeck 1 ja
    Hand myHand;//class  myHand object 2    ja
    string exchangeCards;

    while (repeat == "Y" || repeat == "y")
    {
        cout << endl;
    
        myHand.newHand(myDeck);
        myHand.print(cardArt);
        cout << endl;

        cout << "Would you like to exchange any cards? [Y / N]: ";
        getline(cin, exchangeCards);

        while (exchangeCards != "Y" && exchangeCards != "y" && exchangeCards != "X" && exchangeCards != "n")
        {
            cout << "Please enter Y or N only: ";
            getline(cin, exchangeCards);

        }

        if (exchangeCards == "Y" || exchangeCards == "y") // added == instead of =y ja
        {
            myHand.exchangeCards(myDeck);
        }
        cout << endl;

		myHand.print(cardArt);

        cout << endl;

        myDeck.resetDeck();  // Resets the deck for a new game

        cout << "Play again? [Y / N]: ";
        getline(cin, repeat);
        while (repeat != "Y" && repeat != "y" && repeat != "N" && repeat != "n")
        {
            cout << "Please enter Y or N only: ";
            getline(cin, repeat);

        }

    }

    return 0;
}

vector<string> readCard() {
	vector<string> cardArt; //vector to store  declares string
	string line;
	ifstream myFile("CardASCII_Art.txt");


	if (myFile.fail()) {
		cout << "unable to open file! " << endl;
		return cardArt;
	}
	while (getline(myFile, line))
	{
		cardArt.push_back(line);
	}
	myFile.close();
	return cardArt;
}


