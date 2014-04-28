/** @file List.hpp
Fichier contenant les methodes de la classe Cell.

@author Dominique Begin
@author Olivier Therrien-Lefebvre
@date	30 janvier 2014

*/

template <class TYPE>
Cell<TYPE>::Cell(TYPE* _element, Cell* _previous, Cell* _next)
{
    this->Element = _element;
    this->Previous= _previous;
    this->Next = _next;
}