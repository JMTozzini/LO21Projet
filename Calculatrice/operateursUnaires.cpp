#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <math.h>
#include <complex>


// COS

Expression& Expression::cosFonction(std::string){
    this->exp.remove("'");
    this->exp="'" + this->exp + " cos"+ "'";
    return *this;
}

Complexe& Complexe::cosFonction(std::string){
    std::complex<double> cmplx (reel->GetVal(), imaginaire->GetVal());
    std::complex<double> res=cos(cmplx);
    Reel* tmp1 = new Reel(res.real());
    Reel* tmp2 = new Reel(res.imag());
    return *(new Complexe(tmp1, tmp2));
}

Reel& Reel::cosFonction(std::string angle){
    if (angle=="degres"){
        double val=cos(valeur*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(cos(valeur)));
}

Reel& Entier::cosFonction(std::string angle){
    if (angle=="degres"){
        double val=cos(valeur*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(cos(valeur)));}

Reel& Rationnel::cosFonction(std::string angle){
    if (angle=="degres"){
        double val=cos((numerateur/denominateur)*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(cos(numerateur/denominateur)));
}


//SIN

Expression& Expression::sinFonction(std::string){
    this->exp.remove("'");
    this->exp="'" + this->exp + " " + "sin"+ "'";
    return *this;
}

Complexe& Complexe::sinFonction(std::string){
    std::complex<double> cmplx (reel->GetVal(), imaginaire->GetVal());
    std::complex<double> res=sin(cmplx);
    Reel* tmp1 = new Reel(res.real());
    Reel* tmp2 = new Reel(res.imag());
    return *(new Complexe(tmp1, tmp2));}

Reel& Reel::sinFonction(std::string angle){
    if (angle=="degres"){
        double val=sin(valeur*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(sin(valeur)));
}

Reel& Entier::sinFonction(std::string angle){
    if (angle=="degres"){
        double val=sin(valeur*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(sin(valeur)));}

Reel& Rationnel::sinFonction(std::string angle){
    if (angle=="degres"){
        double val=sin((numerateur/denominateur)*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(sin(numerateur/denominateur)));
}



//TAN

Expression& Expression::tanFonction(std::string){
    this->exp.remove("'");
    this->exp="'" + this->exp + " tan"+ "'";
    return *this;
}

Complexe& Complexe::tanFonction(std::string){
    std::complex<double> cmplx (reel->GetVal(), imaginaire->GetVal());
    std::complex<double> res=tan(cmplx);
    Reel* tmp1 = new Reel(res.real());
    Reel* tmp2 = new Reel(res.imag());
    return *(new Complexe(tmp1, tmp2));
}

Reel& Reel::tanFonction(std::string angle){
    if (angle=="degres"){
        double val=tan(valeur*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(tan(valeur)));
}

Reel& Entier::tanFonction(std::string angle){
    if (angle=="degres"){
        double val=tan(valeur*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(tan(valeur)));}

Reel& Rationnel::tanFonction(std::string angle){
    if (angle=="degres"){
        double val=tan((numerateur/denominateur)*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(tan(numerateur/denominateur)));
}


// COSH

Expression& Expression::coshFonction(std::string){
    this->exp.remove("'");
    this->exp="'" + this->exp + " cosh"+ "'";
    return *this;
}

Complexe& Complexe::coshFonction(std::string){
    std::complex<double> cmplx (reel->GetVal(), imaginaire->GetVal());
    std::complex<double> res=cosh(cmplx);
    Reel* tmp1 = new Reel(res.real());
    Reel* tmp2 = new Reel(res.imag());
    return *(new Complexe(tmp1, tmp2));
}

Reel& Reel::coshFonction(std::string angle){
    if (angle=="degres"){
        double val=cosh(valeur*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(cosh(valeur)));
}

Reel& Entier::coshFonction(std::string angle){
    if (angle=="degres"){
        double val=cosh(valeur*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(cosh(valeur)));}

Reel& Rationnel::coshFonction(std::string angle){
    if (angle=="degres"){
        double val=cosh((numerateur/denominateur)*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(cosh(numerateur/denominateur)));
}


//SINH

Expression& Expression::sinhFonction(std::string){
    this->exp.remove("'");
    this->exp="'" + this->exp + " " + "sinh"+ "'";
    return *this;
}

Complexe& Complexe::sinhFonction(std::string){
    std::complex<double> cmplx (reel->GetVal(), imaginaire->GetVal());
    std::complex<double> res=sinh(cmplx);
    Reel* tmp1 = new Reel(res.real());
    Reel* tmp2 = new Reel(res.imag());
    return *(new Complexe(tmp1, tmp2));
}

Reel& Reel::sinhFonction(std::string angle){
    if (angle=="degres"){
        double val=sinh(valeur*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(sinh(valeur)));
}

Reel& Entier::sinhFonction(std::string angle){
    if (angle=="degres"){
        double val=sinh(valeur*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(sinh(valeur)));}

Reel& Rationnel::sinhFonction(std::string angle){
    if (angle=="degres"){
        double val=sinh((numerateur/denominateur)*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(sinh(numerateur/denominateur)));
}



//TANH

Expression& Expression::tanhFonction(std::string){
    this->exp.remove("'");
    this->exp="'" + this->exp + " tanh"+ "'";
    return *this;
}

Complexe& Complexe::tanhFonction(std::string){
    std::complex<double> cmplx (reel->GetVal(), imaginaire->GetVal());
    std::complex<double> res=tanh(cmplx);
    Reel* tmp1 = new Reel(res.real());
    Reel* tmp2 = new Reel(res.imag());
    return *(new Complexe(tmp1, tmp2));
}

Reel& Reel::tanhFonction(std::string angle){
    if (angle=="degres"){
        double val=tanh(valeur*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(tanh(valeur)));
}

Reel& Entier::tanhFonction(std::string angle){
    if (angle=="degres"){
        double val=tanh(valeur*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(tanh(valeur)));}

Reel& Rationnel::tanhFonction(std::string angle){
    if (angle=="degres"){
        double val=tanh((numerateur/denominateur)*3.14159265/180.0);
        val=(round(val*10000))/10000;
        return *(new Reel(val));
    }
    return *(new Reel(tanh(numerateur/denominateur)));
}


// Factorielle

Constante& Constante::factFonction()
{
    Entier* e=dynamic_cast<Entier*>(this);
    Expression* exp=dynamic_cast<Expression*>(this);

    if(e)
    {
        return *(new Entier(Factorielle( (int)e->GetVal() )));
    }
    else if(exp)
    {
        QString tmp = exp->GetQString();
        tmp.remove("'");
        exp->SetExp("'" + tmp + " " + "!" + "'");
        return *exp;
    }
    else
        throw ExceptionCalculatrice("Factorielle impossible, argument(s) non entiers ou expression");
}


// Signe

Constante& Constante::signFonction()
{
    Entier* e=dynamic_cast<Entier*>(this);
    Reel* r=dynamic_cast<Reel*>(this);
    Rationnel* ra=dynamic_cast<Rationnel*>(this);
    Expression* exp=dynamic_cast<Expression*>(this);
    Complexe* cmplx=dynamic_cast<Complexe*>(this);

    if(e)
    {
        return *(new Entier(-((int)e->GetVal())));
    }
    else if(r)
    {
        return *(new Reel(-(r->GetVal())));
    }
    else if(ra)
    {
        return *(new Rationnel(-((int)ra->GetNum()) , (int)ra->GetDen() ));
    }
    else if(exp)
    {
        QString tmp = exp->GetQString();
        tmp.remove("'");
        exp->SetExp("'" + tmp + " " + "sign" + "'");
        return *exp;
    }
    else if(cmplx)
    {
        Base* tmp1=dynamic_cast<Base*>(&(cmplx->GetReel()->signFonction()));
        Base* tmp2=dynamic_cast<Base*>(&(cmplx->GetIm()->signFonction()));
        return *(new Complexe(tmp1, tmp2));
    }
    else
        throw ExceptionCalculatrice("Erreur d'operation Signe");
}


// sqr

Constante& Constante::sqrFonction()
{
    Expression* exp=dynamic_cast<Expression*>(this);

    if(exp)
    {
        QString tmp = exp->GetQString();
        tmp.remove("'");
        exp->SetExp("'" + tmp + " " + "sqr" + "'");
        return *exp;
    }
    else
        return (this->operator *(this));
}


// cube

Constante& Constante::cubeFonction()
{
    Expression* exp=dynamic_cast<Expression*>(this);

    if(exp)
    {
        QString tmp = exp->GetQString();
        tmp.remove("'");
        exp->SetExp("'" + tmp + " " + "cube" + "'");
        return *exp;
    }
    else
        return (*this * this * this);
}


// sqrt

Constante& Constante::sqrtFonction()
{
    Entier* e=dynamic_cast<Entier*>(this);
    Reel* r=dynamic_cast<Reel*>(this);
    Rationnel* ra=dynamic_cast<Rationnel*>(this);
    Expression* exp=dynamic_cast<Expression*>(this);

    if(e)
    {
        if((int)sqrt(e->GetVal()) == e->GetVal())
            return *(new Entier((int)sqrt(e->GetVal())));
        else
            return *(new Reel( sqrt(e->GetVal()) ));
    }
    else if(r)
    {
        return *(new Reel (sqrt(e->GetVal()) ));
    }
    else if(ra)
    {
        return *(new Rationnel(sqrt(ra->GetNum()), sqrt(ra->GetDen())));
    }
    else if(exp)
    {
        QString tmp = exp->GetQString();
        tmp.remove("'");
        exp->SetExp("'" + tmp + " " + "sqrt" + "'");
        return *exp;
    }
    else
        throw ExceptionCalculatrice("Erreur d'operation Racine Carré");
}
