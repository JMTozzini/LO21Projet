#include "constante.h"

// ------ Operateur % ------
Constante& Constante::operator%(Constante* c)
{
    Entier* e=dynamic_cast<Entier*>(c);
    //Expression* exp=dynamic_cast<Expression*>(c);

    if(e==0 /*&& exp==0*/)
        throw ExceptionCalculatrice("Modulo impossible, argument(s) non entiers");
    else /*if(exp==0)*/{return (*this % *e);}
    //else {return (*this % *exp);}

}

Constante& Constante::operator%(const Entier& e)
{
    return *(new Entier((int)this->GetVal() % (int)e.GetVal()));
}

