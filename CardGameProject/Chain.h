#include "Card.h"
#include <vector>


template <class T> class Chain : public vector<T> {
public:
	Chain(const istream&, CardFactory*);
	Chain<T>& operator+= (Card*);
	int sell();
};
