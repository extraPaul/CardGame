#include "Table.h"

int main() {
	//Setup
	int setup;
	bool pause = false;
	Table* table;
	cout << "Entrez 0 pour commencer un nouveau jeux, ou 1 pour reprendre un jeux sauvegard�. ";
	cin >> setup;
	if (setup == 0) {
		string name1, name2;
		cout << "Entrez le nom du premier joueur: ";
		getline(cin, name1);
		cout << "Entrez le nom du deuxi�me joueur: ";
		getline(cin, name2);
		table = new Table(name1, name2);
	}
	else {
		//load old game
		
	}
	
	while (!table->deck.empty) {
		if (pause) {
			//Save game to file and exit

			return 0;
		}
		else {
			for (Player player : table->players) {
				//Display table
				cout << table << "\n";

			}

		}

	}



	return 0;
}