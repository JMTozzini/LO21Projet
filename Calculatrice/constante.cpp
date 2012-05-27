#include "constante.h"


// ------ Operateur + ------

// Constante
Constante& Constante::operator+(Constante* c)
{
    Entier* e=dynamic_cast<Entier*>(c);
    Reel* r=dynamic_cast<Reel*>(c);

    if(e)
        return (this->operator+(*e));
    else if(r)
        return (this->operator+(*r));
    else
        std::cout<<"Erreur"<<std::endl;

    return *c;
}

// Reel
Reel& Reel::operator+(const Reel& r) {return *(new Reel(valeur + r.GetVal()));}
Reel& Reel::operator+(const Entier& e) {return *(new Reel(valeur + e.GetVal()));}

// Entier
Entier& Entier::operator+(const Entier& e) {return *(new Entier(valeur + (int)e.GetVal()));}
Reel& Entier::operator+(const Reel& r){return *(new Reel((double)valeur + r.GetVal()));}


