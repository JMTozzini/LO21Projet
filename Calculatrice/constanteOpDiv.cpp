#include "constante.h"
/*

// ------ Operateur / ------

// Constante
Constante& Constante::operator/(Constante* c)
{
    Entier* e=dynamic_cast<Entier*>(c);
    Reel* r=dynamic_cast<Reel*>(c);
    Rationnel* ra=dynamic_cast<Rationnel*>(c);
    Expression* exp=dynamic_cast<Expression*>(c);
    Complexe* cmplx=dynamic_cast<Complexe*>(c);

    if(e) return (*this / *e);
    else if(r) return (*this / *r);
    else if(ra) return (*this / *ra);
    else if(exp) return (*this / * exp);
    else if(cmplx) return(*this / *cmplx);
    else throw ExceptionCalculatrice("Erreur d'operation *");

    return *c;
}

// Expression
Expression& Expression::operator/(const Entier& e)
{
    this->exp.remove("'");
    this->exp="'" + this->exp + " " + e.GetQString() + " " + "/" + "'";
    return *this;
}
Expression& Expression::operator/(const Reel& r)
{
    this->exp.remove("'");
    this->exp="'" + this->exp + " " + r.GetQString() + " " + "/" + "'";
    return *this;
}
Expression& Expression::operator/(const Rationnel& ra)
{
    this->exp.remove("'");
    this->exp="'" + this->exp + " " + ra.GetQString() + " " + "/" + "'";
    return *this;
}
Expression& Expression::operator/(const Complexe& c)
{
    this->exp.remove("'");
    this->exp="'" + this->exp + " " + c.GetQString() + " " + "/" + "'";
    return *this;
}
Expression& Expression::operator/(Expression& ex)
{
    this->exp.remove("'");
    QString tmp=ex.GetQString();
    tmp.remove("'");
    this->exp="'" + this->exp + " " + tmp + " " + "/" + "'";
    return *this;
}


// Complexe
Complexe& Complexe::operator/(const Entier& e){
    Base* res1=dynamic_cast<Base*>(&(*reel / e));
    Base* res2=dynamic_cast<Base*>(&(*imaginaire / e));
    return *(new Complexe(res1, res2));
}

Complexe& Complexe::operator/(const Rationnel& ra)
{
    Base* res1=dynamic_cast<Base*>(&((*reel * (ra.GetDen())) / ra.GetNum());
    Base* res2=dynamic_cast<Base*>(&((*imaginaire * ra.GetDen())/ra.GetNum());
    return *(new Complexe(res1, res2));
}

Complexe& Complexe::operator/(const Reel& r){
    Base* res1=dynamic_cast<Base*>(&(*reel / r));
    Base* res2=dynamic_cast<Base*>(&(*imaginaire / r));
    return *(new Complexe(res1, res2));
}

Complexe& Complexe::operator/(const Complexe& c){
    Base* tmp1=dynamic_cast<Base*>(&( ((*reel*c.GetReel()) + (*imaginaire*c.GetIm())) / (c.GetReel()*c.GetReel() + c.GetIm()*c.GetIm()) ));
    Base* tmp2=dynamic_cast<Base*>(&( (*imaginaire*c.GetReel() - *reel*c.GetIm()) / (c.GetReel()*c.GetReel() + c.GetIm()*c.GetIm()) ));

    return *(new Complexe(tmp1, tmp2));
}

Expression& Complexe::operator/(Expression& ex)
{
    QString tmp1=this->GetQString(), tmp2=ex.GetQString();
    tmp1.remove("'"); tmp2.remove("'");
    ex.SetExp("'" + tmp1 + " " + tmp2 + " "+ "/" + "'");
    return ex;
}


// Rationnel
Rationnel& Rationnel::operator/(const Rationnel& ra)
{
    return *(new Rationnel(numerateur * ra.GetDen(),ra.GetNum() * denominateur));
}
Rationnel& Rationnel::operator/(const Entier& e)
{
    return *(new Rationnel(numerateur,denominateur * e.GetVal()));
}
Reel& Rationnel::operator/(const Reel& r){
    return *( new Reel( (double)numerateur / (r.GetVal() * denominateur)) );
}
Complexe& Rationnel::operator/(const Complexe& c){
    Base* tmp1=dynamic_cast<Base*>(&( (numerateur * c.GetReel()) / (denominateur * (c.GetReel()*c.GetReel() + c.GetIm()*c.GetIm())) ));
    Base* tmp2=dynamic_cast<Base*>(&( (0 - numerateur * c.GetIm()) / (denominateur * (c.GetReel()*c.GetReel() + c.GetIm()*c.GetIm())) ));
    return *(new Complexe(tmp1, tmp2));
}
Expression& Rationnel::operator/(Expression& ex)
{
    QString tmp1=this->GetQString(), tmp2=ex.GetQString();
    tmp1.remove("'"); tmp2.remove("'");
    ex.SetExp("'" + tmp1 + " " + tmp2 + " "+ "/" + "'");
    return ex;
}


// Reel
Reel& Reel::operator/(const Reel& r) {return *(new Reel(valeur / r.GetVal()));}
Reel& Reel::operator/(const Entier& e) {return *(new Reel(valeur / e.GetVal()));}
Reel& Reel::operator/(const Rationnel& ra){return *(new Reel(valeur / (ra.GetNum() / ra.GetDen())));}
Complexe& Reel::operator/(const Complexe& c){
    Base* tmp1=dynamic_cast<Base*>(&( (valeur*c.GetReel()) / (c.GetReel()*c.GetReel() + c.GetIm()*c.GetIm()) ));
    Base* tmp2=dynamic_cast<Base*>(&( (0-valeur*c.GetIm()) / (c.GetReel()*c.GetReel() + c.GetIm()*c.GetIm()) ));
    return *(new Complexe(tmp1, tmp2));
}
Expression& Reel::operator/(Expression& ex)
{
    QString tmp1=this->GetQString(), tmp2=ex.GetQString();
    tmp1.remove("'"); tmp2.remove("'");
    ex.SetExp("'" + tmp1 + " " + tmp2 + " "+ "/" + "'");
    return ex;
}


// Entier
Rationnel& Entier::operator/(const Entier& e) {return *(new Rationnel(valeur,e.GetVal()));}
Reel& Entier::operator/(const Reel& r){return *(new Reel((double)valeur / r.GetVal()));}
Rationnel& Entier::operator/(const Rationnel& ra)
{
    return *(new Rationnel(ra.GetNum(), ra.GetDen() * valeur));
}
Complexe& Entier::operator*(const Complexe& c){
    Base* tmp1=dynamic_cast<Base*>(&( (valeur*c.GetReel()) / (c.GetReel()*c.GetReel() + c.GetIm()*c.GetIm()) ));
    Base* tmp2=dynamic_cast<Base*>(&( (0-valeur*c.GetIm()) / (c.GetReel()*c.GetReel() + c.GetIm()*c.GetIm()) ));
    return *(new Complexe(tmp1, tmp2));;
}
Expression& Entier::operator/(Expression& ex)
{
    QString tmp1=this->GetQString(), tmp2=ex.GetQString();
    tmp1.remove("'"); tmp2.remove("'");
    ex.SetExp("'" + tmp1 + " " + tmp2 + " "+ "/" + "'");
    return ex;
}
*/
