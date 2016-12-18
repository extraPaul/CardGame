#include "TradeArea.h"

//Helper function
template <typename Container>
bool contains(Container const& c, typename Container::const_reference v) {
	return std::find(c.begin(), c.end(), v) != c.end();
}

template<class InputIterator, class T>
InputIterator findName(InputIterator first, InputIterator last, const T& val)
{
	while (first != last) {
		if ((*first)->getName().compare(val) == 0) return first;
		++first;
	}
	return last;
}

template <typename Container>
bool containsName(Container const& c, typename Container::const_reference v) {
	list<Card*>::iterator first = c.begin();
	list<Card*>::iterator last = c.end();
	while (first != last) {
		if ((*first)->getName().compare(v) == 0) return true;
		++first;
	}
	return false;
}

TradeArea::TradeArea()
{
}

TradeArea::~TradeArea()
{
	//Make sure that each card is deleted.
	for (auto&& card : cards){
		delete card;
	}
	cards.clear();
	cardTypes.clear();
}

TradeArea & TradeArea::operator+=(Card *card)
{
	
	/*list<list<Card*>::iterator>::iterator first = cardTypes.begin();
	list<list<Card*>::iterator>::iterator last = cardTypes.end();
	while (first != last) {
		if ((**first)->getName().compare(card->getName()) == 0) {
			cards.push_front(card);

		}
		++first;
	}*/

	cards.push_front(card);
	if (!contains(cardTypes, card->getName()))
		cardTypes.push_front(card->getName());

	return *this;
}

bool TradeArea::legal(Card *card)
{
	return (cards.size() < 3 || contains(cardTypes, card->getName()));
}

bool TradeArea::empty()
{
	return cards.empty();
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

TradeArea::TradeArea(istream &, const CardFactory *)
{
}

/*
Text File Format:
Line 1: Char for each card
*/

ostream & operator<<(ostream & out, TradeArea ta)
{
	for (list<Card*>::iterator it = ta.cards.begin(); it != ta.cards.end(); it++) {
		(*it)->print(out);
	}
	return out;
}
