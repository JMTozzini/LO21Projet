#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <math.h>


Expression& Expression::cosFonction(std::string){
    this->exp.remove("'");
    this->exp="'" + this->exp + "cos"+ "'";
    return *this;
}

Complexe& Complexe::cosFonction(std::string){
    throw ExceptionCalculatrice("Cos impossible sur complexe"); //elle est réalisée dans un bloc try
    //e.GetInfos();
    ///return *(this);
}

Reel& Reel::cosFonction(std::string angle){
    if (angle=="degres"){
        double val=cos(valeur*3.14159265/180.0);
        return *(new Reel(val));
    }
    return *(new Reel(cos(valeur)));
}

Reel& Entier::cosFonction(std::string angle){
    if (angle=="degres") return *(new Reel(cos(valeur*3.14159265/180.0)));
    return *(new Reel(cos(valeur)));}

Reel& Rationnel::cosFonction(std::string angle){
    if (angle=="degres") return *(new Reel(cos((numerateur/denominateur)*3.14159265/180.0)));
    return *(new Reel(cos(numerateur/denominateur)));
}
