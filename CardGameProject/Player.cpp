#include "Player.h"

Player:: Player(string &playerName) {											//quoi faire avec la reference
	name = playerName;
	numCoins = 0;
	maxNumChains = 2;
	chain = new Chain<>[2];
	chain[0] = NULL;
    chain[1] = NULL;

}


string Player :: getName() {
	return name;
}

int Player:: getNumCoins() {
	return numCoins;
}

Player& Player:: operator +=(int i) {
	numCoins = numCoins + i;
	return(*this);
}

Player & Player::operator+=(Card *card)
{
	hand += card;
	return *this;
}

int Player:: getMaxNumChains() {
	return maxNumChains;
}

int Player::getNumChains() {
	int count=0;
	for (int i = 0; i < maxNumChains; i++) {
		if (chain[i] != NULL)
			count++;
	}
	return count;

}


 Chain<>& Player:: operator[](int i) {															//implementer?
	 return chain[i];
}


void Player:: buyThirdChain() {
	if (numCoins < 2)
		throw NotEnoughCoins();
	else {
		numCoins = numCoins - 2;
		*(chain + 2) = new Chain;											//la troisieme chaine est elle dans le bon ordre

		chain[2] = NULL;
	}

}

void Player::printHand(ostream&, bool) {

																					//implementer

}//prints the top card of the player's hand (with
								//argument false) or all of the player's hand (with 
								//argument true) to the supplied ostream.

Player:: Player(const istream&, CardFactory*) {
																					//implementer

}//constructor that accepts an istream and reconstruct the Player from file

ostream & operator<<(ostream & out, Player p)
{
	out << p.getName() << '\t' << p.getNumCoins() << " coins\n";
	for (int i = 0; i < p.getNumChains; i++)
		out << p[i] << '\n';

	return out;
}
