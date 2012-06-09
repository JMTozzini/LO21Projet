#include "pile.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

//Méthodes des piles
void PileAffichage::Swap(unsigned int x, unsigned int y)
{
    QString tmp;
    if(x>=ptr.size() || y>=ptr.size())
        throw ExceptionCalculatrice("Impossible de swapper : arguments incorrects");
    tmp=ptr[x];
    ptr[x]=ptr[y];
    ptr[y]=tmp;
}

void PileStockage::Swap(unsigned int x, unsigned int y)
{
    Constante* tmp;
    if(x>=ptr.size() || y>=ptr.size())
        throw ExceptionCalculatrice("Impossible de swapper : arguments incorrects");
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

Constante* PileStockage::Sum(unsigned int x)
{
    if(x>=ptr.size())
        throw ExceptionCalculatrice("Impossible de sommer : arguments incorrects");
    Constante* res=ptr[x-1];
    std::cout<<res->GetVal()<<std::endl;
    for(unsigned int i=0;i<x-1;i++){res = &(*res + ptr[i]);}
    return res;
}

Constante* PileStockage::Mean(unsigned int x)
{
    Entier *div=new Entier(x);
    if(x>=ptr.size())
        throw ExceptionCalculatrice("Argument trop grand");
    Constante* res=ptr.front();
    for(unsigned int i=1;i<x;i++){res = &(*res + ptr[i]);}
    res = &(*res / div);
    return res;
}

// Slots
void MainWindow::SwapPress()
{
    try
    {
        if(pa->GetPtr().size()<2)
            throw ExceptionCalculatrice("Impossible de swapper pas assez d'arguments");
        QString s1=pa->Depiler(); QString s2=pa->Depiler();
        Entier* tmp1=dynamic_cast<Entier*>(&(ps->Depiler()));
        Entier* tmp2=dynamic_cast<Entier*>(&(ps->Depiler()));
        if(tmp1==0 || tmp2==0 || tmp1->GetVal()<0 || tmp2->GetVal()<0)
        {
            ps->Empiler(tmp2); ps->Empiler(tmp1);
            pa->Empiler(s2); pa->Empiler(s1);
            throw ExceptionCalculatrice("Impossible de swapper arguments non entiers positifs");
        }

        pa->Swap(tmp2->GetVal(),tmp1->GetVal());
        ps->Swap(tmp2->GetVal(),tmp1->GetVal());

    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    MAJParam();
    AffichageEcran();
}

void MainWindow::ClearPress()
{
    pa->Clear(); ps->Clear();
    MAJParam();
    AffichageEcran();
}

void MainWindow::DupPress()
{
    try
    {
        ps->Empiler(ps->Dup());
        pa->Empiler(pa->Dup());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}
    MAJParam();
    AffichageEcran();
}

void MainWindow::DropPress()
{
    try
    {
        ps->Drop();
        pa->Drop();
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}
    MAJParam();
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
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}
    MAJParam();
    AffichageEcran();
}

void MainWindow::MeanPress()
{
    try
    {
        pa->Depiler();
        Entier* tmp1=dynamic_cast<Entier*>(&(ps->Depiler()));
        if(tmp1==0)
        {
            ExceptionCalculatrice e("Impossible de swapper arguments non entiers");
            e.GetInfos();
        }
        Constante* tmp2=ps->Mean(tmp1->GetVal());
        ps->Empiler(tmp2);
        pa->Empiler(tmp2->GetQString());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}
    MAJParam();
    AffichageEcran();
}

void MainWindow::EvalPress()
{
    try
    {
        QString s=pa->Depiler();
        Constante* c=&(ps->Depiler());

        if(c->GetType()=="expression")
        {
            s.remove("'");
            QStringList liste = s.split(" ");
            for(int i=0;i<liste.size();i++)
            {
                ui->champEcr->insert(liste.value(i));
                EntrerPress();
            }

        }
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    ui->champEcr->clear();
    AffichageEcran();
    MAJParam();
}

