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

//        g->AjouterMemento(ps->CreerMemento());
//        g->AjouterMemento(pa->CreerMemento());
    }
    pa->AffichagePile();
    ps->AffichagePile();

    ui->champAff->clear();
    ui->champEcr->clear();
    AffichageEcran();
}


void MainWindow::MoinsPress()
{
    /*
    pa->Depiler(); pa->Depiler();
    Entier& tmp1 = dynamic_cast<Entier&>(ps->Depiler());
    Entier& tmp2 = dynamic_cast<Entier&>(ps->Depiler());
    Entier& res = tmp2-tmp1;
    ps->Empiler(res);
    pa->Empiler(QString::number(res.GetVal()));
    pa->AffichagePile();
    ps->AffichagePile();
    ui->champAff->clear();
    ui->champEcr->clear();
    AffichageEcran();
    */
}
