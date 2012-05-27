#include "pile.h"
#include "mainwindow.h"
#include <iostream>

// ----- Pile Stockage -----

void PileStockage::Empiler(Constante& c){ptr.push_back(&c);}

Constante& PileStockage::Depiler()
{
    Constante* tmp=ptr.back();
    ptr.pop_back();
    return *tmp;
}

void PileStockage::AffichagePile()
{
    std::deque<Constante*>::const_iterator deb(ptr.begin()), fin(ptr.end());
    std::cout<<"----"<<std::endl;
    for(;deb!=fin;++deb)
        std::cout<< (*deb)->GetVal() << ' ' <<std::endl;
    std::cout<<"----"<<std::endl;
}


// ----- Pile Affichage -----

void PileAffichage::Empiler(QString c){ptr.push_back(c);}

QString& PileAffichage::Depiler()
{
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
