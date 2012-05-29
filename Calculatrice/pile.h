#ifndef PILE_H
#define PILE_H

#include "constante.h"

class PileStockage
{
    std::deque<Constante*> ptr;

public :
    PileStockage(){}
    void Empiler(Constante& c);
    Constante& Depiler();
    void AffichagePile();
};

class PileAffichage
{
    std::deque<QString> ptr;

public:
    PileAffichage(){}
    void Empiler(QString c);
    QString& Depiler();
    std::deque<QString> GetPtr() const {return ptr;}
    void AffichagePile();
    const QString& GetVal(int i) const {return ptr[i];}
};

#endif // PILE_H
