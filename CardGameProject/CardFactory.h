#include "Deck.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>


class CardFactory {
private:
	Deck deck;
	CardFactory(const CardFactory&);
	CardFactory();

public:
	static CardFactory* getFactory();
	Deck getDeck();
};
