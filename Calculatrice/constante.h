#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <string>
#include <QString>
#include <deque>

class Constante
{
public:
    Constante(){}
    virtual void Afficher(std::ostream& os=std::cout) = 0;
    virtual double GetVal() const = 0;  // Temporaire
    virtual Constante* operator+(const Constante&) = 0;
    virtual const std::string GetType() const = 0;
};


class Entier : public Constante
{
    int valeur;

public:
    Entier(int n):valeur(n){}
    Entier(QString s):valeur(s.toInt()){}
    const Constante& Sinus() const {return *this;}
    void Afficher(std::ostream& os=std::cout) {os<<GetVal()<<std::endl;}
    double GetVal() const {return valeur;}
    const std::string GetType() const {return "je suis un entier";}
    Entier* operator+(const Constante& e) {return (new Entier(valeur + e.GetVal()));}
};

class Reel : public Constante
{
    double valeur;

public:
    Reel(double r):valeur(r){}
    const Constante& Sinus() const {return *this;}
    void Afficher(std::ostream& os=std::cout) {os<<valeur<<std::endl;}
    double GetVal() const {return valeur;}
    const std::string GetType() const {return "je suis un réel";}
    Reel* operator+(const Constante& e) {return (new Reel(valeur + e.GetVal()));}
};

#endif // CONSTANTE_H
