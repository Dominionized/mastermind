#pragma once

#include "Mastermind.h"
#include <stdio.h>
#include <tchar.h>
//#include <time.h>
#include <iostream>
#include <windows.h> //Pour la fonction CharToOem ->Propri�t�du projet "Jeu de caract�res" doit �tre � "Non d�fini"
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
	void obtentionCombinaisonCouleurR�f�rence();
	void lectureVerdicts();
	void epurationListe();

	Color tabCouleurs[4]; //4 couleurs parmis un choix de 8
	ArrayI<Color>* tabCouleursRef;
	short nbCoups = 0;
	short tabVerdicts[4];
};

