/**
\file fonctionAnnexe.cpp
\brief Fonctions annexes facilitant certains traitements ou calcules.
**/



#include "fonctionsAnnexe.h"
#include "constante.h"

Reel* ToReel(QString& s){
    s.remove(" ");
    s.replace(s.indexOf(","),1,".");
    return new Reel(s);
}

Rationnel* ToRationnel(QString& s){
    Rationnel* ra=NULL;
    s.remove(" ");
    QStringList list1 = s.split("/");
    int tmp=list1.value(0).toInt(), tmp2=list1.value(1).toInt();
    if(!tmp2)
        throw ExceptionCalculatrice("Erreur : le denominateur d'un rationnel ne peut pas etre nul");
    ra=new Rationnel(list1.value(0).toInt(),list1.value(1).toInt());
    ra->Simplifier();
    return ra;
}

Complexe* ToComplexe(QString& s)
{
    s.remove(" ");
    QStringList list1 = s.split("$");
    QString reel=list1.value(0), im=list1.value(1);
    Base *b1,*b2;

    if(reel.contains(",")) b1=ToReel(reel);
    else if(reel.contains("/")) b1=ToRationnel(reel);
    else b1=new Entier(reel.toInt());

    if(im.contains(",")) b2=ToReel(im);
    else if(im.contains("/")) b2=ToRationnel(im);
    else b2=new Entier(im.toInt());

    return (new Complexe(b1, b2));
}

int pgcd(int a, int b)
{
    return (b == 0 ? a : pgcd(b, a%b));
}


void Rationnel::Simplifier()
{
    int g = pgcd(numerateur, denominateur);
    numerateur/=g;
    denominateur/=g;
    std::cout<<std::endl;
}


int Factorielle(int n)
{
    if(n==0)
        return 1;
    else
        return (n*Factorielle(n-1));
}
