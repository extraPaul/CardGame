#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table {
public:
	vector<Player> players;
	Deck deck;
	DiscardPile discard;
	TradeArea ta;

public:
	Table();
	~Table();
	bool win(string&);
	void printHand(bool);
	friend ostream & operator << (ostream &, Table);
	Table(istream&, const CardFactory*);
};