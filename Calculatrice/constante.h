/**
\file constante.h
\author Agathe Oddon et Jean-Michel Tozzini
\date 10/06/2012
\version 1

\brief Déclaration de la classe Constante et de ses classes filles
**/

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


/*!
  * \class Constante
  * \brief Classe mère de toutes les valeurs empilées dans la pile de stockage
  */

class Constante
{
public:
    // Constructeur
    Constante(){}
    virtual ~Constante(){delete this;}

    // Fonctions annexes virtuelles
    /*!
      * \brief Fonction virtuelle pour l'affichage, affichant une constante en console.
      * \param os flux d'affichage
      */
    virtual void Afficher(std::ostream& os=std::cout)const = 0;
    /*!
      * \brief Fonction permettant de récupérer la valeur principale des différentes constantes.
      * \return Double.
      */
    virtual double GetVal() const = 0;      // Temporaire
    /*!
      * \brief Fonction permettant de récupérer la valeur secondaire des différentes constantes.
      * \return Double.
      */
    virtual double GetValBis() const = 0;   // Temporaire
    /*!
      * \brief Fonction permettant de récupérer la valeur du type des différentes constantes.
      * \return String.
      */
    virtual const std::string GetType()const=0;
    /*!
      * \brief Fonction permettant de transformer une Constante en QString.
      * \return QString.
      */
    virtual QString GetQString()const=0;
    virtual void Simplifier(){}


    // Opérateur +
    /*!
      * Surcharge permettant de réaliser l'opération + pour les différentes constantes. Lors d'une opération c'est l'opérateur +
      * de Constante qui est appelé et qui délègue en fonction du type de Constante au surcharge des classes filles.
      * \brief Fonction permetant de surcharger l'opérateur +.
      * \return Référence sur Constante.
      */
    virtual Constante& operator+(Constante*); // Design Pattern Template Method
    virtual Constante& operator+(const Reel&)=0;
    virtual Constante& operator+(const Entier&)=0;
    virtual Constante& operator+(const Rationnel&)=0;
    virtual Constante& operator+(const Complexe&)=0;
    virtual Constante& operator+(Expression&)=0;

    // Opérateur -
    /*!
      * Surcharge permettant de réaliser l'opération - pour les différentes constantes. Lors d'une opération c'est l'opérateur -
      * de Constante qui est appelé et qui délègue en fonction du type de Constante au surcharge des classes filles.
      * \brief Fonction permetant de surcharger l'opérateur -.
      * \return Référence sur Constante.
      */
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

    // Sqr
    virtual Constante& sqrFonction();

    // Cube
    virtual Constante& cubeFonction();

    // Sqrt
    virtual Constante& sqrtFonction();

    // Inv
    virtual Constante& invFonction();

    // Ln & Log
    virtual Constante& lnFonction();
    virtual Constante& logFonction();
};

/*!
  * Le type expression est une Chaîne de caractères déclaré entre quote, pouvant reporter un calcule. Ce dernier ne peut-être réalisé
  * qu'à travers la fonction eval.
  * \class Expression
  * \brief Classe permettant de gérer le type expression pouvant être évaluer à tout moment.
  */
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
    /*!
      * \brief Fonction permettant de d'affecter la valeur de l'expression.
      */
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

/*!
  * \class Base
  * \brief Classe englobant les types Rationnel, Réel et Entier. Elle compose la classe Complexe.
  */
class Base : public Constante{
public :
    virtual void Afficher(std::ostream& os=std::cout)const = 0;
    virtual ~Base(){delete this;}
};

/*!
  * \class Complexe
  * \brief Classe permettant de représenter le type Complexe. Chacune de ses parties (Réelle & Imaginaire) est une Base.
  */
class Complexe : public Constante
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

    /*!
      * \brief Fonction permettant de récupérer la partie Réelle du Complexe.
      * \return Pointeur sur Base
      */
    Base* GetReel() const {return reel;}   // Pour des raisons de commodité
    /*!
      * \brief Fonction permettant de récupérer la partie Imaginaire du Complexe.
      * \return Pointeur sur Base
      */
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

/*!
  * \class Reel
  * \brief Classe permettant de représenter le type Réel.
  */
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

/*!
  * \class Rationnel
  * \brief Classe permettant de représenter le type Rationnel.
  */
class Rationnel : public Base
{
    int numerateur;
    int denominateur;

public:
    // Constructeurs
    Rationnel(int num, int den):numerateur(num)
    {
        if(den==0)
            throw ExceptionCalculatrice("Divison par 0 !");
        else
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
    /*!
      * \brief Fonction permattant de simplifier un Rationnel.
      */
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

/*!
  * \class Entier
  * \brief Classe permettant de représenter le type Entier.
  */
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

