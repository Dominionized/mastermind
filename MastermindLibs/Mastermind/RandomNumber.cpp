/** @file RandomNumber.cpp
Fichier contenant les methodes de la classe RandomNumber.

@author Dominique Begin
@author Olivier Therrien-Lefebvre
@date	15 mai 2014

*/
#include <iostream>
#include <time.h> 
#include <stdio.h> //Pour avoir fonciton srand()
#include "RandomNumber.h"

/**
Constructeur de RandomNumber qui cree un nombre aleatoire.
*/
RandomNumber::RandomNumber(void)
{
    time_t time(time_t *tloc);
    srand((unsigned int)time(NULL)+100);  // On part la séquence à l'aide d'un nombre alléatoire (basé sur le temps)
}
/**
Methode qui va chercher le nombre genere.
@return le nombre aleatoire.
@param un short qui represente la maximum que le nombre aleatoire pourra atteindre.
*/
int RandomNumber::GetNumber(short _max)
{
    return (rand() % _max) + 1; //Le nombre généré sera entre 1 et _max
}
/**
Destructeur de MasterMindColor.
*/
RandomNumber::~RandomNumber(void)
{
}
