#include "Chain.h"

class IllegalType : public exception
{
	virtual const char* what() const throw()
	{
		return "The type of card does not match this chain.";
	}
};


template<class T>
inline Chain<T>::Chain(const istream &, CardFactory *)
{

}

template<class T>
bool Chain<T>::legal(Card *card)
{
	T temp;
	return (temp.getName().compare((*card).getName()) == 0);
}

template<class T>
Chain<T>& Chain<T>::operator+=(Card *card)
{
	//Not sure if used properly? otherwise typeid(first element)
	//if (typeid(card) == typeid(Card)) {

	if (legal(card)) {
		this->push_back(card);
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
		if (this->size() == (*this)[0]->getCardsPerCoin(coins))
			break;
	}

	return coins;
}

/*
Text File Format:
Line 1: CardType Name \t X X X			 (amount of time)
*/


template<class T>
ostream & operator<<(ostream & sortie, Chain<T> c)
{
	sortie << c[0]->getName() << '\t';
	for (vector<T*>::iterator it = c.begin(); it != c.end(); it++) {
		sortie << " ";
		(*it)->print(sortie);
	}
	return sortie;
}