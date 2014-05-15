/** @file Mastermind.cpp
Fichier contenant les methodes de la classe Mastermind.

@author Dominique Begin
@author Olivier Therrien-Lefebvre
@date	15 mai 2014

*/#include "Mastermind.h"

/**
Constructeur de Mastermind qui cree toute les combinaisons de couleurs.
*/
Mastermind::Mastermind()
{
	list = new List<ArrayI<Color>>;
	int compteurTabSequence = 0;

	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			for (int k = 1; k <= 8; k++)
			{
				for (int l = 1; l <= 8; l++)
				{
					ArrayI<Color>* ptrNewArray = new ArrayI<Color>(4);
					ptrNewArray->SetElement(Color(i), 0);
					ptrNewArray->SetElement(Color(j), 1);
					ptrNewArray->SetElement(Color(k), 2);
					ptrNewArray->SetElement(Color(l), 3);
					list->PushBack(ptrNewArray);
					compteurTabSequence++;
					tabSequences[compteurTabSequence] = ptrNewArray;
				}
			}
		}
	}
}

/**
Destructeur de la classe Mastermind.
*/
Mastermind::~Mastermind()
{
	delete list;
	for (int i = 0; i < 4096; i++)
	{
		delete tabSequences[i];
	}
}

/**
Methode qui va prendre le nombre d'elements.
@return un int qui est le nombre d'elements dans la liste.
*/
int Mastermind::GetNbElements() const
{
	return list->GetNbElements();
}

/**
Methode qui va chercher l'element dans la liste un élément au aléatoire.
@see randomNumber.
@return Un pointeur dans l'Array sur un element.
*/
ArrayI<Color>* Mastermind::GetElement() const
{
	//Utiliser la classe RandomNumber pour ne pas offrir toujours le premier élément de la liste (les parties seraient toutes pareilles avec la même séquence cachée)
	ArrayI<Color>* randomArray;
	RandomNumber randomNumberator;
	Iterator<ArrayI<Color>> monIterateur;

	int randomNumber = randomNumberator.GetNumber(GetNbElements());

	monIterateur.SetCurrent(list->Begin());

	for (int i = 0; i < randomNumber; i++)
	{
		monIterateur.Next();
	}

	randomArray = list->GetElement(monIterateur);
	return randomArray;
}

/**
Methode qui vide la liste des choix.
@return Un short qui représente un verdict.
@param un pointeur sur la couleur.
@param un pointeur sur le verdict.
*/
short Mastermind::CleanList(Color* _tabColorRef, short* _tabVerdicts)
{
	short nbOfDeletions = 0;
	Iterator<ArrayI<Color>> monIterateur;
	monIterateur.SetCurrent(list->Begin());
	bool hasColor = false;

	for (int i = 0; i < 4; i++)
	{

		switch (_tabVerdicts[i]){

		case 1: //Bonne couleur, bonne place
			monIterateur.SetCurrent(list->Begin());

			while (monIterateur.GetCurrent() != NULL)
			{
				if (monIterateur.GetCurrentElement()->GetElement(i) != _tabColorRef[i]) // Si la couleur de l'index i est différente...
				{
					//... on supprime la cellule
					monIterateur.GetCurrent()->Previous->Next = monIterateur.GetCurrent()->Next;
					monIterateur.GetCurrent()->Next->Previous = monIterateur.GetCurrent()->Previous;
					nbOfDeletions++;
				}
				monIterateur.SetCurrent(monIterateur.GetCurrent()->Next);
			}
			//Si la séquence de couleurs traitée n'a pas la couleur à la bonne place, il faut la retirer de la liste.
			break;
		case 2: //Bonne couleur, mauvaise place
			monIterateur.SetCurrent(list->Begin());


			while (monIterateur.GetCurrent() != NULL)
			{
				for (int j = 0; j < 4; j++) // On parcoure
				{
					if (monIterateur.GetCurrentElement()->GetElement(j) == _tabColorRef[i] && j != i)
					{
						hasColor = true;
						break;
					}
				}

				if (!hasColor)
				{
					monIterateur.GetCurrent()->Previous->Next = monIterateur.GetCurrent()->Next;
					monIterateur.GetCurrent()->Next->Previous = monIterateur.GetCurrent()->Previous;
					nbOfDeletions++;
				}
				monIterateur.SetCurrent(monIterateur.GetCurrent()->Next);
			}
			break;
			//Si la séquence de couleurs traitée n'a pas la couleur à un autre emplacement que celui de la couleur de référence,
			//il faut la retirer de la liste.
		case 3: //Mauvaise couleur
			//Si la séquence de couleurs traitée a la couleur, il faut la retirer de la liste.
			monIterateur.SetCurrent(list->Begin());

			while (monIterateur.GetCurrent() != NULL)
			{
				for (int j = 0; j < 4; j++) // On parcoure
				{
					if (monIterateur.GetCurrentElement()->GetElement(j) == _tabColorRef[i])
					{
						monIterateur.GetCurrent()->Previous->Next = monIterateur.GetCurrent()->Next;
						monIterateur.GetCurrent()->Next->Previous = monIterateur.GetCurrent()->Previous;
						nbOfDeletions++;
						break;
					}
				}
				monIterateur.SetCurrent(monIterateur.GetCurrent()->Next);
			}
			break;
		};

	}
	return nbOfDeletions; //Pour Compiler
}