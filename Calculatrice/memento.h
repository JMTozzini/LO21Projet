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


public:
   void AjouterMemento(MementoStock* m) {listeEtatsSauveStock.push_back(m);}
   void AjouterMemento(MementoAff* m) {listeEtatsSauveAff.push_back(m);}
   MementoAff* AnnulerAff();
   MementoStock* AnnulerStock();
};

#endif // MEMENTO_H
