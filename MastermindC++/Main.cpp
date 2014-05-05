// Mastermind.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include "ConsoleMenu.h"
//#include <time.h>
#include <iostream>
#include <string>
using namespace std;

#include <windows.h> //Pour la fonction CharToOem ->Propriétédu projet "Jeu de caractères" doit être à "Non défini"

#include "Mastermind.h"

string accents(const string &pString){

    assert(pString.length()<=1024);
    char source[1024]; //Propriétés du projet "Characters set" doit être à "Not set" -> pas de caractère UNICODE)
    strcpy_s(source, 1024, pString.c_str());
    char destination[sizeof(source)];
    CharToOem(source, destination);
    return destination;
}


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
