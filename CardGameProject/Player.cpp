#include "Player.h"

Player:: Player(string &playerName) {											//quoi faire avec la reference
	name = playerName;
	numCoins = 0;
	maxNumChains = 2;
	chains.push_back(Chain<Card>());					//not sure if I should add this
	chains.push_back(Chain<Card>());
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
		if (chains[i].size !=0)
			count++;
	}
	return count;

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
	//char cardType[150];
	//in.getline(cardType, 256);
	
	cin >> name >> numCoins;

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
	out << p.getName() << ' ' << p.getNumCoins() << " coins\n";
	for (int i = 0; i < p.getNumChains; i++)
		out << p[i] << '\n';

	return out;
}
