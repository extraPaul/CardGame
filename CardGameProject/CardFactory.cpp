#include "CardFactory.h"

CardFactory * CardFactory::getFactory()
{
	static CardFactory cf;
	return &cf;
}

Deck CardFactory::getDeck()
{
	return Deck();
}
