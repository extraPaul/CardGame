#include "Card.h"

class Malachite : public Card {

public:
	const int NUMCARDS = 14;

	int getCardsPerCoin(int coins) {
		if (1 < coins && coins < 5)
			return coins + 3;
		else if (coins == 1)
			return 3;
		return 0;
	}

	string getName() {
		return "Malachite";
	}

	void print(ostream& out) const {
		out << "M";
	}
};