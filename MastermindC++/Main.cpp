// Mastermind.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include "ConsoleMenu.h"
/**	@file ConsoleMenu.cpp
Fichier contenant les methodes de la classe ConsoleMenu.
@author Olivier Therrien - Lefebvre
@author Dominique Begin
@date 15 mai 2014
@version 1.0
*/

//#include <time.h>
#include <iostream>
#include <string>
using namespace std;

#include <windows.h> //Pour la fonction CharToOem ->Propriétédu projet "Jeu de caractères" doit être à "Non défini"

#include "Mastermind.h"

void main(int argc, _TCHAR* argv[])
{
    if (argc == 2){ 
        string parametre = argv[1];
        if(parametre == "-auteur" || parametre == "-a"){
            cout<<"[Vos noms], tout droit réservé, 2013."<<endl;
            return;
        }
    }
    
	while (true){
		ConsoleMenu Run();
	}
       
}
