#include "Card.h"
#include <vector>
#include <list>

class TradeArea {
public:
	TradeArea();
	~TradeArea();
	TradeArea& operator += (Card*);
	bool legal(Card*);
	bool empty();
	Card* trade(string);
	int numCards();
	friend ostream & operator << (ostream &, TradeArea);
	TradeArea(istream&, const CardFactory* );
	list<Card*> cards;
	list<string> cardTypes;
};