#include "constante.h"


// ------ Operateur + ------

// Constante
Constante& Constante::operator+(Constante* c)
{
    Entier* e=dynamic_cast<Entier*>(c);
    Reel* r=dynamic_cast<Reel*>(c);
    Rationnel* ra=dynamic_cast<Rationnel*>(c);

    if(e) return (*this + *e);
    else if(r) return (*this + *r);
    else if(ra) return (*this + *ra);
    else throw ExceptionCalculatrice("Erreur d'operation +");

    return *c;
}

// Reel
Reel& Reel::operator+(const Reel& r) {return *(new Reel(valeur + r.GetVal()));}
Reel& Reel::operator+(const Entier& e) {return *(new Reel(valeur + e.GetVal()));}
Rationnel& Reel::operator+(const Rationnel& ra){return *(new Rationnel((int)valeur,(int)valeur));} // à finir

// Entier
Entier& Entier::operator+(const Entier& e) {return *(new Entier(valeur + (int)e.GetVal()));}
Reel& Entier::operator+(const Reel& r){return *(new Reel((double)valeur + r.GetVal()));}
Rationnel& Entier::operator+(const Rationnel& ra)
{
    return *(new Rationnel(ra.GetNum() + valeur*ra.GetDen(), ra.GetDen()));
}

// Rationnel
Rationnel& Rationnel::operator+(const Rationnel& ra)
{
    return *(new Rationnel(numerateur.GetVal()*ra.GetDen()+ra.GetNum()*denominateur.GetVal(),ra.GetDen()*denominateur.GetVal()));
}
Rationnel& Rationnel::operator+(const Entier& e)
{
    return *(new Rationnel(numerateur.GetVal() + e.GetVal()*denominateur.GetVal(),denominateur.GetVal()));
}
Reel& Rationnel::operator+(const Reel& r){return *(new Reel( (GetNum()/GetDen()) + r.GetVal()));}
