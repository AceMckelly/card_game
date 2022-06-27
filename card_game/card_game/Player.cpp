//Function Definitions

#include "Player.h"

Player::Player(){
	size = 0;
}

Player::Player(int size){
	this->size = size;
}

Player::~Player(){

}

int Player::getSize() const{
	return size;
}

Card Player::getCard(int i) const{
	return cards[i];
}

Card Player::getLastAdded() const{
	return cards[size - 1];
}

void Player::addToHand(Card card){
	size++;
	cards[size - 1] = card;
}

Card Player::playCard(int i){
	Card temp = cards[size - 1];
	cards[size - 1] = cards[i];
	cards[i] = temp;
	size--;
	return cards[size];
}

void Player::showHand(){
	for (int i = 0; i < size; i++){
		cards[i].showCard();
		cout << " ";
	}
}

bool Player::hasSuite(Card board){
	for (int i = 0; i < size; i++){
		if (cards[i].getSuite() == board.getSuite()){
			return true;
		}
	}
	return false;
}

bool Player::isEmpty(){
	if (size == 0){
		return true;
	}
	else{
		return false;
	}
}

Card Player::playLastAdded(){
	size--;
	return cards[size];
}

bool Player::hasHigher(Card board){
	for (int i = 0; i < size; i++){
		if (cards[i].getSuite() == board.getSuite()){
			if (cards[i].getValue()>board.getValue())
				return true;
		}
	}
	return false;
}

int Player::chooseBest(Card board){
	int best = -1;
	for (int i = 0; i < size; i++){
		if (cards[i].getSuite() == board.getSuite()){
			if (cards[i].getValue()>board.getValue()){
				best = i;
				break;
			}
		}
	}
	for (int i = best; i < size; i++){
		if (cards[i].getSuite() == cards[best].getSuite()){
			if (cards[i].getValue()<cards[best].getValue()){
				best = i;
			}
		}
	}
	return best;
}

int Player::chooseLowest(Card board){
	int lowest = -1;
	for (int i = 0; i < size; i++){
		if (cards[i].getSuite() == board.getSuite()){
			if (cards[i].getValue()<board.getValue()){
				lowest = i;
				break;
			}
		}
	}
	for (int i = lowest; i < size; i++){
		if (cards[i].getSuite() == cards[lowest].getSuite()){
			if (cards[i].getValue()>cards[lowest].getValue()){
				lowest = i;
			}
		}
	}
	return lowest;
}

int Player::autosecond_player(Card board){
	if (hasSuite(board)){
		if (hasHigher(board))
			return chooseBest(board);
		else
			return chooseLowest(board);
	}
}