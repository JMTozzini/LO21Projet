#ifndef MEMENTO_H
#define MEMENTO_H

#include <deque>
#include <iostream>
#include "constante.h"

class Memento
{
    std::deque<Constante*> etat;

public:
    Memento(std::deque<Constante*> state){etat=state; std::cout<<"Memento crée"<<std::endl;}
    std::deque<Constante*> GetEtatSauve() const {return etat;}
};

class Gardien
{
   std::deque<Memento*> listeEtatsSauve;

public:
   void AjouterMemento(Memento* m) {listeEtatsSauve.push_back(m); std::cout<<"Memento ajouté"<<std::endl;}
   Memento* Annuler() {listeEtatsSauve.pop_back(); return (listeEtatsSauve.back());}
};

#endif // MEMENTO_H
