#include <string>
#include <iostream>
#include "CardFactory.h"
#include <exception>
#include "Chain.h"
#include "Hand.h"

using namespace std;

class Player {
	string name;
	int numCoins;
	int maxNumChains;
	vector<Chain<Card>> chains;
	Hand *hand;

public:
	Player(std::string&);			// constructor that creates a Player with a given name.
	string getName();				// get the name of the player.
	int getNumCoins();				// get the number of coins currently held by the player.
	Player& operator+=(int);		// add a number of coins
	Player& operator+=(Card*);		// add a card to the player's hand
	int getMaxNumChains();			// returns either 2 or 3.
	int getNumChains();				// returns the number of non - zero chains
	Chain<>& operator[](int i);		// returns the chain at position i.
	void buyThirdChain();			//adds an empty third chain to the player for two coins
	void printHand(ostream&, bool); //prints the top card of the player's hand (with
									//argument false) or all of the player's hand (with 
									//argument true) to the supplied ostream.
	Player(istream&, CardFactory*); //constructor that accepts an istream and reconstruct the Player from file
	friend ostream & operator << (ostream &, Player);
	//template<class T> bool addChain();		//return false if the chain can't be added.
	//bool addToChain(Card*);
	void sellChain(int i);
	Hand* getHand() { return hand; }

private:
	void addChain(char);
};


class NotEnoughCoins : public exception
{
	virtual const char* what() const throw()
	{
		return "Not enough coins to buy a thirs chain";
	}

	friend ostream & operator << (ostream & out, NotEnoughCoins e) {
		out << e.what();
		return out;
	}

};

class ChainDoesntExist : public exception
{
	virtual const char* what() const throw()
	{
		return "Chain index is out of bounds";
	}

	
	
};