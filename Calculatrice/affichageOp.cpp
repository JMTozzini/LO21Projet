#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::PlusPress()
{
    try
    {
        pa->Depiler(); pa->Depiler();
        Constante& c = ((ps->Depiler()) + &(ps->Depiler()));
        ps->Empiler(c);
        pa->Empiler(ToQString(c));
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}

    pa->AffichagePile(); ps->AffichagePile();
    //ReelToQString(c);

    //pa->Empiler();


    //pa->AffichagePile(); ps->AffichagePile();

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
