#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::EntrerPress()
{
    QString s=ui->champEcr->text();

    try {pa->Empiler(s);}
    catch(ExceptionCalculatrice e){e.GetInfos();}

    AffichageEcran();

    if(s.contains(","))
    {
        s.remove(" ");
        s.replace(s.indexOf(","),1,".");
        s.push_back('0'); s.push_front('0'); // on entre 2,_ ou _,2 et ça fonctionne
        Reel* r=new Reel(s);
        ps->Empiler(*r);
    }

    else if(s=="+")
    {
        pa->Depiler();
        PlusPress();
    }
    else if(s=="-")
    {
        pa->Depiler();
        MoinsPress();
    }

    else
    {
        Entier* e=new Entier(s);
        ps->Empiler(*e);

    }

    ui->champEcr->clear();
}

