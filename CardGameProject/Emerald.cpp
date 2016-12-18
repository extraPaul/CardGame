#include "Card.h"

class Emerald : public Card {

public:
	const int NUMCARDS = 6;

	int getCardsPerCoin(int coins) {
		if (1 < coins && coins < 4)
			return coins;
	}

	string getName() {
		return "Emerald";
	}

	void print(ostream& out) const {
		out << "E";
	}
};