#include "Card.h"
#include <vector>
#include "CardFactory.h"

//Not sure how to do this properly...? 
template <class T = Card> class Chain : public vector<T*> {
public:
	// default constructor
	Chain() = default;
	Chain(istream&, CardFactory*);
	bool legal(Card*);						//returns true if it's legal to add the card to the chain.
	Chain<T>& operator+= (Card*);
	int sell();
	friend ostream & operator << (ostream &, Chain);
};
