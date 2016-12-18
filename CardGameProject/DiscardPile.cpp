#include "DiscardPile.h"

//Top card is the back of the vector.

DiscardPile::DiscardPile()
{
	//empty Discard pile
}

DiscardPile::~DiscardPile()
{
}

DiscardPile & DiscardPile::operator+=(Card *card)
{
	(*this).push_back(card);
	return *this;
}

Card * DiscardPile::pickUp()
{
	if (this->empty()) {
		throw domain_error("The discard pile is empty");
		return nullptr;
	}
	else {
		Card* temp = (*this).back();
		(*this).pop_back();
		return temp;
	}
}

Card * DiscardPile::top()
{
	return this->back();
}

/*
Text File Format:
Line 1: Char for each card in discard
*/

void DiscardPile::print(ostream & out)
{
	for (vector<Card*>::iterator it = this->begin(); it != this->end(); it++) {
		(*it)->print(out);
	}
}

DiscardPile::DiscardPile(istream & in, /*const*/ CardFactory *cf)		//deleted the const adapt method otherwise
{
	char cardType[150];
	char dummy[50];
	in.getline(dummy, 256);//line title in the file
	in.getline(cardType, 256);
	int i = 0;
	while (cardType[i] == NULL) {
		Card* cardToAdd = ((*cf).getCard(cardType[i]));
		(*this).push_back(cardToAdd);										//check if right order
	}

}



ostream & operator<<(ostream & out, DiscardPile dp)
{
	dp.back()->print(out);
	return out;
}
