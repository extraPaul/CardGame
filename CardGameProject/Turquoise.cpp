#include "Card.h"

class Turquoise : public Card {

public:
	const int NUMCARDS = 12;

	int getCardsPerCoin(int coins) {
		if (0 < coins < 4)
			return 2 * coins;
		else if (coins == 4)
			return 7;
	}

	string getName() {
		return "Turquoise";
	}

	void print(const ostream& out) {
		// ???
	}
};