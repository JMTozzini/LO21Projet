#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::PlusPress()
{
    if(pa->GetPtr().size()<2)
    {
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        e.GetInfos();
    }
    else
    {
        try
        {
            pa->Depiler(); pa->Depiler();

            Constante* tmp1=&(ps->Depiler());
            Constante* tmp2=&(ps->Depiler());
            Constante* c;
            c = &(tmp2->operator +(tmp1));

            ps->Empiler(c);
            pa->Empiler(c->GetQString());
        }
        catch(ExceptionCalculatrice e){e.GetInfos();}

        g->AjouterMemento(ps->CreerMemento());
        g->AjouterMemento(pa->CreerMemento());
    }
    //pa->AffichagePile();
    //ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}


void MainWindow::MoinsPress()
{
    if(pa->GetPtr().size()<2)
    {
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        e.GetInfos();
    }
    else
    {
        try
        {
            pa->Depiler(); pa->Depiler();

            Constante* tmp1=&(ps->Depiler());
            Constante* tmp2=&(ps->Depiler());
            Constante* c;
            c = &(tmp2->operator -(tmp1));

            ps->Empiler(c);
            pa->Empiler(c->GetQString());
        }
        catch(ExceptionCalculatrice e){e.GetInfos();}

        g->AjouterMemento(ps->CreerMemento());
        g->AjouterMemento(pa->CreerMemento());
    }
    //pa->AffichagePile();
    //ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::MultPress()
{
    if(pa->GetPtr().size()<2)
    {
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        e.GetInfos();
    }
    else
    {
        try
        {
            pa->Depiler(); pa->Depiler();

            Constante* tmp1=&(ps->Depiler());
            Constante* tmp2=&(ps->Depiler());
            Constante* c;
            c = &(tmp2->operator*(tmp1));

            ps->Empiler(c);
            pa->Empiler(c->GetQString());
        }
        catch(ExceptionCalculatrice e){e.GetInfos();}

        g->AjouterMemento(ps->CreerMemento());
        g->AjouterMemento(pa->CreerMemento());
    }
    pa->AffichagePile();
    ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}
