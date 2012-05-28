#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <string>
#include <QString>
#include <deque>
#include "exceptionCalculatrice.h"

class Entier;
class Reel;
class Rationnel;

class Constante
{
public:
    // Constructeur
    Constante(){}

    // Fonctions annexes virtuelles
    virtual void Afficher(std::ostream& os=std::cout) = 0;
    virtual double GetVal() const = 0;  // Temporaire
    virtual const std::string GetType()const=0;
    virtual double GetValBis() const = 0;

    // Opérateur +
    virtual Constante& operator+(Constante*); // Design Pattern Template Method
    virtual Constante& operator+(const Reel&)=0;
    virtual Constante& operator+(const Entier&)=0;
    virtual Constante& operator+(const Rationnel&)=0;

};

class Base : public Constante{};

class Reel : public Base
{
    double valeur;

public:
    // Constructeurs
    Reel(double r):valeur(r){}
    Reel(QString s):valeur(s.toDouble()){}

    // Fonctions annexes virtuelles
    void Afficher(std::ostream& os=std::cout) {os<<valeur<<std::endl;}
    double GetVal() const {return valeur;}
    double GetValBis() const {throw ExceptionCalculatrice("Un réel n'a pas de dénominateur");}
    const std::string GetType() const {return "reel";}

    // Operateur +
    Reel& operator+(const Reel&);
    Reel& operator+(const Entier&);
    Reel& operator+(const Rationnel&);
};

class Entier : public Base
{
    int valeur;

public:
    // Constructeurs
    Entier(int n):valeur(n){}
    Entier(QString s):valeur(s.toInt()){}

    // Fonctions annexes virtuelles
    void Afficher(std::ostream& os=std::cout) {os<<GetVal()<<std::endl;}
    double GetVal() const {return valeur;}
    double GetValBis() const {return 1;}
    const std::string GetType() const {return "entier";}

    // Operateur +
    Entier& operator+(const Entier&);
    Reel& operator+(const Reel&);
    Rationnel& operator+(const Rationnel&);
};

class Rationnel : public Base // a/b, a : numérateur & b : dénominateur != 0
{
    Entier numerateur;
    Entier denominateur;
// Pourquoi ici tu n'utilises pas directement des int ? Dans l'UML on avait dit qu'un rationnel était composé de deux entiers ?
// Je trouve que ça complique un peu la classe et que ça n'apporte rien parce qu'on peut empiler un rationnel car il hérite de Base
// donc de constante. Après comme tu veux!


public:
    // Constructeurs
    Rationnel(Entier num, Entier den):numerateur(num)
    {
        if(den.GetVal()==0)
            throw ExceptionCalculatrice("Divison par 0 !");
        else
            denominateur=den;
    }
    //Rationnel(QString s):valeur(s.toInt()){}

    // Fonctions annexes virtuelles
    void Afficher(std::ostream& os=std::cout) {os << numerateur.Afficher() << " / " << denominateur.Afficher() << std::endl;}
    double GetVal() const {return numerateur.GetVal();}
    double GetValBis() const {return denominateur.GetVal();}
    const std::string GetType() const {return "rationnel";}

    double GetNum() const {GetVal();} // Pour des raisons de commodité
    double GetDen() const {GetValBis();} // Pour des raisons de commodité


    // Operateur +
    Rationnel& operator+(const Rationnel&);
    Rationnel& operator+(const Entier&);
    Reel& operator+(const Reel&);
};


#endif // CONSTANTE_H

