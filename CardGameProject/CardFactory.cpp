#include "CardFactory.h"
#include "Amethyst.cpp"
#include "Emerald.cpp"
#include "Hematite.cpp"
#include "Malachite.cpp"
#include "Obsidian.cpp"
#include "Quartz.cpp"
#include "Ruby.cpp"
#include "Turquoise.cpp"


CardFactory::CardFactory() {
	for (int i = 0; i < 8; i++)
	{
		Amethyst newCard;
		deck.push_back(newCard);
	}
	for (int i = 0; i < 6; i++)
	{
		Emerald newCard;
		deck.push_back(newCard);
	}
	for (int i = 0; i < 18; i++)
	{
		Hematite newCard;
		deck.push_back(newCard);
	}
	for (int i = 0; i < 14; i++)
	{
		Malachite newCard;
		deck.push_back(newCard);
	}
	for (int i = 0; i < 16; i++)
	{
		Obsidian newCard;
		deck.push_back(newCard);
	}
	for (int i = 0; i < 20; i++)
	{
		Quartz newCard;
		deck.push_back(newCard);
	}
	for (int i = 0; i < 10; i++)
	{
		Ruby newCard;
		deck.push_back(newCard);
	}
	for (int i = 0; i < 12; i++)
	{
		Turquoise newCard;
		deck.push_back(newCard);
	}
}

CardFactory * CardFactory::getFactory()
{
	static CardFactory cf;
	return &cf;
}

Deck CardFactory::getDeck()
{
	// obtain a time-based seed -- source: cplusplus.com/reference/algorithm/shuffle/
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(deck.begin(), deck.end(), default_random_engine(seed));

	return deck;
}
