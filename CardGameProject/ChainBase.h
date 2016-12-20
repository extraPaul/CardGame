#include "Card.h"

class ChainBase {
protected:
	virtual void addCard(Card*) = 0;
public:
	virtual bool legal(Card*) = 0;
	virtual int sell() = 0;
	ChainBase& operator+= (Card* card) {
		this->addCard(card);
		return *this;
	};
};