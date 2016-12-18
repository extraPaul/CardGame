#include "Player.h"

Player:: Player(string &playerName) {											//quoi faire avec la reference
	name = playerName;
	numCoins = 0;
	maxNumChains = 2;
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
	return chains.size();

}


 Chain<Card> & Player:: operator[](int i) {												//implementer?
	 return chains[i];
}


void Player:: buyThirdChain() {
	if (numCoins < 2)
		throw NotEnoughCoins();
	else {
		numCoins = numCoins - 2;
													//la troisieme chaine est elle dans le bon ordre
		chains.resize(3);
	}

}

void Player::printHand(ostream&, bool) {

																					//implementer

}//prints the top card of the player's hand (with
								//argument false) or all of the player's hand (with 
								//argument true) to the supplied ostream.


Player:: Player(istream& in, CardFactory* cf) {
	getline(in,name, '\t');
	in >> numCoins;
	char dummy[150];
	in.getline(dummy, 150); //word coins
	while (in.peek() != '\t') {
		//add chain here 
		//chains.push_back(new Chain<Card>(in, cf));
	}

}//constructor that accepts an istream and reconstruct the Player from file


 /*
 Text File Format:
 Line 1: name /t nb of coins
 Line 2: chain 1 info  **if not null
 Line 3: chain 2 info  **if not null
 Line 4: chain 3 info  **if not null
 */

ostream & operator<<(ostream & out, Player p)
{
	out << p.getName() << '\t' << p.getNumCoins() << " coins\n";
	for (int i = 0; i < p.getNumChains(); i++)
		out << p[i] << '\n';
	out << '\t';
	return out;
}

template<class T>
inline bool Player::addChain()
{
	return false;
}
