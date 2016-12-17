#include "Table.h"

int main() {
	//Setup
	int setup;
	cout << "Entrez 0 pour commencer un nouveau jeux, ou 1 pour reprendre un jeux sauvegardé. ";
	cin >> setup;
	if (setup == 0) {
		string name1, name2;
		cout << "Entrez le nom du premier joueur: ";
		getline(cin, name1);
		cout << "Entrez le nom du deuxième joueur: ";
		getline(cin, name2);
	}
	



	return 0;
}