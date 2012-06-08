#include "memento.h"

MementoAff* Gardien::AnnulerAff()
{
    if(indexAff<1)
        throw ExceptionCalculatrice("Vous ne pouvez pas Annuler d'avantage");

    return listeEtatsSauveAff[--indexAff];
}

MementoAff* Gardien::RetablirAff()
{
    if((unsigned int) indexAff >= listeEtatsSauveAff.size()-1)
        throw ExceptionCalculatrice("Impossible de rétablir d'avantage");

    return listeEtatsSauveAff[++indexAff];
}

void Gardien::AjouterMemento(MementoAff *m)
{
    if(indexAff!=(listeEtatsSauveAff.size()-1))
    {
        for(unsigned int i=indexAff;i<listeEtatsSauveAff.size();i++)
            listeEtatsSauveAff.pop_back();
    }

    listeEtatsSauveAff.push_back(m);
    indexAff++;
}

MementoStock* Gardien::AnnulerStock()
{
    if(indexStock<1)
        throw ExceptionCalculatrice("Vous ne pouvez pas Annuler d'avantage");

    return listeEtatsSauveStock[--indexStock];
}

MementoStock* Gardien::RetablirStock()
{
    if((unsigned int)indexStock >= listeEtatsSauveStock.size()-1)
        throw ExceptionCalculatrice("Impossible de rétablir d'avantage");

    return listeEtatsSauveStock[++indexStock];
}

void Gardien::AjouterMemento(MementoStock *m)
{
    if(indexStock!=(listeEtatsSauveStock.size()-1))
    {
        for(unsigned int i=indexStock;i<listeEtatsSauveStock.size();i++)
            listeEtatsSauveStock.pop_back();
    }

    listeEtatsSauveStock.push_back(m);
    indexStock++;
}
