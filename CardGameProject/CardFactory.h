#ifndef CardFactory_h
#define CardFactory_h

#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include "Deck.h"
#include "Card.h"
#include "Amethyst.cpp"
#include "Emerald.cpp"
#include "Hematite.cpp"
#include "Malachite.cpp"
#include "Obsidian.cpp"
#include "Quartz.cpp"
#include "Ruby.cpp"
#include "Turquoise.cpp"

class Deck;

class CardFactory {
private:
	Deck *deck;
	CardFactory(const CardFactory&);
	CardFactory();

public:
	static CardFactory* getFactory();
	Deck getDeck();
	Card* getCard(char);
	void setDeck (istream &);
};
#endif