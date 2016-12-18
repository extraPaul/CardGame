#include "hand.h"
#include <string>
#include <iostream>

//back est la premiere carte 
//size - position pour avoir la position

Hand& Hand ::operator+=(Card*cardToAdd) {
	(*this).push_back(cardToAdd);
	return *this;

}//a joute une carte derrière la dernière carte de la main.

Card* Hand :: play() {
	Card* temp = (*this).back();
	(*this).pop_back();
	return temp;

}//renvoie et supprime la première carte de la main du joueur .

Card* Hand ::top() {
	return (*this).back();
}//renvoie mais ne supprime pas la première carte de la main du joueur.

Card* Hand ::operator[](int position) {
	Card* temp = (*this).at((*this).size() - position);
	(*this).erase( (*this).begin() + ((*this).size()-position) );
	return temp;
}//renvoie et supprime une carte à une position donnée.


Hand:: Hand(std::istream& in, CardFactory* cf) {
	char cardType[150];
	char dummy[50];
	in.getline(dummy, 256); //line title in the file
	in.getline(cardType, 256);
	int i = 0;
	while (cardType[i] == NULL) {
		Card* cardToAdd = ((*cf).getCard(cardType[i]));
		(*this).push_back(cardToAdd);										//check if right order
	}

}													


 /*
 Text File Format:
 Line 1: Char for each card
 */
ostream & operator<<(ostream & out, Hand h)
{
	// TODO: make sure cards are in order
	for (vector<Card>::iterator it = h.begin(); it != h.end(); it++) {
		(*it).print(out);
	}
	return out;
}
