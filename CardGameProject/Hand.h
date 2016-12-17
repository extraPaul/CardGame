#pragma once
#include "CardFactory.h"

class Hand : public vector<Card> {
private:


public:
	Hand& operator+=(Card*);				//a joute une carte derrière la dernière carte de la main.
	Card* play();							//renvoie et supprime la première carte de la main du joueur .
	Card* top();							//renvoie mais ne supprime pas la première carte de la main du joueur.
	Card* operator[](int);					//renvoie et supprime une carte à une position donnée.
	Hand(const istream&, CardFactory*);		//constructeur qui accepte fichier
	friend ostream & operator << (ostream &, Hand);
};


