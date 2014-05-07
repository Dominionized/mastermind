#pragma once

#include "Mastermind.h"
#include <stdio.h>
#include <tchar.h>
//#include <time.h>
#include <iostream>
#include <windows.h> //Pour la fonction CharToOem ->Propriétédu projet "Jeu de caractères" doit être à "Non défini"
#include <string>
using namespace std;

class ConsoleMenu
{
public:
	ConsoleMenu();
	~ConsoleMenu();
	void Run();
	void displayCredits();
	string choixDesCouleurs();
	string accents(const string &pString);
	void obtentionCombinaisonCouleurRéférence();
	void lectureVerdicts();
	void epurationListe();

	Color tabCouleurs[4]; //4 couleurs parmis un choix de 8
	ArrayI<Color>* tabCouleursRef;
	short nbCoups = 0;
	short tabVerdicts[4];
};

