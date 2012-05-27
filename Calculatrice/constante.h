#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <string>
#include <QString>
#include <deque>

class Entier;
class Reel;

class Constante
{
public:
    Constante(){}
    virtual void Afficher(std::ostream& os=std::cout) = 0;
    virtual double GetVal() const = 0;  // Temporaire
    virtual const std::string GetType()const=0;

    // Opérateur +
    virtual Constante& operator+(Constante*); // Design Pattern Template Method
    virtual Constante& operator+(const Reel&)=0;
    virtual Constante& operator+(const Entier&)=0;

};

class Base : public Constante{};

class Reel : public Base
{
    double valeur;

public:
    // Constructeurs
    Reel(double r):valeur(r){}
    Reel(QString s):valeur(s.toDouble()){}

    void Afficher(std::ostream& os=std::cout) {os<<valeur<<std::endl;}
    double GetVal() const {return valeur;}
    const std::string GetType() const {return "reel";}

    // Operateur +
    Reel& operator+(const Reel&);
    Reel& operator+(const Entier&);
};

class Entier : public Base
{
    int valeur;

public:
    // Constructeurs
    Entier(int n):valeur(n){}
    Entier(QString s):valeur(s.toInt()){}

    void Afficher(std::ostream& os=std::cout) {os<<GetVal()<<std::endl;}
    double GetVal() const {return valeur;}
    const std::string GetType() const {return "entier";}

    // Operateur +
    Entier& operator+(const Entier&);
    Reel& operator+(const Reel&);
};


#endif // CONSTANTE_H

