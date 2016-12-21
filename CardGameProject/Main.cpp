#include "Table.h"


static bool BuyOrSellChain(Player player, bool optional) {
	bool ret = false;
	bool askExchange = true;
	char answer;
	if (player.getMaxNumChains() < 3) {
		cout << "Voulez-vous acheter une nouvelle chaine? (y/n) ";
		cin >> answer;
		if (answer == 'y') {
			try {
				player.buyThirdChain();
				//The following is skipped if exception is thrown.
				askExchange = false;
				ret = true;
			}
			catch (NotEnoughCoins e) {
				cout << e << "\n";
			}
		}
	}
	if (askExchange) {
		if (optional) {
			cout << "Voulez-vous échanger une de vos chaine? (y/n) ";
			cin >> answer;
		}
		else {
			cout << "Vous devez vendre une chaine et la remplacer.\n";
		}
		if (answer == 'y' || !optional) {
			ret = true;
			int choix = 0;
			while (!choix) {
				cout << "Quel chaine voulez-vous échanger?\n(Entrez le numéro de la chaine, en commensant à 1)";
				cin >> choix;
				if (!(0 < choix && choix <= player.getNumChains())) {
					cout << "Position invalide, essayez de nouveau. "; 
					choix = 0;
				}
			}
			choix--;
			player.sellChain(choix);
			//goes back in the loop and adds the card.
		}
	}

	return ret;
}



static void pickUpFromTradingArea(Table* table, Player& player, bool discard) {
	char answer;
	for (int j = 0; j < table->ta->cardTypes.size(); j++) {
		//string type = table->ta->cardTypes
		cout << *table << "\n";
		//TODO Une carte à la foix ou tous enssemble?
		cout << "Voulez-vous rammasser les cartes de type " << type << " ? (y/n) ";
		cin >> answer;
		if (answer == 'y') {
			Card* temp = table->ta->trade(type);
			while (temp != nullptr) {
				//Add to correct chain.
				if (player.addToChain(temp)) {
					temp = table->ta->trade(type);
				}
				else {
					bool cont = BuyOrSellChain(player, true);
					if (!cont)
						temp = nullptr;
				}
			}
		}	//else add them to discard.
		else if(discard) {
			Card* temp = table->ta->trade(type);
			while (temp) {
				(*table->discard) += temp;
				temp = table->ta->trade(type);
			}
		}
	}
}



static void save(Table&table) {
	ofstream outputFile("lastGameSaved.txt");
	if (outputFile) {
		table.players[0].print(outputFile);
		table.players[1].print(outputFile);
		(*table.discard).print(outputFile);
		outputFile << "\n" << *table.ta;
		outputFile << "\n" << *table.deck << endl;
		outputFile << "LE TOUR A QUI";
		outputFile.close();
	}
}

static Table* load() {
	CardFactory *cf = CardFactory::getFactory();
	ifstream inputFile("lastGameSaved.txt");
	if (inputFile.is_open()) {
		Table* table = new Table(inputFile, cf);
		return table;
	}
	else
		return NULL;

}

int main() {
	//Setup
	char answer;
	bool pause = false;
	Table* table = NULL;

	while (table == NULL) {
		cout << "Entrez n pour commencer un nouveau jeu, ou s pour reprendre votre derniere partie. ";
		cin >> answer;
		if (answer == 'n') {
			cin.ignore(256, '\n'); //empty cin for next input
			string name1, name2;
			cout << "Entrez le nom du premier joueur: ";
			getline(cin, name1, '\n');
			cin.clear();
			cout << "Entrez le nom du deuxieme joueur: ";
			getline(cin, name2);

			table = new Table(name1, name2);

			for (Player player : table->players) {
				for (int i = 0; i < 5; i++) {
					player += table->deck->draw();
				}
			}
		}
		else {
			//load old game
			string name1 = "Paul";
			string name2 = "Isa ";
			//table = new Table(name1, name2);
			table = load();
			if (table == NULL)
				cout << "Aucune partie sauvegarder" <<endl<<endl;
		}
	}
	
	/*table->print();			//for testing purpose

	///////////////////////////////this is all testing stuff
	CardFactory *cf = CardFactory::getFactory();
	table->players[0] += table->deck->draw();
	table->players[0] += table->deck->draw();
	table->players[0] += table->deck->draw();
	table->players[0] += table->deck->draw();
	table->players[1] += table->deck->draw();
	table->players[1] += table->deck->draw();
	table->players[1] += table->deck->draw();
	table->players[1] += table->deck->draw();
	(*table->ta) += (table->players[0]).getHand()->play();
	(*table->discard) += (table->players[1]).getHand()->play();
	(table->players[1]).addToChain(new Quartz());

	table->print();			//for testing purpose

	save(*table);
	//remove("lastGameSaved.txt"); //if game is over*/


	//deck is now a pointer in TABLE CAREFULL
	string winner;
	while (!table->win(winner)) {
		cout << "Voulez-vous mettre la partie en pause? (y/n) ";
		cin >> answer;
		if (answer == 'y')
			pause = true;
		if (pause) {
			//Save game to file and exit

			return 0;
		}
		else {
			for (Player& player : table->players) {
				cout << "--------------------------\nC'est le tour a " << player.getName() << endl;
				//Display table
				cout << *table << "\n";
				player += table->deck->draw();

				if (!table->ta->empty()) {
					pickUpFromTradingArea(table, player, true);
				}//done with Trade Area (Étape 1)
				//Étape 2
				cout << "Vous jouez la premiere carte de votre main: " << player.getHand()->top() << "\n";
				bool keepPlaying = true;
				while (keepPlaying) {
					Card* cardPlayed = player.getHand()->play();
					if (player.addToChain(cardPlayed)) {
						for (int i = 0; i < player.getNumChains(); i++) {
							if (player[i].sell() > 0) {
								cout << "Vous avez vendu une chaine!\n";
								cout << *table << "\n";
								player.sellChain(i);
							}
						}
						if (0 < player.getHand()->size()) {
							cout << player << endl;
							cout << "Votre main: " << *player.getHand() << endl;
							cout << "Voulez-vous jouer votre prochaine carte? " << player.getHand()->top() << " (y/n) ";
							cin >> answer;
							if (answer == 'n')
								keepPlaying = false;
						}
					}
					else {
						BuyOrSellChain(player, false);
					}
				} //Fin Étape 2 et 3

					//Étape 4
					if (0 < player.getHand()->size()) {
						cout << player << endl;
						cout << "Votre main: " << *player.getHand() << "\n";
						cout << "Voulez-vous vous debarasser d'une carte? (y/n) ";

						cin >> answer;
						if (answer == 'y') {
							cout  << endl << *player.getHand() << "\n";
							for (int i = 1; i <= player.getHand()->size(); i++) {
								cout << i;
							}
							cout << endl;
							int choix = 0;
							while (!choix) {
								cout << "De quel carte voulez-vous vous debarasser?\nEntrez la position de la carte : ";
								cin >> choix;
								if (!(0 < choix && choix <= player.getHand()->size())) {
									cout << "Position invalide, essayez de nouveau. ";
									choix = 0;
								}
							}
							choix--;
							(*table->discard) += (*player.getHand())[choix];
						}
					} //Fin Étape 4

					//Étape 5
					for (int i = 0; i < 3; i++) {
						(*table->ta) += table->deck->draw();
					}
					while (!(table->discard->isEmpty()) && table->ta->legal(table->discard->top())) {
						(*table->ta) += table->discard->pickUp();
					}
					pickUpFromTradingArea(table, player, false);
					//Fin Étape 5

					//Étape 6
					player += table->deck->draw();
					player += table->deck->draw();
				}

			}



			cout << endl << endl;
			system("pause");
			return 0;
		}
	cout << "Le gagnant est " << winner << "!\n";
}


