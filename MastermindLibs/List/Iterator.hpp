
template <class TYPE>
Iterator<TYPE>::Iterator(void)
{
	current = NULL;
}

template <class TYPE>
void Iterator<TYPE>::Next(void)
{
	current = current->Next;
}

template <class TYPE>
void Iterator<TYPE>::Previous(void)
{
	current = current->Previous;
}

template <class TYPE>
TYPE* Iterator<TYPE>::GetCurrentElement(void) const
{
	return current->Element;
}

template <class TYPE>
Cell<TYPE>* Iterator<TYPE>::GetCurrent(void) const
{
	return current;
}

template <class TYPE>
void Iterator<TYPE>::SetCurrent(Cell<TYPE>* _cell)
{
	current = _cell;
}
