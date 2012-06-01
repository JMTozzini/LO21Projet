#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>

void MainWindow::EntrerPress()
{
    QString s=ui->champEcr->text();

    try {pa->Empiler(s);}
    catch(ExceptionCalculatrice e){e.GetInfos();}

    AffichageEcran();

    QRegExp r("*,*"),plus("*+*"),moins("*-*"), exp("'*'"),ra("*/*"),cmplx("*$*");
    r.setPatternSyntax(QRegExp::Wildcard);
    plus.setPatternSyntax(QRegExp::Wildcard);
    moins.setPatternSyntax(QRegExp::Wildcard);
    exp.setPatternSyntax(QRegExp::Wildcard);
    ra.setPatternSyntax(QRegExp::Wildcard);
    cmplx.setPatternSyntax(QRegExp::Wildcard);

    if(exp.exactMatch(s)){}
    else if(cmplx.exactMatch(s)){
        s.remove(" ");
        Complexe* c=ToComplexe(s);
        ps->Empiler(*c);
    }
    else if(r.exactMatch(s))
    {
        s.remove(" ");
        s.replace(s.indexOf(","),1,".");
        s.push_back('0'); s.push_front('0'); // on entre 2,_ ou _,2 et ça fonctionne
        Reel* r=new Reel(s);
        ps->Empiler(*r);
    }
    else if(ra.exactMatch(s))
    {
        s.remove(" ");
        QStringList list1 = s.split("/");
        Rationnel* ra=new Rationnel(list1.value(1).toInt(),list1.value(2).toInt());
        ps->Empiler(*ra);
    }
    else if(plus.exactMatch(s))
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
        Entier* e=new Entier(s);
        ps->Empiler(*e);

    }

    ui->champEcr->clear();
}

