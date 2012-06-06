#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <math.h>


// COS

Expression& Expression::cosFonction(std::string){
    this->exp.remove("'");
    this->exp="'" + this->exp + " cos"+ "'";
    return *this;
}

Complexe& Complexe::cosFonction(std::string){
    throw ExceptionCalculatrice("Cos impossible sur complexe");
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
    throw ExceptionCalculatrice("sin impossible sur complexe");
}

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
    throw ExceptionCalculatrice("tan impossible sur complexe");
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
