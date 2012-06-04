#include "memento.h"

MementoAff* Gardien::AnnulerAff()
{
    if(listeEtatsSauveAff.size()<=1)
        throw ExceptionCalculatrice("Vous ne pouvez pas Annuler d'avantage");
    listeEtatsSauveAff.pop_back();
    return (listeEtatsSauveAff.back());
}
MementoStock* Gardien::AnnulerStock()
{
    if(listeEtatsSauveStock.size()<=1)
        throw ExceptionCalculatrice("Vous ne pouvez pas Annuler d'avantage");
    listeEtatsSauveStock.pop_back();
    return (listeEtatsSauveStock.back());
}
