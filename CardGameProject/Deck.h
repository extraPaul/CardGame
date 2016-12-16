#include "Card.h"
#include <vector>


class Deck : public vector<Card> {
public:
	Deck(const istream&, CardFactory*);
	Deck();
	Card* draw();
};
