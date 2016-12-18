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
	Card * newCard;
	for (int i = 0; i < 8; i++)
	{
		newCard = new Amethyst();
		deck.push_back(newCard);
	}
	for (int i = 0; i < 6; i++)
	{
		newCard = new Emerald();
		deck.push_back(newCard);
	}
	for (int i = 0; i < 18; i++)
	{
		newCard = new Hematite();
		deck.push_back(newCard);
	}
	for (int i = 0; i < 14; i++)
	{
		newCard = new Malachite();
		deck.push_back(newCard);
	}
	for (int i = 0; i < 16; i++)
	{
		newCard = new Obsidian();
		deck.push_back(newCard);
	}
	for (int i = 0; i < 20; i++)
	{
		newCard = new Quartz();
		deck.push_back(newCard);
	}
	for (int i = 0; i < 10; i++)
	{
		newCard = new Ruby();
		deck.push_back(newCard);
	}
	for (int i = 0; i < 12; i++)
	{
		newCard = new Turquoise();
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


Card* CardFactory::getCard(char type) {
	Card * newCard = NULL;

	if (type == 'Q') {
		newCard = new Quartz();
	}
	else if (type == 'H') {
		newCard = new Hematite();
	}
	else if (type =='O') {
		newCard = new Obsidian();
	}
	else if (type == 'M') {
		newCard = new Malachite();
	}
	else if (type == 'M') {
		newCard = new Turquoise();
	}
	else if (type == 'M') {
		newCard = new Ruby();
	}
	else if (type == 'A') {
		newCard = new Amethyst();
	}
	else if (type == 'E') {
		newCard = new Emerald();
	}

	return newCard;

}