#include "Card.h"
#include <vector>
#include <list>

class TradeArea {
public:
	TradeArea();
	~TradeArea();
	TradeArea& operator += (Card*);
	bool legal(Card*);
	Card* trade(string);
	int numCards();
	friend ostream & operator << (ostream &, TradeArea);
	TradeArea(istream&, const CardFactory*);
private:
	list<Card*> cards;
	list<string> cardTypes;
};