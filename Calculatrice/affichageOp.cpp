#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::PlusPress()
{
    pa->Depiler(); pa->Depiler();

    Entier* tmp1 = dynamic_cast<Entier*>(ps->Depiler());
    Entier* tmp2 = dynamic_cast<Entier*>(ps->Depiler());
    Entier* res=*tmp1+*tmp2;

    ps->Empiler(*res);
    pa->Empiler(QString::number(res->GetVal()));

    pa->AffichagePile(); ps->AffichagePile();

    ui->champAff->clear();
    ui->champEcr->clear();

    AffichageEcran();
}
