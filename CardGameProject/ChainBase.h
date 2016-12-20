#include "Card.h"

class ChainBase {
protected:
	virtual void addCard(Card*) = 0;
	virtual void print(ostream&) const = 0;
public:
	virtual bool legal(Card*) = 0;
	virtual int sell() = 0;
	virtual int getSize() = 0;
	virtual string getType() = 0;
	friend ostream & operator << (ostream & o, const ChainBase& cb) {
		cb.print(o);
		return o;
	};
	ChainBase& operator+= (Card* card) {
		this->addCard(card);
		return *this;
	};
};