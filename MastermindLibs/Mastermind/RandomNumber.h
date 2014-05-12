/**	@file RandomNumber.h
Fichier contenant la d�claration des m�thodes de la classe RandomNumber.
@author Olivier Therrien - Lefebvre
@author Dominique Begin
@date 15 mai 2014
@version 1.0
*/#pragma once

//Encapsule le probl�me de la g�n�ration d'un nombre all�atoire
class RandomNumber
{
public:
    RandomNumber(void);
    ~RandomNumber(void);

    int GetNumber(short _max);
};

