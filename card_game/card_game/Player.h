//Header ==> Function declaration

#include <iostream>

#include "Card.h"

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player{

public:
	//Default Constructor
	Player();

	//Overload Constructor
	Player(int);

	//Destructor
	~Player();

	//Accessor Functions
	int getSize() const;
		//getSize - returns the size

	Card getCard(int) const;
		//getCard - returns a card at a given index
		//@param int - card index
		//@return card

	Card getLastAdded() const;
		//getLastAdded - returns the card at the highest index
		//return card

	void showHand();
		//shows the players cards;

	//Mutator Functions
	void addToHand(Card);
		//addToHand - adds a card to hand
		//increases size
		//@param 1 card

	Card playCard(int);
		//playCard - plays a card from hand
		//decreases size
		//@param the index of the card
		//@return return the card played

	bool hasSuite(Card);
		//hasSuite - determines if player can play
		//@param the card on the board
		//@return whether the player has a matching suite
	

	bool isEmpty();
		//isEmpty - determines if player has cards
		//@return bool true if size is 0

	Card playLastAdded();
		//playLastAdded - plays the card from the highest index
		//decreases size
		//@return the card at the highest index

	bool hasHigher(Card);
		//hasHigher - determines if player has a higher card
		//@param the card on the board
		//@return return whether the player has a card that is higher

	int chooseBest(Card);
		//playBest - plays the card that is just higher than the board
		//@param the card on the board
		//@return the best card 

	int chooseLowest(Card);
		//playLowest - plays the lowest card of the suite
		//@param the card on the board
		//@return the index card of the suite

	int autosecond_player(Card);
		//autosecond_player - plays second automatically
		//@param the card on the board
		//@return the index of the card to play

private:
	//Member variables
	int size;
	Card cards[52];
};

#endif