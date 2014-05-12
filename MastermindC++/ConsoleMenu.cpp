/**	@file ConsoleMenu.cpp
Fichier contenant les methodes de la classe ConsoleMenu.

@author Olivier Therrien-Lefebvre
@author Dominique Begin
@date 15 mai 2014
@version 1.0
*/

#include "ConsoleMenu.h"

/**
Constructeur de la classe ConsoleMenu.
*/
ConsoleMenu::ConsoleMenu()
{
}

/**
Destructeur de la classe ConsoleMenué
*/
ConsoleMenu::~ConsoleMenu()
{
}

/**
Methode qui prend en charge la gestion des accents.
*/
string accents(const string &pString){

	assert(pString.length() <= 1024);
	char source[1024]; //Propriétés du projet "Characters set" doit être à "Not set" -> pas de caractère UNICODE)
	strcpy_s(source, 1024, pString.c_str());
	char destination[sizeof(source)];
	CharToOem(source, destination);
	return destination;
}

/**
Methode qui debute le programme.
*/
void ConsoleMenu::Run()
{
	displayCredits();

	Mastermind mastermind;

	choixDesCouleurs();

	cout << "Couleurs choisies: " << tabCouleurs[0] << " "
		<< tabCouleurs[1] << " "
		<< tabCouleurs[2] << " "
		<< tabCouleurs[3] << " "
		<< endl;

	cout << endl << endl << accents("Début de la partie!") << endl << endl;
	system("pause");
	while (true){

		if (nbCoups == 8){
			cout << accents("Le nombre maximum d'essais a atteind la limite (8). Je perds...") << endl << endl;
			break;
		}
		int iNbElements = mastermind.GetNbElements();
		if (iNbElements == 0){ //Il ne reste plus de combinaison dans la liste, l'utilisateur a fait assurément une erreur car HAL ne se trompe pas!
			cout << accents("La liste de combinaisons possibles est épuisée.") << endl << endl;;
			break;
		}
		nbCoups++;

		obtentionCombinaisonCouleurReference();

		cout << accents("NbElements:") << iNbElements << endl;

		lectureVerdicts();

		if (tabVerdicts[0] == 1 && tabVerdicts[1] == 1 && tabVerdicts[2] == 1 && tabVerdicts[3] == 1){
			cout << endl << accents("J'ai trouvé la réponse après ") << nbCoups;
			if (nbCoups == 1){
				cout << accents(" essai. Merci d'avoir joué avec moi.") << endl << endl;
			}
			else{
				cout << accents(" essais. Merci d'avoir joué avec moi.") << endl << endl;
			}
			cout << accents("----HAL 9000----") << endl << endl;
			break;
		}
		epurationListe();
	}
	return;
}
/**
Methode affichant les "credits".
@see Run()
*/
void ConsoleMenu::displayCredits()
{
	cout << "|================================================|" << endl;
	cout << "|                                                |" << endl;
	cout << "|               TRAVAIL PRATIQUE 3               |" << endl;
	cout << "|                   MASTERMIND                   |" << endl;
	cout << "|                                                |" << endl;
	cout << "|                      Par:                      |" << endl;
	cout << "|                Dominique Begin                 |" << endl;
	cout << "|                       &                        |" << endl;
	cout << "|           Olivier Therrien-Lefevbre            |" << endl;
	cout << "|                                                |" << endl;
	cout << "|================================================|" << endl;
	cout << endl;

	system("pause");
}

/**
Methode qui gere le choix des couleurs.
@see Run()
@return un string contenant les couleurs choisies.
*/
string ConsoleMenu::choixDesCouleurs()
{
	int i;
	string choix;
	do{
		if (i = 0)
		{
			cout << accents("Vous devrez choisir un séquence de 4 couleurs parmis la sélection de couleur") << endl << endl;
		}
		cout << accents("Veuillez choisir une couleur parmis les suivantes:") << endl << endl;
		cout << "    1-Rouge" << endl;
		cout << "    2-Vert" << endl;
		cout << "    3-Bleu" << endl;
		cout << "    4-Jaune" << endl;
		cout << "    5-Noir" << endl;
		cout << "    6-Orange" << endl;
		cout << "    7-Mauve" << endl;
		cout << "    8-Blanc" << endl;


		cout << "Entrer la suite de chiffres, 0 pour sortir: ";
		cin >> choix;
		if (choix == "0")
		{
			break;
		}
		else
		{
			tabCouleurs[i].SetColor(atoi(choix.substr(0, 1).c_str()));
		}

	} while (choix.length() != 4 || tabCouleurs[0] > 8 || tabCouleurs[1] > 8 || tabCouleurs[2] > 8 || tabCouleurs[3] > 8);
	return choix;
}

/**
Methode qui va chercher la combinaison de couleurs de reference.
@see Run()
*/
void ConsoleMenu::obtentionCombinaisonCouleurReference()
{
	//Obtention de la combinaison de couleur de référence
	ArrayI<Color>* tabCouleursRef = mastermind.GetElement();

	cout << accents("--------Couleurs à deviner: ") << tabCouleurs[0] << " "
		<< tabCouleurs[1] << " "
		<< tabCouleurs[2] << " "
		<< tabCouleurs[3] << " "
		<< "--------"
		<< endl;


	cout << endl << "Choix de HAL (" << accents("essai #") << nbCoups << "):    " << (*tabCouleursRef)[0] << " "
		<< (*tabCouleursRef)[1] << " "
		<< (*tabCouleursRef)[2] << " "
		<< (*tabCouleursRef)[3] << " "
		<< endl << endl;
}

/**
Methode qui lit le verdict du joueur sur les couleurs.
@see Run()
*/
void ConsoleMenu::lectureVerdicts()
{
	//Lecteur des 4 verdicts de l'usager
	for (int i = 0; i < 4; i++){
		do{
			string entree;

			//Couleur c=(*t)[0]; //Si la liste retourne un pointeur
			Color c = (*tabCouleursRef)[i];

			cout << endl << "Couleur " << i + 1 << " - " << (*tabCouleursRef)[i] << endl;
			cout << "Choisir (1-Bonne couleur et emplacement 2-Bonne couleur mais mauvais emplacement 3-Mauvaise couleur): ";

			cin >> entree;
			tabVerdicts[i] = atoi(entree.c_str());
		} while (tabVerdicts[i] != 1 && tabVerdicts[i] != 2 && tabVerdicts[i] != 3);
	}
}

/**
Methode qui enleve de la liste toute les combinaisons impossibles de couleurs.
@see Run()
*/
void ConsoleMenu::epurationListe()
{
	//------------------------Epuration de la liste des combinaisons qui ne respectent pas les critères-----------------------------
	Color temp[4];
	temp[0] = (*tabCouleursRef)[0];
	temp[1] = (*tabCouleursRef)[1];
	temp[2] = (*tabCouleursRef)[2];
	temp[3] = (*tabCouleursRef)[3];

	cout << mastermind.CleanList(temp, tabVerdicts) << accents(" combinaisons supprimées.") << endl;
}