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
	Deck(istream&, CardFactory*);
	Deck(CardFactory*);
	Card* draw();
	friend ostream & operator << (ostream &, Deck);
};
#endif

class DeckEmpty : public exception
{
	virtual const char* what() const throw()
	{
		return "The deck is empty.";
	}
};