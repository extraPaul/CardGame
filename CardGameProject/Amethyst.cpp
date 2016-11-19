#include "Card.h"

class Amethyst : public Card {

public:

	int getCardsPerCoin(int coins) {
		if (0 < coins < 5)
			return coins + 1;
	}

	string getName() {
		return "Amethyst";
	}

	void print(const ostream& out) {
		// ???
	}
};