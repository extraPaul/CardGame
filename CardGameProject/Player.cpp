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
	getline(in,name, '\t');
	in >> numCoins;
	char dummy[150];
	in.getline(dummy, 150); //word coins
	while (in.peek() != '\t') {
		//add chain here 
		//chains.push_back(new Chain<Card>(in, cf));
	}

}

template<class T>
bool Player::addChain() {
	static_assert(std::is_base_of<Card, T>::value, "T is not derived from Card");
	if (chains.size() <= maxNumChains) {
		T temp;
		addChain(temp.getName()[0]);
		return true;
	}
	//else
	return false;
}


bool Player::addToChain(Card * card)
{
	if (chains.size() < maxNumChains) {
		addChain(card->getName()[0]);
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

void Player::sellChain(int i){
	numCoins += chains[i].sell();
	chains.erase(chains.begin() + i);
}

void Player::addChain(char type)
{
	Chain<> newChain;
	if (type == 'Q') {
		Chain<Quartz> newChain;
	}
	else if (type == 'H') {
		Chain<Hematite> newChain;
	}
	else if (type == 'O') {
		Chain<Obsidian> newChain;
	}
	else if (type == 'M') {
		Chain<Malachite> newChain;
	}
	else if (type == 'T') {
		Chain<Turquoise> newChain;
	}
	else if (type == 'R') {
		Chain<Ruby> newChain;
	}
	else if (type == 'A') {
		Chain<Amethyst> newChain;
	}
	else if (type == 'E') {
		Chain<Emerald> newChain;
	}
	chains.push_back(newChain);
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
	out << p.getName() << '\t' << p.getNumCoins() << " coins\n";
	for (int i = 0; i < p.getNumChains(); i++)
		out << p[i] << '\n';
	out << '\t';
	return out;
}