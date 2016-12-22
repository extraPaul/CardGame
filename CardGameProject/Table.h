#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "CardFactory.h"
#include <iostream>
#include <fstream>

class Table {
public:
	vector<Player> players;
	Deck *deck;
	DiscardPile *discard;
	TradeArea *ta;

public:
	Table(string& name1, string& name2);
	~Table();
	bool win(string&);
	friend ostream & operator << (ostream &, Table);
	Table(istream&, CardFactory*);

};