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

//On assume qu'un joueur a seulement besoins d'acheter une troisième chaine 1 fois.
void Player:: buyThirdChain() {
	if (numCoins < 3)
		throw NotEnoughCoins();
	else {
		numCoins = numCoins - 3;
													//la troisieme chaine est elle dans le bon ordre
		maxNumChains++;
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

}

template<class T>
inline bool Player::addChain()
{
	if (chains.size() <= maxNumChains) {
		Chain<T> newChain;
		chains.push_back(newChain);
		return true;
	}
	//else
	return false;
}


bool Player::addToChain(Card * card)
{
	if (chains.size() < maxNumChains) {
		char type = card->getName()[0];
		if (type == 'Q') {
			addChain<Quartz>();
		}
		else if (type == 'H') {
			addChain<Hematite>();
		}
		else if (type == 'O') {
			addChain<Obsidian>();
		}
		else if (type == 'M') {
			addChain<Malachite>();
		}
		else if (type == 'M') {
			addChain<Turquoise>();
		}
		else if (type == 'M') {
			addChain<Ruby>();
		}
		else if (type == 'A') {
			addChain<Amethyst>();
		}
		else if (type == 'E') {
			addChain<Emerald>();
		}

		chains.back() += card;
		return true;
	}
	//else
	for (int i = 0; i < chains.size(); i++) {
		if ((*this)[i].legal(card)) {
			(*this)[i] += card;
			return true;
		}
	}
	//else
	return false;
}


//constructor that accepts an istream and reconstruct the Player from file
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