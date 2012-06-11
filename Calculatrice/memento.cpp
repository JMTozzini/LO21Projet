#include "memento.h"

MementoAff* Gardien::AnnulerAff()
{
    if(listeEtatsSauveAff.size()<=1)
        throw ExceptionCalculatrice("Vous ne pouvez pas Annuler d'avantage");
    index-=1;
    MementoAff* tmp=listeEtatsSauveAff[index];

    for(int i=0;i<index;i++)
        std::cout<<""<<std::endl;

    return tmp;
    /*listeEtatsSauveAff.pop_back();
    return(listeEtatsSauveAff.back());*/
}

MementoStock* Gardien::AnnulerStock()
{
    if(listeEtatsSauveStock.size()<=1)
        throw ExceptionCalculatrice("Vous ne pouvez pas Annuler d'avantage");
    std::cout<<"index= "<<index<<std::endl;
    index-=1;
    MementoStock* tmp=listeEtatsSauveStock[index];

    for(int i=0;i<index;i++)
        std::cout<<"existe"<<std::endl;

    return tmp;
    /*listeEtatsSauveStock.pop_back();
    return(listeEtatsSauveStock.back());*/
}
