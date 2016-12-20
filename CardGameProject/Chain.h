#include "ChainBase.h"
#include <vector>
#include "CardFactory.h"


template <class T> class Chain : public ChainBase, public vector<T*> {
public:
	// default constructor
	Chain();
	Chain(istream&, CardFactory*);
	bool legal(Card*);						//returns true if it's legal to add the card to the chain.
	Chain<T>& operator+= (Card* card);
	int sell();
	friend ostream & operator << (ostream & sortie, Chain c) {
		sortie << c[0]->getName() << '\t';
		for (vector<T*>::iterator it = c.begin(); it != c.end(); it++) {
			sortie << " ";
			(*it)->print(sortie);
		}
		return sortie;
	};
	void addCard(Card* );
	int getSize();
	string getType();
protected:
	string type;
	void print(ostream& o) const {
		o << (*this);
	};
};

class IllegalType : public exception
{
	virtual const char* what() const throw()
	{
		return "The type of card does not match this chain.";
	}
};


template<class T>
inline Chain<T>::Chain()
{
	T temp;
	type = temp.getName();
}

template<class T>
Chain<T>::Chain(istream & in , CardFactory * cf)
{

	string chainTitle;
	getline(in, chainTitle, '\t');
	char type[256];
	in.getline(type, 256);

	while (type != NULL) {
		if (type != ' ') {
			Card* cardToAdd = ((*cf).getCard(type));
			(*this).push_back(cardToAdd);
		}															//check if right order
		i++;
	}

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
		T* temp = new T();
		this->push_back(temp);
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

template<class T>
void Chain<T>::addCard(Card * card)
{
	(*this) += card;
}

template<class T>
inline int Chain<T>::getSize()
{
	return this->size();
}

template<class T>
inline string Chain<T>::getType()
{
	return type;
}

/*
Text File Format:
Line 1: CardType Name \t X X X			 (amount of time)
*/


/*template<class T>
ostream & operator<<(ostream & sortie, Chain<T> c)
{
	sortie << c[0]->getName() << '\t';
	for (vector<T*>::iterator it = c.begin(); it != c.end(); it++) {
		sortie << " ";
		(*it)->print(sortie);
	}
	return sortie;
}*/
