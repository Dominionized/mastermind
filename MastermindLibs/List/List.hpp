/** @file List.hpp
	Fichier contenant les methodes de la classe List.

	@author Dominique Begin
	@author Olivier Therrien-Lefebvre
	@date	30 janvier 2014

*/
/**
	Constructeur de List. Instantie le premier et le dernier noeud à NULL
*/
template <class TYPE>
List<TYPE>::List()
{
	first = NULL;
	last = NULL;
}

/**
	Destructeur de List.
*/
template <class TYPE>
List<TYPE>::~List()
{
	Clear();
}
/**
	Insertion d'une cellule à la fin de liste (supporte l'ajout dans une liste vide)
	@param[in] _element L'element que contiendra la nouvelle cellule.
*/
template <class TYPE>
void List<TYPE>::PushBack(TYPE* _element)
{
	Cell<TYPE>* newCell = new Cell<TYPE>(_element, last, NULL);

	if (isEmpty())
	{
		first = newCell;
		last = newCell;
	}
	else
	{
		Cell<TYPE>* ptrSecondLastCell = last;
		last = newCell;
		ptrSecondLastCell->Next = newCell;
		last->Previous = ptrSecondLastCell;
	}
	nbElements++;
}

/**
	Insertion d'une cellule avant la cellule referencee par l'iterateur
	@param[in] _Element L'element que contiendra la nouvelle cellule.
	@param[in] _Iter L'iterateur referencant la cellule.
*/
template <class TYPE>
void List<TYPE>::Insert(TYPE* _Element, Iterator<TYPE>& _Iter)
{

    //Insert avant la position courante (limite: impossible d'ajouter à la fin!)
    //Ne supporte pas l'ajout dans une liste vide.
    //2 cas 1)Insertion au début 
    //      2)Insertion entre premier et dernier 

	switch (_Iter->GetCurrent())
	{
	case NULL: //L'iterateur n'est pas valide
		throw("Impossible d'ajouter a la fin ou iterateur invalide.");
		return;
	case first:
		Cell<TYPE>* ptrSecondCell = first;
		first = new Cell<TYPE>(_Element, NULL, ptrSecondCell); //Previous -> NULL, Next -> 2e noeud
		ptrSecondCell->Previous = first;
		break;
	case default:
		_Iter->GetCurrent()->Previous->Next = new Cell<TYPE>(_Element, _Iter->GetCurrent()->Previous, _Iter->GetCurrent());;
		_Iter->GetCurrent()->Previous = newCell;
		break;
	}
	nbElements++;

} 

/**
Suppression d'une cellule referencee par l'iterateur
@param[in] _Iter L'iterateur referencant la cellule a supprimer.
*/
template <class TYPE>
void List<TYPE>::Erase(Iterator<TYPE>& _Iter)
{
	/*
	4 cas :

	1. L'iterateur n'est pas valide
	2. L'iterateur pointe vers le premier element
	3. L'iterateur pointe vers le dernier element
	4. L'iterateur pointe n'importe ou d'autre
	*/

	switch (_Iter->GetCurrent())
	{
	case NULL:
		throw("Iterateur invalide");
		return;
	case first:
		Cell<TYPE>* newFirst = first->Next;
		delete first;
		first = newFirst;
		first->Previous = NULL;
		break;
	case last:
		Cell<TYPE>* newLast = last->Previous;
		delete last;
		last = newLast;
		last->Next = NULL;
		break;
	case default:
		Cell<TYPE>* ptrCellToDelete = _Iter->GetCurrent();
		ptrCellToDelete->Previous->Next = ptrCellToDelete->Next;
		ptrCellToDelete->Next->Previous = ptrCellToDelete->Previous;
		delete ptrCellToDelete;
		break;
	}
	nbElements--;
}

/**
Retourne l'element de la cellule referencee par l'iterateur
@param[in] _Iter L'iterateur referencant la cellule pour laquelle retourner la valeur.
@return L'element de la cellule referencee par l'iterateur
*/
template <class TYPE>
TYPE* List<TYPE>::GetElement(const Iterator<TYPE>& _Iter) const
{
	return &(_Iter->GetCurrentElement);
}

/**
Retourne le nombre d'elements de la liste.
@return Le nombre d'elements de la liste
*/
template <class TYPE>
int List<TYPE>::GetNbElements() const
{ 
	return nbElements;
}

/**
Retourne si la liste est vide ou non
@return Un bool disant si la liste est vide ou non
*/
template <class TYPE>
bool List<TYPE>::IsEmpty() const
{
	if (first = NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
} 

/**
Vide la liste.
*/
template <class TYPE>
void List<TYPE>::Clear()
{

	// On commence au 2e et on supprime le précédent à chaque fois
	Cell<TYPE>* ptrCurrentCell = first->Next;

	while (ptrCurrentCell != NULL)
	{
		delete ptrCurrentCell->Previous;
		ptrCurrentCell = PtrCurrentCell->Next;
	}
	delete last;
	first = NULL;
	last = NULL;
	nbElements = 0;
}

/**
Retourne un pointeur vers le premier element de la liste
@return Un pointeur vers le premier element de la liste
*/
//Méthodes déjà implémentées
template <class TYPE>
Cell<TYPE>* List<TYPE>::Begin() const
{ 
    return this->first;
}

/**
Retourne un pointeur vers le dernier element de la liste
@return Un pointeur vers le dernier element de la liste
*/
template <class TYPE>
Cell<TYPE>* List<TYPE>::End() const
{
    return this->last;
}

/**
Surcharge de l'operateur <<
@param[in] _sortie L'ostream contenant la valeur de retour
@param[in] _list La liste.
@return Un ostream contenant tous les elements de la liste separes par des sauts de ligne
*/
template <class TYPE>
ostream& operator<<(ostream& _sortie, const List<TYPE>& _list)
{
    Cell<TYPE>* cellule=_list.first;

    while(cellule != NULL){
        _sortie<<*cellule->Element<<endl;
        cellule = cellule->Next;
    }
    _sortie<<endl;
    return _sortie;
}