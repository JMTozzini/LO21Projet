#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <string>
#include <QString>
#include <deque>
#include "exceptionCalculatrice.h"

class Complexe;
class Reel;
class Rationnel;
class Entier;
class Expression;


class Constante
{
public:
    // Constructeur
    Constante(){}
    virtual ~Constante(){delete this;}

    // Fonctions annexes virtuelles
    virtual void Afficher(std::ostream& os=std::cout)const = 0;
    virtual double GetVal() const = 0;      // Temporaire
    virtual double GetValBis() const = 0;   // Temporaire
    virtual const std::string GetType()const=0;
    virtual QString GetQString()const=0;
    virtual void Simplifier(){}


    // Opérateur +
    virtual Constante& operator+(Constante*); // Design Pattern Template Method
    virtual Constante& operator+(const Reel&)=0;
    virtual Constante& operator+(const Entier&)=0;
    virtual Constante& operator+(const Rationnel&)=0;
    virtual Constante& operator+(const Complexe&)=0;
    virtual Constante& operator+(Expression&)=0;

    // Opérateur -
    virtual Constante& operator-(Constante*); // Design Pattern Template Method
    virtual Constante& operator-(const Reel&)=0;
    virtual Constante& operator-(const Entier&)=0;
    virtual Constante& operator-(const Rationnel&)=0;
    virtual Constante& operator-(const Complexe&)=0;
    virtual Constante& operator-(Expression&)=0;

    // Opérateur *
    virtual Constante& operator*(Constante*); // Design Pattern Template Method
    virtual Constante& operator*(const Reel&)=0;
    virtual Constante& operator*(const Entier&)=0;
    virtual Constante& operator*(const Rationnel&)=0;
    virtual Constante& operator*(const Complexe&)=0;
    virtual Constante& operator*(Expression&)=0;

    // Opérateur /
    virtual Constante& operator/(Constante*); // Design Pattern Template Method
    virtual Constante& operator/(const Reel&)=0;
    virtual Constante& operator/(const Entier&)=0;
    virtual Constante& operator/(const Rationnel&)=0;
    virtual Constante& operator/(const Complexe&)=0;
    virtual Constante& operator/(Expression&)=0;

    // Opérateur %
    virtual Constante& operator%(Constante *);

    // Operateurs sur les angles
    virtual Constante& cosFonction(std::string)=0;
    virtual Constante& sinFonction(std::string)=0;
    virtual Constante& tanFonction(std::string)=0;
    virtual Constante& coshFonction(std::string)=0;
    virtual Constante& sinhFonction(std::string)=0;
    virtual Constante& tanhFonction(std::string)=0;

    // pow
    virtual Constante& powFonction(Constante*);
    virtual Constante& powFonction(const Entier&)=0;
    virtual Constante& powFonction(const Reel&)=0;
    virtual Constante& powFonction(const Rationnel&)=0;
    virtual Constante& powFonction(const Complexe&)=0;
    virtual Constante& powFonction(Expression&)=0;

    // Factorielle
    virtual Constante& factFonction();

    // Signe
    virtual Constante& signFonction();

    // sqr
    virtual Constante& sqrFonction();

    //cube
    virtual Constante& cubeFonction();

    //sqrt
    virtual Constante& sqrtFonction();
};


class Expression : public Constante
{
    QString exp;

public:
    Expression(QString s):exp(s){}
    ~Expression(){delete this;}

    void Afficher(std::ostream& os=std::cout)const {os<<exp.toStdString()/*<< std::endl*/;}
    double GetVal() const {throw ExceptionCalculatrice("Fonction non définie\n");}
    double GetValBis() const {throw ExceptionCalculatrice("Fonction non définie\n");}
    const std::string GetType() const {return "expression";}
    QString GetQString() const {return exp;}
    void SetExp(QString s){exp=s;}

    // Operateur +
    Expression& operator+(const Entier&);
    Expression& operator+(const Reel&);
    Expression& operator+(const Rationnel&);
    Expression& operator+(const Complexe&);
    Expression& operator+(Expression&);

    // Operateur -
    Expression& operator-(const Entier&);
    Expression& operator-(const Reel&);
    Expression& operator-(const Rationnel&);
    Expression& operator-(const Complexe&);
    Expression& operator-(Expression&);

    // Operateur *
    Expression& operator*(const Entier&);
    Expression& operator*(const Reel&);
    Expression& operator*(const Rationnel&);
    Expression& operator*(const Complexe&);
    Expression& operator*(Expression&);

    // Operateur /
    Expression& operator/(const Entier&);
    Expression& operator/(const Reel&);
    Expression& operator/(const Rationnel&);
    Expression& operator/(const Complexe&);
    Expression& operator/(Expression&);

    // Operateurs sur les angles
    Expression& cosFonction(std::string);
    Expression& sinFonction(std::string);
    Expression& tanFonction(std::string);
    Expression& coshFonction(std::string);
    Expression& sinhFonction(std::string);
    Expression& tanhFonction(std::string);

    // pow
    Expression& powFonction(const Entier&);
    Expression& powFonction(const Reel&);
    Expression& powFonction(const Rationnel&);
    Expression& powFonction(const Complexe&);
    Expression& powFonction(Expression &);
};


class Base : public Constante{
public :
    virtual void Afficher(std::ostream& os=std::cout)const = 0;
    virtual ~Base(){delete this;}
};

class Complexe : public Constante // a$b (correspondant à a+ib), a : reel, b : imaginaire
{
    Base* reel;
    Base* imaginaire;

public:
    // Constructeurs
    Complexe(Base* r, Base* i):reel(r), imaginaire(i){}
    ~Complexe(){delete[] reel; delete[] imaginaire;}

    // Fonctions annexes virtuelles
    void Afficher(std::ostream& os=std::cout)const {reel->Afficher(os); os<<"$"; imaginaire->Afficher(os); /*os<< std::endl;*/}
    double GetVal() const {return reel->GetVal();}
    double GetValBis() const {return imaginaire->GetVal();}
    const std::string GetType() const {return "complexe";}
    QString GetQString() const {return (reel->GetQString()+"$"+imaginaire->GetQString());}

    Base* GetReel() const {return reel;}   // Pour des raisons de commodité
    Base* GetIm() const {return imaginaire;}  // Pour des raisons de commodité


    // Operateur +
    Complexe& operator+(const Entier&);
    Complexe& operator+(const Reel&);
    Complexe& operator+(const Rationnel&);
    Complexe& operator+(const Complexe&);
    Expression& operator+(Expression&);

    // Operateur -
    Complexe& operator-(const Entier&);
    Complexe& operator-(const Reel&);
    Complexe& operator-(const Rationnel&);
    Complexe& operator-(const Complexe&);
    Expression& operator-(Expression&);

    // Operateur *
    Complexe& operator*(const Entier&);
    Complexe& operator*(const Reel&);
    Complexe& operator*(const Rationnel&);
    Complexe& operator*(const Complexe&);
    Expression& operator*(Expression&);

    // Operateur /
    Complexe& operator/(const Entier&);
    Complexe& operator/(const Reel&);
    Complexe& operator/(const Rationnel&);
    Complexe& operator/(const Complexe&);
    Expression& operator/(Expression&);

    // Operateurs sur les angles
    Complexe& cosFonction(std::string);
    Complexe& sinFonction(std::string);
    Complexe& tanFonction(std::string);
    Complexe& coshFonction(std::string);
    Complexe& sinhFonction(std::string);
    Complexe& tanhFonction(std::string);

    // pow
    Complexe& powFonction(const Entier&);
    Complexe& powFonction(const Reel&);
    Complexe& powFonction(const Rationnel&);
    Complexe& powFonction(Expression&);
    Complexe& powFonction(const Complexe&);
};



class Reel : public Base
{
    double valeur;

public:
    // Constructeurs
    Reel(double r=0):valeur(r){}
    Reel(QString s):valeur(s.toDouble()){}
    ~Reel(){delete this;}

    // Fonctions annexes virtuelles
    void Afficher(std::ostream& os=std::cout)const {os<<valeur/*<<std::endl*/;}
    double GetVal() const {return valeur;}
    double GetValBis() const {throw ExceptionCalculatrice("Un réel n'a pas de dénominateur");}
    const std::string GetType() const {return "reel";}
    QString GetQString() const {QString s(QString::number(valeur)); s.replace(s.indexOf("."),1,","); return s;}

    // Operateur +
    Reel& operator+(const Reel&);
    Reel& operator+(const Entier&);
    Reel& operator+(const Rationnel&);
    Complexe& operator+(const Complexe&);
    Expression& operator+(Expression&);

    // Operateur -
    Reel& operator-(const Reel&);
    Reel& operator-(const Entier&);
    Reel& operator-(const Rationnel&);
    Complexe& operator-(const Complexe&);
    Expression& operator-(Expression&);

    // Operateur *
    Reel& operator*(const Reel&);
    Reel& operator*(const Entier&);
    Reel& operator*(const Rationnel&);
    Complexe& operator*(const Complexe&);
    Expression& operator*(Expression&);

    // Operateur /
    Reel& operator/(const Reel&);
    Reel& operator/(const Entier&);
    Reel& operator/(const Rationnel&);
    Complexe& operator/(const Complexe&);
    Expression& operator/(Expression&);

    // Operateurs sur les angles
    Reel& cosFonction(std::string);
    Reel& sinFonction(std::string);
    Reel& tanFonction(std::string);
    Reel& coshFonction(std::string);
    Reel& sinhFonction(std::string);
    Reel& tanhFonction(std::string);

    // pow
    Reel& powFonction(const Entier&);
    Reel& powFonction(const Reel&);
    Reel& powFonction(const Rationnel&);
    Expression& powFonction(Expression&);
    Complexe& powFonction(const Complexe&);
};


class Rationnel : public Base // a/b, a : numérateur & b : dénominateur != 0
{
    int numerateur;
    int denominateur;

public:
    // Constructeurs
    Rationnel(int num, int den):numerateur(num)
    {
        //if(den==0)
            /*throw ExceptionCalculatrice("Divison par 0 !");*/
        //else
            denominateur=den;
    }
    ~Rationnel(){delete this;}

    // Fonctions annexes virtuelles
    void Afficher(std::ostream& os=std::cout)const { os<<numerateur << "/" << denominateur /*<< std::endl*/;}
    double GetVal() const {return numerateur;}
    double GetValBis() const {return denominateur;}
    const std::string GetType() const {return "rationnel";}
    QString GetQString() const {return (QString::number(numerateur)+"/"+QString::number(denominateur));}

    double GetNum() const {return GetVal();}    // Pour des raisons de commodité
    double GetDen() const {return GetValBis();} // Pour des raisons de commodité
    void Simplifier();


    // Operateur +
    Rationnel& operator+(const Rationnel&);
    Rationnel& operator+(const Entier&);
    Reel& operator+(const Reel&);
    Complexe& operator+(const Complexe&);
    Expression& operator+(Expression&);

    // Operateur -
    Rationnel& operator-(const Rationnel&);
    Rationnel& operator-(const Entier&);
    Reel& operator-(const Reel&);
    Complexe& operator-(const Complexe&);
    Expression& operator-(Expression&);

    // Operateur *
    Rationnel& operator*(const Rationnel&);
    Rationnel& operator*(const Entier&);
    Reel& operator*(const Reel&);
    Complexe& operator*(const Complexe&);
    Expression& operator*(Expression&);

    // Operateur /
    Rationnel& operator/(const Rationnel&);
    Rationnel& operator/(const Entier&);
    Reel& operator/(const Reel&);
    Complexe& operator/(const Complexe&);
    Expression& operator/(Expression&);

    // Operateurs sur les angles
    Reel& cosFonction(std::string);
    Reel& sinFonction(std::string);
    Reel& tanFonction(std::string);
    Reel& coshFonction(std::string);
    Reel& sinhFonction(std::string);
    Reel& tanhFonction(std::string);

    // pow
    Rationnel& powFonction(const Entier&);
    Reel& powFonction(const Reel&);
    Reel& powFonction(const Rationnel&);
    Expression& powFonction(Expression&);
    Complexe& powFonction(const Complexe&);
};


class Entier : public Base
{
    int valeur;

public:
    // Constructeurs
    Entier(int n=0):valeur(n){}
    Entier(QString s):valeur(s.toInt()){}
    ~Entier(){delete this;}

    // Fonctions annexes virtuelles
    void Afficher(std::ostream& os=std::cout)const {os<<GetVal()/*<<std::endl*/;}
    double GetVal() const {return valeur;}
    double GetValBis() const {return 1;}
    const std::string GetType() const {return "entier";}
    QString GetQString() const {return (QString::number(valeur));}

    // Operateur +
    Entier& operator+(const Entier&);
    Reel& operator+(const Reel&);
    Rationnel& operator+(const Rationnel&);
    Complexe& operator +(const Complexe&);
    Expression& operator+(Expression&);

    // Operateur -
    Entier& operator-(const Entier&);
    Reel& operator-(const Reel&);
    Rationnel& operator-(const Rationnel&);
    Complexe& operator -(const Complexe&);
    Expression& operator-(Expression&);

    // Operateur *
    Entier& operator*(const Entier&);
    Reel& operator*(const Reel&);
    Rationnel& operator*(const Rationnel&);
    Complexe& operator *(const Complexe&);
    Expression& operator*(Expression&);

    // Operateur /
    Rationnel& operator/(const Entier&);
    Reel& operator/(const Reel&);
    Rationnel& operator/(const Rationnel&);
    Complexe& operator /(const Complexe&);
    Expression& operator/(Expression&);

    // Operateurs sur les angles
    Reel& cosFonction(std::string);
    Reel& sinFonction(std::string);
    Reel& tanFonction(std::string);
    Reel& coshFonction(std::string);
    Reel& sinhFonction(std::string);
    Reel& tanhFonction(std::string);

    // pow
    Entier& powFonction(const Entier&);
    Reel& powFonction(const Reel&);
    Reel& powFonction(const Rationnel&);
    Expression& powFonction(Expression&);
    Complexe& powFonction(const Complexe&);
};



#endif // CONSTANTE_H

