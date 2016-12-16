#include "Chain.h"

template<class T>
inline Chain<T>::Chain(const istream &, CardFactory *)
{

}

template<class T>
Chain<T>& Chain<T>::operator+=(Card *card)
{
	//Not sure if used properly? otherwise typeid(first element)
	if (typeid(card) == typeid(T)) {
		this->.push_back(card);
	}
	else {

	}

	// TODO: insert return statement here
}

template<class T>
int Chain<T>::sell()
{
	return 0;
}

