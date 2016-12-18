#ifndef Card_h
#define Card_h

#include <iostream>
#include <string>

using namespace std;

class Card {
public:
	virtual int getCardsPerCoin(int) = 0;
	virtual string getName() = 0;
	virtual void print(ostream&) = 0;
};
#endif