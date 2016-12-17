#include "Deck.h"

Deck::Deck(const istream &stream, CardFactory *cf)
{
	*this = (*cf).getDeck();
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

Deck::Deck()
{
	//do nothing
}

ostream & operator<<(ostream & out, Deck d)
{
	for (vector<Card*>::iterator it = d.begin(); it != d.end(); it++) {
		(*it)->print(out);
	}
	return out;
}