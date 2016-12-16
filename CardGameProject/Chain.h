#include "Card.h"
#include <vector>


template <class Card> class Chain : public vector<Card*> {
public:
	Chain(const istream&, CardFactory*);
	Chain<Card>& operator+= (Card*);
	int sell();
};
