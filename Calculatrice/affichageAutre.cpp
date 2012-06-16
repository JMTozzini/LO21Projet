/**
\file affichageAutre.cpp
**/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>
#include <string>

void MainWindow::EntrerPress()
{
    QString s=ui->champEcr->text();
    QString s2=ui->champNbAff->text();

    ui->champErr->clear();

    if(s2!=""){
        bool retour=0;
        int valeur=s2.toInt(&retour,10);
        if(retour==0){
            ExceptionCalculatrice e("Erreur : valeur pour le nombre d'affichage non reconnue");
            TraitementErreur(e.GetInfos());
        }
        else
            nbreAff=valeur;
        ui->champNbAff->clear();
    }

    else{ // Ecriture dans dans champEcr
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
        else if(s=="mod"){arret=1; ModPress();}
        else if(s=="!"){arret=1; FactPress();}
        else if(s=="sign"){arret=1; SignPress();}
        else if(s=="sqr"){arret=1; SignPress();}
        else if(s=="cube"){arret=1; CubePress();}
        else if(s=="sqrt"){arret=1; SqrtPress();}
        else if(s=="inv"){arret=1; InvPress();}
        else if(s=="ln"){arret=1; LnPress();}
        else if(s=="log"){arret=1; LogPress();}
        else if(s=="eval"){arret=1; EvalPress();}
        else if(s==NULL){arret=1; DupPress();}
        else if(s.contains("$")){
            if(!complexe){
                arret=1;
                ExceptionCalculatrice e("Le mode complexe n'est pas actif");
                TraitementErreur(e.GetInfos());
            }
            else{
                Complexe* c=ToComplexe(s);
                ps->Empiler(c);
            }
        }
        else if(s.contains(",")){ps->Empiler(ToReel(s));}
        else if(s.contains("/")){
            Rationnel* a=NULL;
            try{
                a=ToRationnel(s);
                a->Afficher();
                ps->Empiler(a);
                s=a->GetQString();
            }
            catch(ExceptionCalculatrice e){arret=1; TraitementErreur(e.GetInfos());}
        }
        else if(s=="x" && x!=NULL){
            ps->Empiler(x);
            pa->Empiler(x->GetQString());
            arret=1;
        }
        else {// entier ou expression non reconnue
            bool retour=0;
            int valeur=s.toInt(&retour,10);
            if(retour==0){
                arret=1;
                ExceptionCalculatrice e("Erreur : valeur non reconnue");
                TraitementErreur(e.GetInfos());
            }
            else
                ps->Empiler(new Entier(valeur));
        }

        if(!arret){
            try
            {
                pa->Empiler(s);
                g->AjouterMemento(pa->CreerMemento());
                g->AjouterMemento(ps->CreerMemento());
            }
            catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}
        }

        ui->champEcr->clear();

    }
    AffichageEcran();
    MAJParam();

}

void MainWindow::AnnulerPress()
{

    try{
        MementoStock *m1= g->AnnulerStock();
        MementoAff *m2=g->AnnulerAff();
        pa->ChargerMemento(m2);
        pa->ChargerMemento(m2);
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}
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
