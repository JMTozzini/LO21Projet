#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>

void MainWindow::EntrerPress()
{
    QString s=ui->champEcr->text();

    try {pa->Empiler(s);}
    catch(ExceptionCalculatrice e){e.GetInfos();}

    AffichageEcran();

    QRegExp exp("'*'");
    exp.setPatternSyntax(QRegExp::Wildcard);

    if(exp.exactMatch(s)){}
    else if(s.contains("$")){ps->Empiler(*(ToComplexe(s)));}
    else if(s.contains(",")){ps->Empiler(*(ToReel(s)));}
    else if(s.contains("/")){ps->Empiler(*(ToRationnel(s)));}
    else if(!(s.contains("$") || s.contains(",") || s.contains("/"))){ps->Empiler(*(new Entier(s)));}
    else if(s=="+")
    {
        pa->Depiler();
        PlusPress();
    }
    /*else if(moins.exactMatch(s))
    {
        pa->Depiler();
        MoinsPress();
    }*/
    else if(s==""){DupPress();}
    else
    {
        pa->Depiler();
        throw ExceptionCalculatrice("Mauvaise saisie");
    }

    ui->champEcr->clear();
}

void MainWindow::AnnulerPress()
{
    std::cout<<"annuler"<<std::endl;
    ps->AffichagePile(); pa->AffichagePile();
    try
    {
        MementoStock *m1= g->AnnulerStock();
        MementoAff *m2=g->AnnulerAff();
        ps->ChargerMemento(m1); pa->ChargerMemento(m2);
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}

    ps->AffichagePile(); pa->AffichagePile();


    AffichageEcran();
}
