#include "Card.h"

class Ruby : public Card {

public:

	int getCardsPerCoin(int coins) {
		if (1 < coins < 5)
			return coins + 2;
		else if (coins == 1)
			return 2;
	}

	string getName() {
		return "Ruby";
	}

	void print(const ostream& out) {
		// ???
	}
};