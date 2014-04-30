/** @file List.hpp
Fichier contenant les methodes de la classe Iterator.

@author Dominique Begin
@author Olivier Therrien-Lefebvre
@date	30 avril 2014

*/

/**
	Constructeur de Iterator
*/
template <class TYPE>
Iterator<TYPE>::Iterator(void)
{
	current = NULL;
}

/**
	Ramene l'iterateur a la Cell suivante
*/
template <class TYPE>
void Iterator<TYPE>::Next(void)
{
	current = current->Next;
}

/**
	Ramene l'iterateur a la Cell precedente
*/
template <class TYPE>
void Iterator<TYPE>::Previous(void)
{
	current = current->Previous;
}

/**
	Retourne l'element de la cell vers laquelle l'iterateur pointe
	@return L'element de la cell vers laquelle l'iterateur pointe
*/
template <class TYPE>
TYPE* Iterator<TYPE>::GetCurrentElement(void) const
{
	return current->Element;
}

/**
	Retourne la cell vers laquelle l'iterateur pointe
	@return La cell vers laquelle l'iterateur pointe
*/
template <class TYPE>
Cell<TYPE>* Iterator<TYPE>::GetCurrent(void) const
{
	return current;
}

/**
	Fait pointer l'iterateur sur une cell specifiee
	@param[in] _cell La cellule sur laquelle faire pointer l'iterateur.
*/
template <class TYPE>
void Iterator<TYPE>::SetCurrent(Cell<TYPE>* _cell)
{
	current = _cell;
}
