/** @file Cell.hpp
Fichier contenant les methodes de la classe Cell.
@author Dominique Begin
@author Olivier Therrien-Lefebvre
@date	15 mai 2014

*/

/**
	Constructeur de Cell
	@param[in] _element L'element vers lequel la Cell pointera
	@param[in] _previous L'element precedent
	@param[in] _next L'element suivant
*/
template <class TYPE>
Cell<TYPE>::Cell(TYPE* _element, Cell* _previous, Cell* _next)
{
    this->Element = _element;
    this->Previous= _previous;
    this->Next = _next;
}