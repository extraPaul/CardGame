#include "Card.h"

class Amethyst : public Card {

public:
	const static int NUMCARDS = 8;	//Possiblement inutile

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