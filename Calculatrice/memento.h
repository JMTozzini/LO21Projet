/**
\file memento.h
\brief Déclaration des classes MementoStock, MementoAff, Gardien
**/

#ifndef MEMENTO_H
#define MEMENTO_H

#include <deque>
#include <iostream>
#include "constante.h"

/*!
  * Cette classe sauvegarde à un chaque changement le contenu de PileStockage.
  * \class MementoStock
  * \brief Classe permettant d'annuler et de rétablir un état de PileStockage.
  */
class MementoStock
{
    std::deque<Constante*> etat;

public:
    MementoStock(std::deque<Constante*> state){etat=state;}
    std::deque<Constante*> GetEtatSauve() const {return etat;}
};

/*!
  * Cette classe sauvegarde à chaque changement le contenu de PileAffichage.
  * \class MementoAff
  * \brief Classe permettant d'annuler et de rétablir un état de PileAffichage.
  */
class MementoAff
{
    std::deque<QString> etat;

public:
    MementoAff(std::deque<QString> state){etat=state;}
    std::deque<QString> GetEtatSauve() const {return etat;}
};

/*!
  * Cette classe sert à sauvegarder les mementos des deux piles, elle peut rétablir ou annuler un état.
  * \class Gardien
  * \brief Classe permettant d'empiler et de dépiler les MementoStock & MementoAff.
  */
class Gardien
{
    std::deque<MementoStock*> listeEtatsSauveStock;
    int indexStock;

    std::deque<MementoAff*> listeEtatsSauveAff;
    int indexAff;

    static Gardien* instance;

public:
    // Constructeur & Destructeur
    static Gardien* GetInstance();
    static void DetruireInstance();

    void AjouterMemento(MementoStock* m);
    MementoStock* AnnulerStock();
    MementoStock* RetablirStock();

    void AjouterMemento(MementoAff* m);
    MementoAff* AnnulerAff();
    MementoAff* RetablirAff();

private :
    Gardien():indexStock(-1),indexAff(-1){}
    void operator=(const Gardien&){}
    ~Gardien(){delete this;}
};

#endif // MEMENTO_H
