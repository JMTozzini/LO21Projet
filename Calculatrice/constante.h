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
    virtual double GetValBis() const = 0; // Temporaire
    virtual const std::string GetType()const=0;


    // Opérateur +
    virtual Constante& operator+(Constante*); // Design Pattern Template Method
    virtual Constante& operator+(const Reel&)=0;
    virtual Constante& operator+(const Entier&)=0;
    virtual Rationnel& operator+(const Rationnel&)=0;
};

class Base : public Constante{
public:
    virtual void Afficher(std::ostream& os=std::cout){}
    virtual double GetVal() const{}  // Temporaire
    virtual double GetValBis() const{} // Temporaire
    virtual const std::string GetType()const{}


    // Opérateur +
    Base& operator+(Base* c);
    virtual Constante& operator+(const Reel&){}
    virtual Constante& operator+(const Entier&){}
    virtual Rationnel& operator+(const Rationnel&){}

};

class Reel : public Base
{
    double valeur;

public:
    // Constructeurs
    Reel(double r=0):valeur(r){}
    Reel(QString s):valeur(s.toDouble()){}

    // Fonctions annexes virtuelles
    void Afficher(std::ostream& os=std::cout) {os<<valeur<<std::endl;}
    double GetVal() const {return valeur;}
    double GetValBis() const {throw ExceptionCalculatrice("Un réel n'a pas de dénominateur");}
    const std::string GetType() const {return "reel";}

    // Operateur +
    Reel& operator+(const Reel&);
    Reel& operator+(const Entier&);
    Rationnel& operator+(const Rationnel&);
};

class Entier : public Base
{
    int valeur;

public:
    // Constructeurs
    Entier(int n=0):valeur(n){}
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

public:
    // Constructeurs
    Rationnel(Entier num, Entier den):numerateur(num)
    {
        if(den.GetVal()==0)
            throw ExceptionCalculatrice("Divison par 0 !");
        else
            denominateur=den;
    }
    Rationnel(int num, int den):numerateur(*(new Entier(num)))
    {
        if(den==0)
            throw ExceptionCalculatrice("Divison par 0 !");
        else
            denominateur=*(new Entier (den));
    }
    //Rationnel(QString s):valeur(s.toInt()){}

    // Fonctions annexes virtuelles
    void Afficher(std::ostream& os=std::cout) {numerateur.Afficher(); os<<"/"; (denominateur.Afficher()); os<< std::endl;}
    double GetVal() const {return numerateur.GetVal();}
    double GetValBis() const {return denominateur.GetVal();}
    const std::string GetType() const {return "rationnel";}

    double GetNum() const {return GetVal();} // Pour des raisons de commodité
    double GetDen() const {return GetValBis();} // Pour des raisons de commodité


    // Operateur +
    Rationnel& operator+(const Rationnel&);
    Rationnel& operator+(const Entier&);
    Rationnel& operator+(const Reel&);
};


class Complexe : public Constante // a$b (correspondant à a+ib), a : reel, b : imaginaire
{
    Base reel;
    Base imaginaire;

public:
    // Constructeurs
    Complexe(Base r, Base i):reel(r), imaginaire(i){}

    // Fonctions annexes virtuelles
    void Afficher(std::ostream& os=std::cout) {reel.Afficher(); os<<"$"; (imaginaire.Afficher()); os<< std::endl;}
    double GetVal() const {return reel.GetVal();}
    double GetValBis() const {return imaginaire.GetVal();}
    const std::string GetType() const {return "complexe";}

    double GetReel() const {return GetVal();} // Pour des raisons de commodité
    double GetIm() const {return GetValBis();} // Pour des raisons de commodité


    // Operateur +
    Rationnel& operator+(const Rationnel&);
    Complexe& operator+(const Entier&);
    Complexe& operator+(const Reel&);
};





#endif // CONSTANTE_H

