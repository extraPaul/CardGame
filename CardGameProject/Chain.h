#include "Card.h"
#include <vector>

//Not sure how to do this properly...? 
template <class T = Card> class Chain : public vector<T*> {
public:
	// default constructor
	Chain() = default;
	Chain(const istream&, CardFactory*);
	Chain<T>& operator+= (Card*);
	int sell();
	friend ostream & operator << (ostream &, Chain);
};
