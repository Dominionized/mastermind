/**	@file RandomNumber.h
Fichier contenant la déclaration des méthodes de la classe RandomNumber.
@author Olivier Therrien - Lefebvre
@author Dominique Begin
@date 15 mai 2014
@version 1.0
*/#pragma once

//Encapsule le problème de la génération d'un nombre alléatoire
class RandomNumber
{
public:
    RandomNumber(void);
    ~RandomNumber(void);

    int GetNumber(short _max);
};

