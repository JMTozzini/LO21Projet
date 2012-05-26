#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::EntrerPress()
{
    QString s=ui->champEcr->text();

    pa->Empiler(s);
    pa->AffichagePile();

    AffichageEcran();

    Entier* e=new Entier(s);

    ps->Empiler(*e);
    ps->AffichagePile();

    ui->champEcr->clear();
}

