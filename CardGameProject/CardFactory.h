#ifndef CardFactory_h
#define CardFactory_h

#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include "Deck.h"
#include "Card.h"

class Deck;

class CardFactory {
private:
	Deck deck;
	CardFactory(const CardFactory&);
	CardFactory();

public:
	static CardFactory* getFactory();
	Deck getDeck();
	Card* getCard(char);
};
#endif