#include "constante.h"
#include <stdio.h>
#include <math.h>

// ------ Pow ------

// Constante
Constante& Constante::powFonction(Constante* c){
    Entier* e=dynamic_cast<Entier*>(c);
    Reel* r=dynamic_cast<Reel*>(c);
    Rationnel* ra=dynamic_cast<Rationnel*>(c);
    Expression* exp=dynamic_cast<Expression*>(c);

    if(e) return (this->powFonction(*e));
    else if(r) return (this->powFonction(*r));
    else if(ra) return (this->powFonction(*ra));
    else if(exp) return (this->powFonction(*exp));
    else throw ExceptionCalculatrice("Erreur d'operation pow");
    return *c;
}


//Expression
Expression& Expression::powFonction(const Entier& e){
    this->exp.remove("'");
    this->exp="'" + this->exp + " " + e.GetQString() + " " + "pow" + "'";
    return *this;
}
Expression& Expression::powFonction(const Reel& e){
    this->exp.remove("'");
    this->exp="'" + this->exp + " " + e.GetQString() + " " + "pow" + "'";
    return *this;
}
Expression& Expression::powFonction(const Rationnel& e){
    this->exp.remove("'");
    this->exp="'" + this->exp + " " + e.GetQString() + " " + "pow" + "'";
    return *this;
}
Expression& Expression::powFonction(const Complexe& e){
    throw ExceptionCalculatrice("Erreur d'operation pow : impossible sur un complexe");
    return *(this);
}
Expression& Expression::powFonction(Expression& e){
    this->exp.remove("'");
    this->exp="'" + this->exp + " " + e.GetQString() + " " + "pow" + "'";
    return *this;
}


// Complexe
Complexe& Complexe::powFonction(const Entier&){
    throw ExceptionCalculatrice("Erreur d'operation pow : impossible sur un complexe");
    return *(this);
}
Complexe& Complexe::powFonction(const Reel&){
    throw ExceptionCalculatrice("Erreur d'operation pow : impossible sur un complexe");
    return *(this);
}
Complexe& Complexe::powFonction(const Rationnel&){
    throw ExceptionCalculatrice("Erreur d'operation pow : impossible sur un complexe");
    return *(this);
}
Complexe& Complexe::powFonction(Expression&){
    throw ExceptionCalculatrice("Erreur d'operation pow : impossible sur un complexe");
    return *(this);
}
Complexe& Complexe::powFonction(const Complexe&){
    throw ExceptionCalculatrice("Erreur d'operation pow : impossible sur un complexe");
    return *(this);
}


// Reel
Reel& Reel::powFonction(const Entier& e){
    return *(new Reel(pow(valeur, (double)e.GetVal())));
}
Reel& Reel::powFonction(const Reel& e){
    return *(new Reel(pow(valeur, e.GetVal())));
}
Reel& Reel::powFonction(const Rationnel&e){
    return *(new Reel(pow(valeur, (e.GetVal()/e.GetValBis()))));
}
Expression& Reel::powFonction(Expression& ex){
    QString tmp1=this->GetQString(), tmp2=ex.GetQString();
    tmp1.remove("'"); tmp2.remove("'");
    ex.SetExp("'" + tmp1 + " " + tmp2 + " " + "pow" + "'");
    return ex;
}
Complexe& Reel::powFonction(const Complexe&){
    throw ExceptionCalculatrice("Erreur d'operation pow : impossible sur un complexe");
}


// Rationnel
Rationnel& Rationnel::powFonction(const Entier& e){
    Rationnel ra((int)pow(numerateur, e.GetVal()), (int)pow(denominateur, e.GetVal()));
    ra.Simplifier();
    return ra;
}
Reel& Rationnel::powFonction(const Reel& e){
    return *(new Reel(pow((numerateur/denominateur),e.GetVal())));
}
Reel& Rationnel::powFonction(const Rationnel& e){
    return *(new Reel(pow((numerateur/denominateur),(e.GetNum()/e.GetDen()))));

}
Expression& Rationnel::powFonction(Expression &ex){
    QString tmp1=this->GetQString(), tmp2=ex.GetQString();
    tmp1.remove("'"); tmp2.remove("'");
    ex.SetExp("'" + tmp1 + " " + tmp2 + " " + "pow" + "'");
    return ex;
}
Complexe& Rationnel::powFonction(const Complexe&){
    throw ExceptionCalculatrice("Erreur d'operation pow : impossible sur un complexe");
}


// Entier
Entier& Entier::powFonction(const Entier& e){
    return *(new Entier(pow(valeur, e.GetVal())));
}
Reel& Entier::powFonction(const Reel& e){
    return *(new Reel(pow(valeur, e.GetVal())));
}
Reel& Entier::powFonction(const Rationnel& e){
    return *(new Reel(pow(valeur, (e.GetNum()/e.GetDen()))));
}
Expression& Entier::powFonction(Expression& ex){
    QString tmp1=this->GetQString(), tmp2=ex.GetQString();
    tmp1.remove("'"); tmp2.remove("'");
    ex.SetExp("'" + tmp1 + " " + tmp2 + " " + "pow" + "'");
    return ex;
}
Complexe& Entier::powFonction(const Complexe&){
    throw ExceptionCalculatrice("Erreur d'operation pow : impossible sur un complexe");
}
