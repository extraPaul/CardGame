#pragma once
#include "Card.h"


class CardFactory {
private:
	CardFactory(const CardFactory&);
	CardFactory();

public:
	static CardFactory* getFactory();
	Deck getDeck();
};
