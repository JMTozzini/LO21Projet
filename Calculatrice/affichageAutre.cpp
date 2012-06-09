#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>
#include <string>

void MainWindow::EntrerPress()
{
    QString s=ui->champEcr->text();
    bool arret=0;
    QRegExp exp("'*'");
    exp.setPatternSyntax(QRegExp::Wildcard);

    if(exp.exactMatch(s)){ps->Empiler(new Expression(s));}
    else if(s.startsWith("x=")){
        s.remove(0,2);
        std::cout<<"s="<<s.toStdString()<<std::endl;
        if(s.contains("$")){
            std::cout<<"complexe repéré"<<std::endl;
            if(!complexe){
                arret=1;
                ExceptionCalculatrice e("Le mode complexe n'est pas activé");
                TraitementErreur(e.GetInfos());
            }
            else{
                x=ToComplexe(s);
                ps->Empiler(x);
            }
        }
        else if(s.contains(",")){x=ToReel(s); ps->Empiler(x);}
        else if(s.contains("/")){x=ToRationnel(s); ps->Empiler(x);}
        else {// entier ou expression non reconnue
            bool retour=0;
            int valeur=s.toInt(&retour,10);
            std::cout<<"entier";
            if(retour==0){
                arret=1;
                ExceptionCalculatrice e("Erreur : valeur non reconnue");
                TraitementErreur(e.GetInfos());
            }
            x=new Entier(valeur);
            ps->Empiler(x);
        }
        std::cout<<"x="; x->Afficher();
    }
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
    else if(s==NULL){DupPress();}
    else if(s.contains("$")){
        if(!complexe){
            arret=1;
            ExceptionCalculatrice e("Le mode complexe n'est pas activé");
            TraitementErreur(e.GetInfos());
        }
        else{
            Complexe* c=ToComplexe(s);
            ps->Empiler(c);
        }
    }
    else if(s.contains(",")){ps->Empiler(ToReel(s));}
    else if(s.contains("/")){ps->Empiler(ToRationnel(s));}

    else if(s=="x"){
        ps->Empiler(x);
        pa->Empiler(x->GetQString());
        arret=1;
    }
    else {// entier ou expression non reconnue
        bool retour=0;
        int valeur=s.toInt(&retour,10);
        std::cout<<"entier";
        if(retour==0){
            arret=1;
            ExceptionCalculatrice e("Erreur : valeur non reconnue");
            TraitementErreur(e.GetInfos());
        }
        ps->Empiler(new Entier(valeur));
    }
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
        catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}
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
