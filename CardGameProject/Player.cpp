#include "Player.h"

Player:: Player(string &playerName) {											//quoi faire avec la reference
	name = playerName;
	numCoins = 0;
	maxNumChains = 2;
	hand = new Hand();
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
	*hand += card;
	return *this;
}

int Player:: getMaxNumChains() {
	return maxNumChains;
}

int Player::getNumChains() {
	return chains.size();

}


 ChainBase& Player:: operator[](int i) {	
	 if (i < getNumChains())
		 return chains[i];
	 else
		 throw ChainDoesntExist();
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

void Player::printHand(ostream& out, bool notTopCard) {
	if (notTopCard) {
		out << *hand;
	}
	else {

		out << hand->top();
	}
																					

}//prints the top card of the player's hand (with
								//argument false) or all of the player's hand (with 
								//argument true) to the supplied ostream.


Player:: Player(istream& in, CardFactory* cf) {
	getline(in,name, '\t');

	in >> numCoins;
	in >> maxNumChains;
	hand = new Hand(in, cf);
	char type;
	int size;
	string chainInfo;
	string tmp;
	for (int i = 0; i < 3; i++) {
		getline(in, chainInfo);
		if (chainInfo.compare("NULL") != 0) {
			type = chainInfo.at(0);
			size = atoi(chainInfo.substr(2).c_str());
			addChain(type);
			for (int i = 0; i < size; i++) {
				addToChain(cf->getCard(type));
			}

		}

	}

	//add chain here 
	//chains.push_back(new Chain<Card>(in, cf));
	

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
	if (card == nullptr)
		return false;
	for (int i = 0; i < chains.size(); i++) {
		if ((*this)[i].legal(card)) {
			(*this)[i] += card;
			return true;
		}
	}
	//else
	if (chains.size() < maxNumChains) {
		addChain(card->getName()[0]);
		chains.back() += card;
		return true;
	}
	//else
	return false;
}

void Player::sellChain(int i){
	cout << "numcoins avant " << numCoins << endl;
	numCoins += chains[i].sell();
	cout << "numcoins apres " << numCoins << endl;
	chains.removeChain(i);
}

void Player::addChain(char type)
{
	if (type == 'Q') {
		ChainBase* newChain = new Chain<Quartz>;
		chains.addChain(newChain);
	}
	else if (type == 'H') {
		ChainBase* newChain = new Chain<Hematite>;
		chains.addChain(newChain);
	}
	else if (type == 'O') {
		ChainBase* newChain = new Chain<Obsidian>;
		chains.addChain(newChain);
	}
	else if (type == 'M') {
		ChainBase* newChain = new Chain<Malachite>;
		chains.addChain(newChain);
	}
	else if (type == 'T') {
		ChainBase* newChain = new Chain<Turquoise>;
		chains.addChain(newChain);
	}
	else if (type == 'R') {
		ChainBase* newChain = new Chain<Ruby>;
		chains.addChain(newChain);
	}
	else if (type == 'A') {
		ChainBase* newChain = new Chain<Amethyst>;
		chains.addChain(newChain);
	}
	else if (type == 'E') {
		ChainBase* newChain = new Chain<Emerald>;
		chains.addChain(newChain);
	}
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
		out << p[i] << "\n";
	return out;
}

void Player::print(ostream & out)				//print all cards
{	
	//addChain<Quartz>();
	//addToChain(new Quartz());
	out << getName() << '\t' << getNumCoins() << ' ' << getMaxNumChains() << "\n";
	out << *hand << "\n";
	for (int i = 0; i < 3; i++){
		if (i < getNumChains())
			out << chains[i].getType().at(0) << " " << chains[i].getSize() << "\n";
		else
			out << "NULL" << "\n";
	}
		
}