//Header ==> Function declaration

#include <iostream>

using namespace std;

#ifndef CARD_H
#define CARD_H

class Card{

public:
	//Default Constructor
	Card();

	//Overload Constructor
	Card(char, int, char);

	//Destructor
	~Card();

	//Accessor Functions
	char getSuite() const;
		//getSuite - returns the card's suite

	int getValue() const;
		//getValue - returns the card's value

	char getFace() const;
		//getFace - returns the card's face

	void showCard();
		//showCard - displays face and suite

	//Mutator Functions
	void setSuite(char);
		//setSuite - sets the suite of card
		//@param char - suite of card

	void setValue(int);
		//setValue - set the value of card
		//@param int - value of card

	void setFace(char);
		//setFace - set the face of the card
		//@param char - value of card

	bool compareSuite(Card);
		//compareSuite - determines if the suite is the same
		//@param Card - players card
		//@return bool - true if suite is the same

	bool isMoreThan(Card);
		//isMoreThan - determines if this is higher
		//@param Card - the other card
		//return - true if it is more


private:
	//Member variables
	char suite;
	int value;
	char face;
};

#endif