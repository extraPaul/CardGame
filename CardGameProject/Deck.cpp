#include "Deck.h"

Deck::Deck(const istream &stream, CardFactory *cf)
{
	*this = (*cf).getDeck();
}

Card * Deck::draw()
{
	if (this->empty()) {
		//Erreur?
		return nullptr;
	}
	else {
		// lvalue is a value that still exist outside of here
		//temp = new Card;
		//return (*this).pop_back());
	}
}

Deck::Deck()
{
	//do nothing
}
