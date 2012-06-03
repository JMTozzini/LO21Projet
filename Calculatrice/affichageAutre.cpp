#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>

void MainWindow::EntrerPress()
{
    QString s=ui->champEcr->text();

    try {pa->Empiler(s);}
    catch(ExceptionCalculatrice e){e.GetInfos();}

    QRegExp exp("'*'");
    exp.setPatternSyntax(QRegExp::Wildcard);

    if(exp.exactMatch(s)){ps->Empiler(*(new Expression(s)));}
    else if(s.contains("$")){ps->Empiler(*(ToComplexe(s)));}
    else if(s.contains(",")){ps->Empiler(*(ToReel(s)));}
    else if(s.contains("/")){ps->Empiler(*(ToRationnel(s)));}
    else if(s=="+"){pa->Depiler(); PlusPress();}
    /*else if(moins.exactMatch(s))
    {
        pa->Depiler();
        MoinsPress();
    }*/
    //else if(s==""){DupPress();}
    else {ps->Empiler(*(new Entier(s)));}
    /*else
    {
        pa->Depiler();
        ExceptionCalculatrice e("Mauvaise saisie");
        e.GetInfos();
    }*/

    ui->champEcr->clear();
    AffichageEcran();
}

void MainWindow::AnnulerPress()
{
    try
    {
        MementoStock *m1= g->AnnulerStock();
        MementoAff *m2=g->AnnulerAff();
        ps->ChargerMemento(m1); pa->ChargerMemento(m2);
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}

    AffichageEcran();
}
