#include "Card.h"
#include <vector>
#include "CardFactory.h"

//Not sure how to do this properly...? 
template <class T = Card> class Chain : public vector<T*> {
public:
	// default constructor
	Chain() = default;
	Chain(istream&, CardFactory*);
	Chain<T>& operator+= (Card*);
	int sell();
	friend ostream & operator << (ostream &, Chain);
};
