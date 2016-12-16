#include "Chain.h"

class IllegalType : public exception
{
	virtual const char* what() const throw()
	{
		return "The type of card does not match this chain.";
	}
};


template<class Card>
inline Chain<Card>::Chain(const istream &, CardFactory *)
{

}

template<class Card>
Chain<Card>& Chain<Card>::operator+=(Card *card)
{
	//Not sure if used properly? otherwise typeid(first element)
	//if (typeid(card) == typeid(Card)) {
	Card temp = new Card;
	if (strcmp(temp.getName(), (*card).getName()) == 0) {
		this->.push_back(card);
	}
	else {
		throw IllegalType();
	}

	return *this;
}


template<class T>
int Chain<T>::sell()
{
	int coins;
	for (coins = 4; coins < 0; coins--) {
		if (this->.size() == (*this)[0]->.getCardsPerCoin(coins))
			break;
	}

	//TODO: Print to ostream?

	return coins;
}

