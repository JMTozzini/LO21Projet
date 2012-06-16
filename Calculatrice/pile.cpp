/**
\file pile.cpp
**/



#include "pile.h"
#include "mainwindow.h"
#include "exceptionCalculatrice.h"
#include <iostream>

// ----- Pile Stockage -----

void PileStockage::Empiler(Constante* c){ptr.push_back(c);}

Constante& PileStockage::Depiler()
{
    if(ptr.size()==0)
        throw ExceptionCalculatrice("Impossible de depiler car la pile est vide...");

    Constante* tmp=ptr.back();
    ptr.pop_back();
    return *tmp;
}

void PileStockage::AffichagePile()
{
    std::deque<Constante*>::const_iterator deb(ptr.begin()), fin(ptr.end());
    std::cout<<"----"<<std::endl;
    for(;deb!=fin;++deb)
        std::cout<< (*deb)->GetType() << ' ' <<std::endl;
    std::cout<<"----"<<std::endl;
}

PileStockage* PileStockage::instance=0;

PileStockage* PileStockage::GetInstance()
{
    if(instance==0)
        instance=new PileStockage();

    else
        std::cout<<"erreur"<<std::endl;

    return instance;
}

void PileStockage::DetruireInstance()
{
    delete instance;
}


// ----- Pile Affichage -----

void PileAffichage::Empiler(QString c)
{
    if(c!="")
        ptr.push_back(c);
    else
        throw ExceptionCalculatrice("Impossible d'empiler une valeur NULL");
}

QString& PileAffichage::Depiler()
{
    if(ptr.size()==0)
        throw ExceptionCalculatrice("Impossible de depiler car la pile est vide...");

    QString* tmp=&(ptr.back());
    ptr.pop_back();
    return *tmp;
}

void PileAffichage::AffichagePile()
{
    std::deque<QString>::const_iterator deb(ptr.begin()), fin(ptr.end());
    //QString s("e"); s.toStdString()
    std::cout<<"----"<<std::endl;
    for(;deb!=fin;++deb)
        std::cout<< (*deb).toStdString() << ' ' <<std::endl;
    std::cout<<"----"<<std::endl;
}


void PileAffichage::Save(std::ostream& os)
{
    std::deque<QString>::const_iterator deb(ptr.begin()), fin(ptr.end());
    for(;deb!=fin;++deb){
        os<< (*deb).toStdString() <<std::endl;
    }

}

PileAffichage* PileAffichage::instance=0;

PileAffichage* PileAffichage::GetInstance()
{
    if(instance==0)
        instance=new PileAffichage();

    else
        std::cout<<"erreur"<<std::endl;

    return instance;
}

void PileAffichage::DetruireInstance()
{
    delete instance;
}
