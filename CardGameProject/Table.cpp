#include "Table.h"

Table::~Table()
{
}

bool Table::win(string & name)
{
	//If there is no player, returns the player in the lead.
	if (players[0].getNumCoins() > players[1].getNumCoins())
		name = players[0].getName();
	else
		name = players[1].getName();
	return deck.empty();
}

void Table::printHand(bool)
{
}

Table::Table(istream & in, const CardFactory* cf)
{

}

ostream & operator<<(ostream &, Table)
{
	// TODO: insert return statement here
}
