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
   std::deque<MementoStock*>::const_iterator itStock;
   std::deque<MementoAff*> listeEtatsSauveAff;
   std::deque<MementoAff*>::const_iterator itAff;


public:
   //Gardien():itStock(listeEtatsSauveStock.begin()),itAff(listeEtatsSauveAff.begin()){}
   void AjouterMemento(MementoStock* m) { itStock=listeEtatsSauveStock.end(); listeEtatsSauveStock.push_back(m);}
   void AjouterMemento(MementoAff* m) { itAff=listeEtatsSauveAff.end(); listeEtatsSauveAff.push_back(m);}
   MementoAff* AnnulerAff();
   MementoStock* AnnulerStock();
};

#endif // MEMENTO_H
