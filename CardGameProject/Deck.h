#ifndef Deck_h
#define Deck_h

#include "Card.h"
#include <vector>
#include "CardFactory.h"
class CardFactory;

class Deck : public vector<Card*> {
public:
	// default constructor
	Deck() = default;
	Deck(const istream&, CardFactory*);
	Deck(CardFactory*);
	Card* draw();
	friend ostream & operator << (ostream &, Deck);
};
#endif
