#include "Card.h"

class Quartz : public Card {

public:

	int getCardsPerCoin(int coins) {
		if (0 < coins < 5)
			return 2 * coins + 2;
	}

	string getName() {
		return "Quartz";
	}

	void print(const ostream& out) {
		// ???
	}
};