#include "TradeArea.h"

//Helper function
template <typename Container>
bool contains(Container const& c, typename Container::const_reference v) {
	return std::find(c.begin(), c.end(), v) != c.end();
}

TradeArea & TradeArea::operator+=(Card *card)
{
	cards.push_front(card);
	if (!contains(cardTypes, card->getName()))
		cardTypes.push_front(card->getName());

	return *this;
}

bool TradeArea::legal(Card *card)
{
	return (cards.size() < 3 || contains(cardTypes, card->getName()));
}

Card * TradeArea::trade(string name)
{
	list<Card*>::iterator it = cards.begin();
	while (it != cards.end()) {
		if (name.compare((*(*it)).getName()) == 0) {
			Card* temp = *it;
			cards.erase(it);
			return temp;
		}
	}
	//If there is no card of that type:
	return nullptr;
}

int TradeArea::numCards()
{
	return cards.size();
}

void TradeArea::print(ostream &)
{
}

TradeArea::TradeArea(istream &, const CardFactory *)
{
}
