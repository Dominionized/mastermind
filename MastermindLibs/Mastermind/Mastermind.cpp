#include "Mastermind.h"


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
	//Il faut cr�er ici les 4096 s�quences de couleurs possibles. Bonne r�flexion!
}

Mastermind::~Mastermind()
{
	delete list;
	for (int i = 0; i < 4096; i++)
	{
		delete tabSequences[i];
	}
}

int Mastermind::GetNbElements() const
{
	return list->GetNbElements();
}

ArrayI<Color>* Mastermind::GetElement() const
{
	//Utiliser la classe RandomNumber pour ne pas offrir toujours le premier �l�ment de la liste (les parties seraient toutes pareilles avec la m�me s�quence cach�e)
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
				if (monIterateur.GetCurrentElement()->GetElement(i) != _tabColorRef[i]) // Si la couleur de l'index i est diff�rente...
				{
					//... on supprime la cellule
					monIterateur.GetCurrent()->Previous->Next = monIterateur.GetCurrent()->Next;
					monIterateur.GetCurrent()->Next->Previous = monIterateur.GetCurrent()->Previous;
					nbOfDeletions++;
				}
				monIterateur.SetCurrent(monIterateur.GetCurrent()->Next);
			}
			//Si la s�quence de couleurs trait�e n'a pas la couleur � la bonne place, il faut la retirer de la liste.
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
			//Si la s�quence de couleurs trait�e n'a pas la couleur � un autre emplacement que celui de la couleur de r�f�rence,
			//il faut la retirer de la liste.
		case 3: //Mauvaise couleur
			//Si la s�quence de couleurs trait�e a la couleur, il faut la retirer de la liste.
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