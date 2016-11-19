#include "Card.h"

class Malachite : public Card {

public:

	int getCardsPerCoin(int coins) {
		if (1 < coins < 5)
			return coins + 3;
		else if (coins == 1)
			return 3;
	}

	string getName() {
		return "Malachite";
	}

	void print(const ostream& out) {
		// ???
	}
};