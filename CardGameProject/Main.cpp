#include "Table.h"

int main() {
	//Setup
	char answer;
	bool pause = false;
	Table* table;
	cout << "Entrez n pour commencer un nouveau jeu, ou s pour reprendre un jeu sauvegarde. ";
	cin >> answer;
	if (answer == 'n') {
		cin.ignore(256, '\n'); //empty cin for next input
		string name1, name2;
		cout << "Entrez le nom du premier joueur: ";
		getline(cin, name1, '\n');
		cin.clear();
		cout << "Entrez le nom du deuxieme joueur: " ;
		getline(cin, name2);

		table = new Table(name1, name2);
	}
	else {
		//load old game
		string name = "hello";
		string name2 = "yolo";
		table = new Table(name,name2);


	}


	(*table->ta) += (new Emerald());
	(*table->discard) += (new Quartz());
	table->print();			//for testing purpose
	
	
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

				if (!table->ta->empty()) {
					for (string type : table->ta->cardTypes) {
						cout << "Voulez-vous rammasser les cartes de type " << type << " ? (y/n) ";
						cin >> answer;
						if (answer == 'y') {
							Card* temp = table->ta->trade(type);
							while (temp) {
								//Add to correct chain.
								if (player.addToChain(temp)) {
									temp = table->ta->trade(type);
								}
								else {

								}
									bool askExchange = true;
									if (player.getMaxNumChains() < 3) {
										cout << "Voulez-vous acheter une nouvelle chaine? (y/n) ";
										cin >> answer;
										if (answer == 'y') {
											try {
												player.buyThirdChain();
												//The following is skipped if exception is thrown.
												askExchange = false;			
												player[2] += temp;
												temp = table->ta->trade(type);
											}
											catch (NotEnoughCoins e) {
												cout << e << "\n";
											}
										}
									}
									if (askExchange) {
										cout << "Voulez-vous échanger une de vos chaine? (y/n) ";
										cin >> answer;
										if (answer == 'y') {
											int choix = 0;
											while (!choix) {
												cout << "Quel chaine voulez-vous échanger?\n(Entrez le numéro de la chaine, en commensant à 1)";
												cin >> choix;
												if (!(0 < choix && choix <= player.getNumChains())) {
													choix = 0;
												}
											}
											choix--;
											player.sellChain(choix);
											
										}
									}
								}
							}
						}
					}
				}
			}

		}

	

	cout << endl << endl;
	system("pause");
	return 0;
}