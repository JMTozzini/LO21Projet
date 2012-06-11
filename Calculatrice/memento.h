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
    void Afficher(){
        for(int i=0;i<etat.size();i++)
        {
            etat[i]->Afficher();
        }
    }
};

class MementoAff
{
    std::deque<QString> etat;

public:
    MementoAff(std::deque<QString> state){etat=state;}
    std::deque<QString> GetEtatSauve() const {return etat;}
};

class Gardien
{
   std::deque<MementoStock*> listeEtatsSauveStock;
   std::deque<MementoAff*> listeEtatsSauveAff;
   int index;

public:
   Gardien():index(0){}
   void AjouterMemento(MementoStock* m) {listeEtatsSauveStock.push_back(m); index++;}
   void AjouterMemento(MementoAff* m) {listeEtatsSauveAff.push_back(m); index++;}
   MementoAff* AnnulerAff();
   MementoStock* AnnulerStock();
};

#endif // MEMENTO_H
