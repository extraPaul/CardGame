#include "Card.h"
#include <vector>

class TradeArea {
public:
	TradeArea& operator += (Card*);
	bool legal(Card*);
	Card* trade(string);
	int numCards();
	void print(ostream&);		//insert to ostream?
	TradeArea(istream&, const CardFactory*);
};