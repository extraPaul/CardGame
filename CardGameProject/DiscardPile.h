#include "Card.h"
#include <vector>

//should maybe be private?
class DiscardPile : public vector<Card*> {
public:
	DiscardPile& operator+= (Card*);
	Card* pickUp();
	Card* top();
	void print(ostream&);
	void printTop(ostream&);
	DiscardPile(istream&, const CardFactory*);
};