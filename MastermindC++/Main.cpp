// Mastermind.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include "ConsoleMenu.h"
//#include <time.h>
#include <iostream>
#include <string>
using namespace std;

#include <windows.h> //Pour la fonction CharToOem ->Propri�t�du projet "Jeu de caract�res" doit �tre � "Non d�fini"

#include "Mastermind.h"

string accents(const string &pString){

    assert(pString.length()<=1024);
    char source[1024]; //Propri�t�s du projet "Characters set" doit �tre � "Not set" -> pas de caract�re UNICODE)
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
            cout<<"[Vos noms], tout droit r�serv�, 2013."<<endl;
            return;
        }
    }
    
	while (true){
		ConsoleMenu Run();
	}
       
}
