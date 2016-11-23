#pragma once
#include "Card.h"
#include <vector>


class Deck : public vector<Card> {
public:
	Deck(const istream&, CardFactory*);
	Card* draw();
};
