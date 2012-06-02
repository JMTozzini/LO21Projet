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
    else
    {
        pa->Depiler();
        throw ExceptionCalculatrice("Mauvaise saisie");
    }

    ui->champEcr->clear();
}

