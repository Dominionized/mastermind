
//Constructeur
template <class TYPE>
List<TYPE>::List()
{
	first = NULL;
	last = NULL;
}

//Destructeur
template <class TYPE>
List<TYPE>::~List()
{
}

//Insert � la fin de liste (supporte l'ajout dans une liste vide)
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
}
template <class TYPE>
void List<TYPE>::Insert(TYPE* _Element, Iterator<TYPE>& _Iter)
{
    //Insert avant la position courante (limite: impossible d'ajouter � la fin!)
    //Ne supporte pas l'ajout dans une liste vide.
    //2 cas 1)Insertion au d�but 
    //      2)Insertion entre premier et dernier 

	switch (_Iter->GetCurrent())
	{
	case last:
		throw("Impossible d'ajouter a la fin.");
		break;
	case first:
		TYPE* ptrSecondCell = first;
		first = _Element;
		ptrSecondCell->Previous = first;
		first->Next = ptrSecondCell;
		break;
	case default:
		Cell<TYPE> newCell = new Cell<TYPE>(_Element, _Iter->GetCurrent()->Previous, _Iter->GetCurrent());
		_Iter->GetCurrent()->Previous->Next = newCell;
		_Iter->GetCurrent()->Previous = newCell;
		break;
	}

} 

template <class TYPE>
void List<TYPE>::Erase(Iterator<TYPE>& _Iter)
{
    //4 cas possibles... A vous de les trouver!
}

template <class TYPE>
TYPE* List<TYPE>::GetElement(const Iterator<TYPE>& _Iter) const
{

}

template <class TYPE>
int List<TYPE>::GetNbElements() const
{ 
	return nbElements;
}

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

template <class TYPE>
void List<TYPE>::Clear()
{

}

//M�thodes d�j� impl�ment�es
template <class TYPE>
Cell<TYPE>* List<TYPE>::Begin() const
{ 
    return this->first;
}

template <class TYPE>
Cell<TYPE>* List<TYPE>::End() const
{
    return this->last;
}

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