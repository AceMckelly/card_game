//Function Definitions

#include "Card.h";

Card::Card(){
	suite = ' ';
	value = 0;
	face = 0;
}

Card::Card(char suite, int value, char face){
	this->suite = suite;
	this->value = value;
	this->face = face;
}

Card::~Card(){

}

char Card::getSuite() const{
	return suite;
}

int Card::getValue() const{
	return value;
}

char Card::getFace() const{
	return face;
}

void Card::setSuite(char suite){
	this->suite = suite;
}

void Card::setValue(int value){
	this->value = value;
}

void Card::setFace(char face){
	this->face = face;
}

void Card::showCard(){
	cout << face;
	cout << suite;
}

bool Card::compareSuite(Card player_card){
	if (suite == player_card.getSuite()){
		return true;
	}
	else{
		return false;
	}
}

bool Card::isMoreThan(Card player_card){
	if (value > player_card.getValue()){
		return true;
	}
	else{
		return false;
	}
}