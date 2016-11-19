#include "Card.h"

class Hematite : public Card {

public:

	int getCardsPerCoin(int coins) {
		switch (coins) {
		case 1:
			return 3;
			break;
		case 2:
			return 6;
			break;
		case 3:
			return 8;
			break;
		case 4:
			return 9;
			break;
		default:
			//throw exception?
			break;
		}
	}

	string getName() {
		return "Hematite";
	}

	void print(const ostream& out) {
		// ???
	}
};