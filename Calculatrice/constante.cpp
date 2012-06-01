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
Reel& Reel::operator+(const Rationnel& ra){return *(new Reel(valeur + ra.GetNum()/ra.GetDen()));} // à finir
Complexe& Reel::operator+(const Complexe& e){
    Base* tmp=dynamic_cast<Base*>(&(*(e.GetReel()) + *(this)));
    return *(new Complexe(tmp, e.GetIm()));
}


// Entier
Entier& Entier::operator+(const Entier& e) {return *(new Entier(valeur + (int)e.GetVal()));}
Reel& Entier::operator+(const Reel& r){return *(new Reel((double)valeur + r.GetVal()));}
Rationnel& Entier::operator+(const Rationnel& ra)
{
    return *(new Rationnel(ra.GetNum() + valeur*ra.GetDen(), ra.GetDen()));
}
Complexe& Entier::operator+(const Complexe& e){
    Base* tmp=dynamic_cast<Base*>(&(*(e.GetReel()) + *(this)));
    return *(new Complexe(tmp, e.GetIm()));
}


// Rationnel
Rationnel& Rationnel::operator+(const Rationnel& ra)
{
    return *(new Rationnel(numerateur*ra.GetDen()+ra.GetNum()*denominateur,ra.GetDen()*denominateur));
}
Rationnel& Rationnel::operator+(const Entier& e)
{
    return *(new Rationnel(numerateur + e.GetVal()*denominateur,denominateur));
}
Reel& Rationnel::operator+(const Reel& r){
    return *(new Reel(r.GetVal()+((double)numerateur/(double)denominateur)));
}
Complexe& Rationnel::operator+(const Complexe& e){
    Base* tmp=dynamic_cast<Base*>(&(*(e.GetReel()) + *(this)));
    return *(new Complexe(tmp, e.GetIm()));
}


// Complexe
Complexe& Complexe::operator+(const Entier& e){

    Base* res=dynamic_cast<Base*>(&(*reel+e));
    return *(new Complexe(res, imaginaire));
}

Complexe& Complexe::operator+(const Rationnel& ra)
{
    Base* res=dynamic_cast<Base*>(&(*reel+ra));
    return *(new Complexe(res, imaginaire));
}

Complexe& Complexe::operator+(const Reel& r){
    Base* res=dynamic_cast<Base*>(&(*reel+r));
    return *(new Complexe(res, imaginaire));
}

Complexe& Complexe::operator +(const Complexe& c){
    Base* tmp1=dynamic_cast<Base*>(&(*reel+c.GetReel()));
    Base* tmp2=dynamic_cast<Base*>(&(*imaginaire+c.GetIm()));

    return *(new Complexe(tmp1, tmp2));
};
