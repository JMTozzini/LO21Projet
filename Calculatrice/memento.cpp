#include "memento.h"

MementoAff* Gardien::AnnulerAff()
{
    if(listeEtatsSauveAff.size()<=1)
        throw ExceptionCalculatrice("Vous ne pouvez pas Annuler d'avantage");
    --itAff;
    return (*itAff);
}

MementoStock* Gardien::AnnulerStock()
{
    if(listeEtatsSauveStock.size()<=1)
        throw ExceptionCalculatrice("Vous ne pouvez pas Annuler d'avantage");
    --itStock;
    return (*itStock);
}
