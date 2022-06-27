#include <iostream>
#include <string>


#include "Deck.h";
#include "Card.h";
#include "Player.h"

using namespace std;

Player players[2];

int player;

Deck deck;

Card board;
Card highest_on_the_board;

int game_round;

bool gameOver;

bool winner(){
	if (players[player].isEmpty()){
		return true;
	}
	else{
		return false;
	}
}

void setup(){
	deck.buildDeck();
	deck.shuffleDeck();

	for (int i = 0; i < 7; i++){
		players[0].addToHand(deck.getTopCard());
		players[1].addToHand(deck.getTopCard());
	}

	board = deck.getTopCard();

	gameOver = false;
	player = 0;
	game_round = 0;
}

void draw(){
	system("cls");
	cout << "Player " << player + 1 << " turn"<<endl;
	cout << "The Deck has " << deck.getSize() << " cards" << endl;
	if (player == 0){
		cout << "Player 2 has " << players[1].getSize() << " cards"<<endl;
	}
	else{
		cout << "Player 1 has " << players[0].getSize() << " cards" << endl;
	}
	system("pause");
	system("cls");
	players[player].showHand();
	cout << endl;
	for (int i = 0; i < players[player].getSize();i++){
		cout << i<<"  ";
	}
	cout << endl;
	board.showCard();
	cout << endl;
}


void input(){  
	//Allows the winner of the last round to play first
	if (game_round > 0 && game_round % 2 == 0){
		int choice;
		do{
			cout << "Player "<<player+1<<" Play a card";
			cin >> choice;
		} while (choice >= players[player].getSize());
		board = players[player].playCard(choice);
	}
	else{
		if (players[player].hasSuite(board)){
			int choice;
			do{
				do{
					//cout << "Player " << player + 1 << " Play a card";
					//cin >> choice;
					choice = players[player].autosecond_player(board);
				} while (choice >= players[player].getSize());
			} while (!board.compareSuite(players[player].getCard(choice)));//Ensures player matches the board's suite
			board = players[player].playCard(choice);
		}
		else{
			while (!deck.isEmpty() && !board.compareSuite(players[player].getLastAdded())){//Lets the player search the deck
				/*cout << "You are about to draw a card" << endl;
				system("pause");*/
				players[player].addToHand(deck.getTopCard());
			}
			if (deck.isEmpty() && !board.compareSuite(players[player].getLastAdded())){//Player picks up the card on the board
				players[player].addToHand(board);
				board = Card(' ', -1, ' ');
			}
			else if (board.compareSuite(players[player].getLastAdded())){
				board = players[player].playLastAdded();
			}
		}
	}
}

void logic(){
	if (winner()){
		gameOver = true;
	}
	else{
		if (game_round % 2 == 1){
			if (board.isMoreThan(highest_on_the_board)){
				highest_on_the_board = board;
			}
			else{
				if (player == 0){
					player = 1;
				}
				else{
					player = 0;
				}
			}
		}
		else{
			highest_on_the_board = board;
			if (player == 0){
				player = 1;
			}
			else{
				player = 0;
			}
		}
		game_round++;
	}
}

int main(){
	setup();
	while (!gameOver){
		draw();
		input();
		logic();
	}
	system("pause");
}


//33 and 21