#include "Table.h"

int main() {
	//Setup
	char answer;
	bool pause = false;
	Table* table;
	cout << "Entrez n pour commencer un nouveau jeux, ou s pour reprendre un jeux sauvegardé. ";
	cin >> answer;
	if (answer == 'n') {
		string name1, name2;
		cout << "Entrez le nom du premier joueur: ";
		getline(cin, name1);
		cout << "Entrez le nom du deuxième joueur: ";
		getline(cin, name2);
		table = new Table(name1, name2);
	}
	else {
		//load old game
		string name = "hello";
		string name2 = "yolo";
		table = new Table(name,name2);


	}

	while (!table->deck.empty()) {
		if (pause) {
			//Save game to file and exit

			return 0;
		}
		else {
			for (Player player : table->players) {
				//Display table
				cout << table << "\n";
				player += table->deck.draw();
				if (!table->ta.empty()) {
					for (string type : table->ta.cardTypes) {
						cout << "Voulez-vous rammasser les cartes de type " << type << " ? (y/n) ";
						cin >> answer;
						if (answer == 'y') {
							Card* temp = table->ta.trade(type);
							while (temp) {
								//Add to correct chain.
								//New opperator in player?
							}
						}
					}
				}
			}

		}

	}



	return 0;
}