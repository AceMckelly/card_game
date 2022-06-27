//Function Definitions

#include "Deck.h";

Deck::Deck(){
	size = 52;
}

Deck::Deck(int size){
	this->size = size;
}

Deck::~Deck(){

}

int Deck::getSize() const{
	return size;
}

void Deck::showCards(){
	for (int i = 0; i < size; i++){
		cout << cards[i].getFace();
		cout << cards[i].getSuite();
	}
}

void Deck::setSize(int size){
	this->size = size;
}

void Deck::buildDeck(){
	char suites[] = { 3, 4, 5, 6 };
	char faces[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 13; j++){
			cards[13 * i + j].setValue(j);
			cards[13 * i + j].setSuite(suites[i]);
			cards[13 * i + j].setFace(faces[j]);
		}	
	}
}

void Deck::shuffleDeck(){
	srand(time(NULL));
	for (int i = size-1; i>0; i--){
		int x = rand() % i;
		Card temp = cards[x];
		cards[x] = cards[i];
		cards[i] = temp;
	}
}

Card Deck::getTopCard(){
	size--;
	return cards[size];
}

bool Deck::isEmpty(){
	if (size == 0){
		return true;
	}
	else{
		return false;
	}
}