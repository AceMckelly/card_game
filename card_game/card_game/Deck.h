//Header ==> Function declaration

#include <iostream>
#include <time.h>

#include "Card.h"

using namespace std;

#ifndef DECK_H
#define DECK_H

class Deck{

public:
	//Default Constructor
	Deck();

	//Overload Constructor
	Deck(int);

	//Destructor
	~Deck();

	//Accessor Functions
	int getSize() const;
		//getSize - returns the deck's size

	void showCards();
		//displays all cards in the deck;

	//Mutator Functions
	void setSize(int);
		//setSize- sets the size of deck
		//@param int - size of deck

	void buildDeck();
		//buildDeck - assigns values to cards

	void shuffleDeck();
		//shuffleDeck - randomizes the order of the cards array

	Card getTopCard();
		//getTopCard - returns the card at the highest index 
		//decreases the size of the deck
		//@return card at the heighest index

	bool isEmpty();
		//isEmpty - return true if size is 0
		//@returns bool

private:
	//Member Variables
	int size;
	Card cards[52];

};

#endif