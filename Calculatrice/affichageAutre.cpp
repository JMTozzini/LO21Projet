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
        s.push_back('0'); s.push_front('0'); // on entre 2,_ ou _,2 et ça fonctionne
        Reel* r=new Reel(s);
        ps->Empiler(*r);
    }

    /*
    else if(s=="+") // Je comprend pas à quoi ça sert ?
    {
        pa->Depiler();
        PlusPress();
    }
    else if(s=="-") // Je comprend pas à quoi ça sert ?
    {
        pa->Depiler();
        MoinsPress();
    }

    s ne peut jamais être égal à + ou - car lorsqu'on appuie sur une opération, on l'execute directement on ne l'affiche pas
    */

    else
    {
        Entier* e=new Entier(s);
        ps->Empiler(*e);

    }
    ui->champEcr->clear();
}

