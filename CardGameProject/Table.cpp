#include "Table.h"

Table::Table(string & name1, string & name2)
{
	CardFactory cf;
	Player player1(name1);
	Player player2(name2);
	players.push_back(player1);
	players.push_back(player2);
}

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

ostream & operator<<(ostream & out, Table t)
{
	for (Player player : t.players) {
		out << player << "\n";
	}
	out << "Top of discard pile: " << t.discard << "\n" << "Trading area: " << t.ta;
	return out;
}
