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
    else if(s=="+"){arret=1; PlusPress();}
    else if(s=="-"){arret=1; MoinsPress();}
    else if(s=="*"){arret=1; MultPress();}
    else if(s=="/"){arret=1; DivPress();}
    else if(s=="cos"){arret=1; CosPress();}
    else if(s=="sin"){arret=1; SinPress();}
    else if(s=="tan"){arret=1; TanPress();}
    else if(s=="cosh"){arret=1; CoshPress();}
    else if(s=="sinh"){arret=1; SinhPress();}
    else if(s=="tanh"){arret=1; TanhPress();}
    else if(s=="pow"){arret=1; PowPress();}
    else if(s==NULL){DupPress();}
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
    else if(s.contains("/")){ps->Empiler(ToRationnel(s)); s=ToRationnel(s)->GetQString();}
    else {ps->Empiler(new Entier(s));}
    /*else
    {
        pa->Depiler();
        ExceptionCalculatrice e("Mauvaise saisie");
        e.GetInfos();
    }*/
    if(!arret){
        try
        {
                pa->Empiler(s);
                g->AjouterMemento(pa->CreerMemento());
                g->AjouterMemento(ps->CreerMemento());
        }
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

        ps->ChargerMemento(m1);
        pa->ChargerMemento(m2);
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}

    AffichageEcran();
    MAJParam();
}

void MainWindow::RetablirPress()
{
    try
    {
        MementoStock *m1= g->RetablirStock();
        MementoAff *m2=g->RetablirAff();

        ps->ChargerMemento(m1);
        pa->ChargerMemento(m2);
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}

    AffichageEcran();
    MAJParam();
}
