#ifndef PILE_H
#define PILE_H

#include "constante.h"
#include "memento.h"

class PileStockage
{
    std::deque<Constante*> ptr;

public :
    PileStockage(){}

    // Méthodes de base
    void Empiler(Constante&);
    Constante& Depiler();
    std::deque<Constante*> GetPtr() const {return ptr;}
    void AffichagePile();

    // Méthodes d'historique
    MementoStock* CreerMemento(){return new MementoStock(ptr);}
    void ChargerMemento(MementoStock *mem){ptr = mem->GetEtatSauve();}

    // Méthodes d'opérations
    void Swap(int x, int y);
    void Clear(){ptr.clear();}
    Constante* Dup();
    void Drop();
};

class PileAffichage
{
    std::deque<QString> ptr;

public:
    PileAffichage(){}

    // Méthodes de base
    void Empiler(QString);
    QString& Depiler();
    std::deque<QString> GetPtr() const {return ptr;}
    void AffichagePile();
    const QString& GetVal(int i) const {return ptr[i];}

    // Méthodes d'historique
    MementoAff* CreerMemento(){return new MementoAff(ptr);}
    void ChargerMemento(MementoAff *mem){ptr = mem->GetEtatSauve();}

    // Méthodes d'opérations
    void Swap(int x, int y);
    void Clear(){ptr.clear();}
    QString Dup();
    void Drop();
};

#endif // PILE_H
