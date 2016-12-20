#include "Deck.h"

Deck::Deck(istream &in, CardFactory *cf)
{
	(*this).clear();
	char cardType[256];
	in.getline(cardType, 256);
	int i = 0;
	while (cardType[i] == NULL) {
		Card* cardToAdd = ((*cf).getCard(cardType[i]));
		(*this).push_back(cardToAdd);										//check if right order
		i++;
	}
	cf->setDeck(this);
}

Card * Deck::draw()
{
	if (this->empty()) {
		throw domain_error("The deck is empty");
		return nullptr;
	}
	else {
		Card* temp = (*this).back();
		(*this).pop_back();
		return temp;
	}
}

Deck::Deck(CardFactory* cf)
{
	cout << "good constructor";

	*this = (*cf).getDeck();
}


/*
Text File Format:
Line 1: Char for each card
*/

ostream & operator<<(ostream & out, Deck d) {
	for (vector<Card*>::iterator it = d.begin(); it != d.end(); it++) {
		out << (*it);
	}
	return out;
}