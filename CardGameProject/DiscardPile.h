#include "CardFactory.h"
#include <vector>

//should maybe be private?
class DiscardPile : public vector<Card*> {
public:
	DiscardPile();
	~DiscardPile();
	DiscardPile& operator+= (Card*);
	Card* pickUp();
	Card* top();
	void print(ostream&);
	friend ostream & operator << (ostream &, DiscardPile);
	DiscardPile(istream&, CardFactory*);
};