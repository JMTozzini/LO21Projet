#ifndef PILE_H
#define PILE_H

#include "constante.h"
#include "memento.h"

class PileStockage
{
    std::deque<Constante*> ptr;
    static PileStockage* instance;

public :
    // Constructeur & Destructeur
    static PileStockage* GetInstance();
    static void DetruireInstance();

    // Méthodes de base
    void Empiler(Constante*);
    Constante& Depiler();
    std::deque<Constante*> GetPtr() const {return ptr;}
    void AffichagePile();

    // Méthodes d'historique
    MementoStock* CreerMemento(){return new MementoStock(ptr);}
    void ChargerMemento(MementoStock *mem){ptr = mem->GetEtatSauve();}

    // Méthodes d'opérations
    void Swap(unsigned int, unsigned int);
    void Clear(){ptr.clear();}
    Constante* Dup();
    void Drop();
    Constante* Sum(unsigned int);
    Constante* Mean(unsigned int);

private:
    PileStockage(){}
    void operator=(const PileStockage&){}
    ~PileStockage(){delete this;}
};

class PileAffichage
{
    std::deque<QString> ptr;
    static PileAffichage* instance;

public:
    // Constructeur & Destructeur
    static PileAffichage* GetInstance();
    static void DetruireInstance();

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
    void Swap(unsigned int, unsigned int);
    void Clear(){ptr.clear();}
    QString Dup();
    void Drop();

    // Sauvegarde dans un fichier
    void Save(std::ostream& os);

private:
    PileAffichage(){}
    void operator=(const PileAffichage&){}
    ~PileAffichage(){delete this;}
};

#endif // PILE_H
