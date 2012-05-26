#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::EntrerPress()
{
    QString s=ui->champEcr->text();


    pa->Empiler(s);
    AffichageEcran();

    if(s.contains(","))
    {
        s.remove(" ");
        s.replace(s.indexOf(","),1,".");
        Reel* r=new Reel(s);
        ps->Empiler(*r);
        ps->AffichagePile();
    }

    else
    {
        Entier* e=new Entier(s);
        ps->Empiler(*e);
    }
    ui->champEcr->clear();
}

