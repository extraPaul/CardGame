#ifndef Card_h
#define Card_h

#include <iostream>
#include <string>

using namespace std;

class Card {
public:
	virtual int getCardsPerCoin(int) = 0;
	virtual string getName() = 0;
	friend ostream& operator << (ostream& o, const Card& c);
	friend ostream& operator << (ostream& o, const Card* c);
protected:
	virtual void print(ostream&) const = 0;
};

inline ostream & operator<<(ostream & o, const Card & c)
{
	c.print(o);
	return o;
}

inline ostream & operator<<(ostream & o, const Card* c)
{
	o << (*c);
	return o;
}
#endif

