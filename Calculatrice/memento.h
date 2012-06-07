#ifndef MEMENTO_H
#define MEMENTO_H

#include <deque>
#include <iostream>
#include "constante.h"

class MementoStock
{
    std::deque<Constante*> etat;

public:
    MementoStock(std::deque<Constante*> state){etat=state;}
    std::deque<Constante*> GetEtatSauve() const {return etat;}
    void test(){etat[0]->Afficher();}
};

class MementoAff
{
    std::deque<QString> etat;

public:
    MementoAff(std::deque<QString> state){etat=state;}
    std::deque<QString> GetEtatSauve() const {return etat;}
    void test(){std::cout<<etat[0].toStdString()<<std::endl;}
};

class Gardien
{
   std::deque<MementoStock*> listeEtatsSauveStock;
   int indexStock;

   std::deque<MementoAff*> listeEtatsSauveAff;
   int indexAff;

public:
   Gardien():indexStock(-1),indexAff(-1){}

   void AjouterMemento(MementoStock* m);
   MementoStock* AnnulerStock();
   MementoStock* RetablirStock();

   void AjouterMemento(MementoAff* m);
   MementoAff* AnnulerAff();
   MementoAff* RetablirAff();
};

#endif // MEMENTO_H
