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

void DiscardPile::print(ostream & out)
{
	for (vector<Card*>::iterator it = this->begin(); it != this->end(); it++) {
		(*it)->print(out);
	}
}

DiscardPile::DiscardPile(istream &, const CardFactory *)
{
}

ostream & operator<<(ostream & out, DiscardPile dp)
{
	dp.back()->print(out);
	return out;
}
