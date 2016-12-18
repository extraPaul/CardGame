#include "Card.h"
#include <vector>


class Deck : public vector<Card*> {
public:
	Deck(const istream&, CardFactory*);
	Deck(CardFactory*);
	Card* draw();
	friend ostream & operator << (ostream &, Deck);
};
