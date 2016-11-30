#pragma once
#include "Card.h"
#include <random>
#include <algorithm>
#include <iterator>


class CardFactory {
private:
	Deck deck;
	CardFactory(const CardFactory&);
	CardFactory();

public:
	static CardFactory* getFactory();
	Deck getDeck();
};
