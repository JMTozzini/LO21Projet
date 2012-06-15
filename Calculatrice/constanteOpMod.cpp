#include "constante.h"

// ------ Operateur % ------
Constante& Constante::operator%(Constante* c)
{
    Entier* e=dynamic_cast<Entier*>(c);
    Expression* exp=dynamic_cast<Expression*>(c);

    //std::cout<<e<<" "<<exp<<std::endl;

    if(e && this->GetType()=="entier") //Entier % Entier
    {
        return *(new Entier((int)this->GetVal() % (int)e->GetVal()));
    }
    else if(exp && this->GetType()=="entier") // Entier % Expression
    {
        QString tmp2=exp->GetQString();
        tmp2.remove("'");
        exp->SetExp("'" + this->GetQString() + " " + tmp2 + " "+ "mod" + "'");
        return *exp;
    }
    else if(e && this->GetType()=="expression") // Expression % Entier
    {
        Expression * ex=dynamic_cast<Expression*>(this);
        QString tmp = this->GetQString();
        tmp.remove("'");
        ex->SetExp("'" + tmp + " " + e->GetQString() + " " + "mod" + "'");
        return *ex;
    }
    else if(exp && this->GetType()=="expression") // Expression % Expression
    {
        Expression * ex=dynamic_cast<Expression*>(this);
        QString tmp1=this->GetQString(),tmp2=exp->GetQString();
        tmp1.remove("'"); tmp2.remove("'");
        ex->SetExp("'" + tmp2 + " " + tmp1 + " " + "mod" + "'");
        return *ex;
    }
    else // Deuxième rideau de sécurité, pas forcément nécessaire...
        throw ExceptionCalculatrice("Modulo impossible, argument(s) non entiers");

}
