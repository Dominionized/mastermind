/** @file MasterMindColor.cpp
Fichier contenant les methodes de la classe MasterMindColor.

@author Dominique Begin
@author Olivier Therrien-Lefebvre
@date	15 mai 2014

*/#include "MasterMindColor.h"

/**
Constructeur de MasterMindColor.
*/
Color::Color(void)
{
    this->color = 0;
}
/**
Constructeur de MasterMindColor qui initialise la couleur avec la couleur donné en paramètre.
@param Short représentant une couleur.
*/
Color::Color(short _c)
{
    this->color = _c;
}
/**
Destructeur de MasterMindColor.
*/
Color::~Color(void){}

/**
Methode qui gere l'association des case avec les couleurs.
@return la couleur du case.
*/
ostream& operator<<(ostream& sortie, const Color& _c)
{
    
    switch(_c.color){
        case 1:
            sortie<<"Rouge";
            break;
        case 2:
            sortie<<"Vert";
            break;
        case 3:
            sortie<<"Bleu";
            break;
        case 4:
            sortie<<"Jaune";
            break;
        case 5:
            sortie<<"Noir";
            break;
        case 6:
            sortie<<"Orange";
            break;
        case 7:
            sortie<<"Mauve";
            break;
        case 8:
            sortie<<"Blanc";
            break;
    };
    return sortie;
}
/**
Methode qui ...
*/
bool Color::operator==(const Color& _c)
{ 
    return this->color == _c.color;
}

bool Color::operator>(const Color& _c){ 
    return this->color > _c.color;
}

bool Color::operator<(const Color& _c){ 
    return this->color < _c.color;
}

bool Color::operator!=(const Color& _c){ 
    return this->color != _c.color;
}

void Color::operator=(const Color& _c){ 
    this->color = _c.color;
}
/**
Methode qui va chercher la couleur.
@return un short qui représente la couleur.
*/
short Color::GetColor(){
    return this->color;
}
/**
Methode qui donne une couleur.
@param un short qui represente une couleur.
*/
void Color::SetColor(short _c){
    this->color = _c;
}
