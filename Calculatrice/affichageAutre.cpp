#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>

void MainWindow::EntrerPress()
{
    QString s=ui->champEcr->text();
    bool arret=0;

    QRegExp exp("'*'");
    exp.setPatternSyntax(QRegExp::Wildcard);

    if(exp.exactMatch(s)){ps->Empiler(new Expression(s));}
    else if(s=="+"){arret=1; PlusPress();} // Sinon il empile le signe et c'est moche lol
    else if(s=="-"){arret=1; MoinsPress();}
    else if(s=="*"){arret=1; MultPress();}
    else if(s=="/"){arret=1; DivPress();}
    //else if(s==""){DupPress();}
    else if(s.contains("$")){
        if(!complexe){
            arret=1;
            std::cout<<"Le mode complexe n'est pas activé"<<std::endl;
        }
        else{
            Complexe* c=ToComplexe(s);
            ps->Empiler(c);
        }
    }
    else if(s.contains(",")){ps->Empiler(ToReel(s));}
    else if(s.contains("/")){ps->Empiler(ToRationnel(s));}
    else {ps->Empiler(new Entier(s));}
    /*else
    {
        pa->Depiler();
        ExceptionCalculatrice e("Mauvaise saisie");
        e.GetInfos();
    }*/
    if(!arret){
        try {pa->Empiler(s);}
        catch(ExceptionCalculatrice e){e.GetInfos();}
    }

    ui->champEcr->clear();
    AffichageEcran();
    MAJParam();

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
//    MAJParam();

}
