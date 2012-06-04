#include "pile.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

//Méthodes des piles
void PileAffichage::Swap(int x, int y)
{
    QString tmp;
    tmp=ptr[x];
    ptr[x]=ptr[y];
    ptr[y]=tmp;
}

void PileStockage::Swap(int x, int y)
{
    Constante* tmp;
    tmp=ptr[x];
    ptr[x]=ptr[y];
    ptr[y]=tmp;
}

QString PileAffichage::Dup()
{
    if(ptr.size()==0)
        throw ExceptionCalculatrice("Il n'y a pas d'éléments à dupliquer");
    return ptr.front();
}

Constante* PileStockage::Dup()
{
    if(ptr.size()==0)
        throw ExceptionCalculatrice("Il n'y a pas d'éléments à dupliquer");
    return ptr.front();
}

void PileAffichage::Drop()
{
    if(ptr.size()==0)
        throw ExceptionCalculatrice("Impossible de dropper d'avantage");
    ptr.pop_front();
}

void PileStockage::Drop()
{
    if(ptr.size()==0)
        throw ExceptionCalculatrice("Impossible de dropper d'avantage");
    ptr.pop_front();
}

Constante* PileStockage::Sum(int x)
{
    Constante* res=ptr[x-1];
    std::cout<<res->GetVal()<<std::endl;
    for(int i=0;i<x-1;i++){res = &(*res + ptr[i]);}
    return res;
}


// Slots
void MainWindow::SwapPress()
{
    try{pa->Depiler();pa->Depiler();}
    catch(ExceptionCalculatrice e){e.GetInfos();}
    Entier* tmp1=dynamic_cast<Entier*>(&(ps->Depiler()));
    Entier* tmp2=dynamic_cast<Entier*>(&(ps->Depiler()));
    if(tmp1==0 || tmp2==0)
    {
        ExceptionCalculatrice e("Impossible de swapper arguments non entiers");
        e.GetInfos();
    }
    else
    {
        pa->Swap(tmp2->GetVal(),tmp1->GetVal());
        ps->Swap(tmp2->GetVal(),tmp1->GetVal());
    }
    AffichageEcran();
}

void MainWindow::ClearPress()
{
    pa->Clear(); ps->Clear();
    AffichageEcran();
}

void MainWindow::DupPress()
{
    try
    {
        ps->Empiler(ps->Dup());
        pa->Empiler(pa->Dup());
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}
    AffichageEcran();
}

void MainWindow::DropPress()
{
    try
    {
        ps->Drop();
        pa->Drop();
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}
    AffichageEcran();
}

void MainWindow::SumPress()
{
    try
    {
        pa->Depiler();
        Entier* tmp1=dynamic_cast<Entier*>(&(ps->Depiler()));
        Constante* tmp2=ps->Sum(tmp1->GetVal());
        ps->Empiler(tmp2);
        pa->Empiler(tmp2->GetQString());
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}
    AffichageEcran();
}

void MainWindow::MeanPress()
{
    /*
    – MEAN : moyenne des x premiers éléments de la pile (où x est l’argument) (entier, ra-
    tionnel, réel, complexe) : à faire lorsque operator * surchargé
    */
}


