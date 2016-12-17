#include "Card.h"

class Obsidian : public Card {

public:
	const int NUMCARDS = 16;

	int getCardsPerCoin(int coins) {
		if (0 < coins < 4)
			return 2 * coins + 1;
		else if (coins == 4)
			return 8;
	}

	string getName() {
		return "Obsidian";
	}

	void print(ostream& out) {
		out << "O";
	}
};