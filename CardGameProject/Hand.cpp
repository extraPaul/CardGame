#include "hand.h"
#include <string>
#include <iostream>

//back est la premiere carte 
//size - position pour avoir la position

Hand& Hand ::operator+=(Card*) {




}//a joute une carte derrière la dernière carte de la main.

Card* Hand :: play() {
	Card* temp = &(*this).back();
	(*this).pop_back();
	return temp;

}//renvoie et supprime la première carte de la main du joueur .

Card* Hand ::top() {
	return &(*this).back();
}//renvoie mais ne supprime pas la première carte de la main du joueur.

Card* Hand ::operator[](int position) {
	Card* temp = &(*this).at((*this).size() - position);
	(*this).erase( (*this).begin() + ((*this).size()-position) );
	return temp;
}//renvoie et supprime une carte à une position donnée.






Hand:: Hand(const istream&, CardFactory*) {}													//implementer


 //Ajouter également un opérateur d'insertion pour Hand dans un std::ostream. La main doit afficher
 //toutes les cartes dans l'ordre.
ostream & operator<<(ostream & out, Hand h)
{
	// TODO: make sure cards are in order
	for (vector<Card>::iterator it = h.begin(); it != h.end(); it++) {
		(*it).print(out);
	}
	return out;
}
