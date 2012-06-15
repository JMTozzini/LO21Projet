#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::PlusPress()
{
    try
    {
        if(pa->GetPtr().size()<2)
        {
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");
        }
        pa->Depiler(); pa->Depiler();
        Constante* tmp1=&(ps->Depiler());
        Constante* tmp2=&(ps->Depiler());
        Constante* c;
        c = &(tmp2->operator +(tmp1));
        if(c->GetType()=="rationnel")
            c->Simplifier();
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());

    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}


void MainWindow::MoinsPress()
{
    try
    {
        if(pa->GetPtr().size()<2)
        {
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");
        }
        pa->Depiler(); pa->Depiler();

        Constante* tmp1=&(ps->Depiler());
        Constante* tmp2=&(ps->Depiler());
        Constante* c;
        c = &(tmp2->operator -(tmp1));

        if(c->GetType()=="rationnel")
            c->Simplifier();

        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());

    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::MultPress()
{
    try
    {
        if(pa->GetPtr().size()<2)
        {
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");
        }
        pa->Depiler(); pa->Depiler();

        Constante* tmp1=&(ps->Depiler());
        Constante* tmp2=&(ps->Depiler());
        Constante* c;
        c = &(tmp2->operator*(tmp1));

        if(c->GetType()=="rationnel")
            c->Simplifier();

        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());

    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::DivPress()
{
    try
    {
        if(pa->GetPtr().size()<2)
        {
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");
        }

        pa->Depiler(); pa->Depiler();

        Constante* tmp1=&(ps->Depiler());
        Constante* tmp2=&(ps->Depiler());
        Constante* c;
        c = &(tmp2->operator/(tmp1));

        if(c->GetType()=="rationnel")
            c->Simplifier();

        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());

    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}


void MainWindow::CosPress(){

    try{
        if(pa->GetPtr().size()<1)
        {
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");
        }
        pa->Depiler();
        Constante* tmp1=&(ps->Depiler());
        Constante* c;
        c = &(tmp1->cosFonction(angle));
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}
    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());

    ui->champEcr->clear();
    MAJParam();
    AffichageEcran();
}

void MainWindow::SinPress(){

    try{
        if(pa->GetPtr().size()<1)
        {
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");
        }
        pa->Depiler();
        Constante* tmp1=&(ps->Depiler());
        Constante* c;
        c = &(tmp1->sinFonction(angle));
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}
    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());

    ui->champEcr->clear();
    MAJParam();
    AffichageEcran();
}

void MainWindow::TanPress(){
    try{
        if(pa->GetPtr().size()<1)
        {
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");
        }
        pa->Depiler();
        Constante* tmp1=&(ps->Depiler());
        Constante* c;
        c = &(tmp1->tanFonction(angle));
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}
    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());

    ui->champEcr->clear();
    MAJParam();
    AffichageEcran();
}


void MainWindow::CoshPress(){
    try{
        if(pa->GetPtr().size()<1)
        {
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");
        }
        pa->Depiler();
        Constante* tmp1=&(ps->Depiler());
        Constante* c;
        c = &(tmp1->coshFonction(angle));
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}
    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());

    ui->champEcr->clear();
    MAJParam();
    AffichageEcran();
}

void MainWindow::SinhPress(){
    try{
        if(pa->GetPtr().size()<1)
        {
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");
        }
        pa->Depiler();
        Constante* tmp1=&(ps->Depiler());
        Constante* c;
        c = &(tmp1->sinhFonction(angle));
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}
    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());

    ui->champEcr->clear();
    MAJParam();
    AffichageEcran();
}

void MainWindow::TanhPress(){
    try{
        if(pa->GetPtr().size()<1)
        {
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");
        }
        pa->Depiler();
        Constante* tmp1=&(ps->Depiler());
        Constante* c;
        c = &(tmp1->tanhFonction(angle));
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}
    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());

    ui->champEcr->clear();
    MAJParam();
    AffichageEcran();
}


void MainWindow::PowPress()
{
    int stop=0;

    try{
        if(pa->GetPtr().size()<2)
        {
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");
        }
        QString a=pa->Depiler();
        if(a.contains("$")){
            pa->Empiler(a);
            throw ExceptionCalculatrice("Erreur d'operation : pow impossible avec un complexe");
        }
        QString b=pa->Depiler();
        if(b.contains("$")){
            pa->Empiler(a);
            pa->Empiler(b);
            throw ExceptionCalculatrice("Erreur d'operation : pow impossible avec un complexe");
        }
        // La suite n'est pas executee si il y a eu une exception
        Constante* tmp1=&(ps->Depiler());
        Constante* tmp2=&(ps->Depiler());

        Constante* c;
        c = &(tmp2->powFonction(tmp1));
        if(c->GetType()=="rationnel")
            c->Simplifier();
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
        ui->champEcr->clear();
        MAJParam();
        AffichageEcran();
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos()); stop=1;}

    if(!stop){
        g->AjouterMemento(ps->CreerMemento());
        g->AjouterMemento(pa->CreerMemento());
    }
    //    pa->AffichagePile(); ps->AffichagePile();
}


void MainWindow::ModPress()
{
    try
    {
        if(pa->GetPtr().size()<2)
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");

        QString s1=pa->Depiler(); QString s2=pa->Depiler();
        Constante* tmp1=&(ps->Depiler());
        Constante* tmp2=&(ps->Depiler());

        if((tmp1->GetType()!="entier" && tmp1->GetType()!="expression") || (tmp2->GetType()!="entier" && tmp2->GetType()!="expression"))
        {
            pa->Empiler(s2); pa->Empiler(s1);
            ps->Empiler(tmp2); ps->Empiler(tmp1);
            throw ExceptionCalculatrice("Modulo impossible, argument(s) non entier(s) ou expression(s)");
        }

        Constante* c = &(tmp2->operator%(tmp1));
        //std::cout<<c->GetVal()<<std::endl;
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::FactPress()
{
    try
    {
        if(pa->GetPtr().size()<1)
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");

        QString s=pa->Depiler();
        Constante* tmp=&(ps->Depiler());

        if((tmp->GetType()!="entier" && tmp->GetType()!="expression"))
        {
            pa->Empiler(s);
            ps->Empiler(tmp);
            throw ExceptionCalculatrice("Factorielle impossible, argument non entier ou expression");
        }
        else if((tmp->GetType()=="entier") && (tmp->GetVal()>13))
        {
            pa->Empiler(s);
            ps->Empiler(tmp);
            throw ExceptionCalculatrice("Factorielle annulee, resultat aberrant");
        }

        Constante* c = &(tmp->factFonction());
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::SignPress()
{
    try
    {
        if(pa->GetPtr().size()<1)
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");

        QString s=pa->Depiler();
        Constante* tmp=&(ps->Depiler());
        Constante* c = &(tmp->signFonction());
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::SqrPress()
{
    try
    {
        if(pa->GetPtr().size()<1)
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");

        QString s=pa->Depiler();
        Constante* tmp=&(ps->Depiler());
        Constante* c = &(tmp->sqrFonction());
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::CubePress()
{
    try
    {
        if(pa->GetPtr().size()<1)
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");

        QString s=pa->Depiler();
        Constante* tmp=&(ps->Depiler());
        Constante* c = &(tmp->cubeFonction());
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::SqrtPress()
{
    try
    {
        if(pa->GetPtr().size()<1)
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");

        QString s=pa->Depiler();
        Constante* tmp=&(ps->Depiler());

        if(tmp->GetType()=="complexe")
        {
            pa->Empiler(s);
            ps->Empiler(tmp);
            throw ExceptionCalculatrice("Racine Carree impossible, argument complexe");
        }
        else if(tmp->GetVal()<0)
        {
            pa->Empiler(s);
            ps->Empiler(tmp);
            throw ExceptionCalculatrice("Racine Carree impossible, argument negatif");
        }
        Constante* c = &(tmp->sqrtFonction());
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::InvPress()
{
    try
    {
        if(pa->GetPtr().size()<1)
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");

        QString s=pa->Depiler();
        Constante* tmp=&(ps->Depiler());

        if(tmp->GetType()=="complexe")
        {
            pa->Empiler(s);
            ps->Empiler(tmp);
            throw ExceptionCalculatrice("Racine Carre impossible, argument complexe");
        }

        Constante* c = &(tmp->invFonction());
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::LnPress()
{
    try
    {
        if(pa->GetPtr().size()<1)
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");

        QString s=pa->Depiler();
        Constante* tmp=&(ps->Depiler());

        if(tmp->GetType()=="complexe")
        {
            pa->Empiler(s);
            ps->Empiler(tmp);
            throw ExceptionCalculatrice("Ln impossible, argument complexe");
        }
        else if(tmp->GetVal()<0)
        {
            pa->Empiler(s);
            ps->Empiler(tmp);
            throw ExceptionCalculatrice("Ln impossible, argument negatif");
        }
        Constante* c = &(tmp->lnFonction());
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::LogPress()
{
    try
    {
        if(pa->GetPtr().size()<1)
            throw ExceptionCalculatrice("Pas assez d'operandes dans la pile");

        QString s=pa->Depiler();
        Constante* tmp=&(ps->Depiler());

        if(tmp->GetType()=="complexe")
        {
            pa->Empiler(s);
            ps->Empiler(tmp);
            throw ExceptionCalculatrice("Log impossible, argument complexe");
        }
        else if(tmp->GetVal()<0)
        {
            pa->Empiler(s);
            ps->Empiler(tmp);
            throw ExceptionCalculatrice("Log impossible, argument negatif");
        }

        Constante* c = &(tmp->logFonction());
        ps->Empiler(c);
        pa->Empiler(c->GetQString());
    }
    catch(ExceptionCalculatrice e){TraitementErreur(e.GetInfos());}

    g->AjouterMemento(ps->CreerMemento());
    g->AjouterMemento(pa->CreerMemento());
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}
