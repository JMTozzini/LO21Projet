#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::PlusPress()
{
    if(pa->GetPtr().size()<2)
    {
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        TraitementErreur(e.GetInfos());
    }
    else
    {
        try
        {
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
    }
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}


void MainWindow::MoinsPress()
{
    if(pa->GetPtr().size()<2)
    {
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        TraitementErreur(e.GetInfos());
    }
    else
    {
        try
        {
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
    }
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::MultPress()
{
    if(pa->GetPtr().size()<2)
    {
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        TraitementErreur(e.GetInfos());
    }
    else
    {
        try
        {
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
    }
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}

void MainWindow::DivPress()
{
    if(pa->GetPtr().size()<2)
    {
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        TraitementErreur(e.GetInfos());
    }
    else
    {
        try
        {
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
    }
    //pa->AffichagePile(); ps->AffichagePile();

    ui->champEcr->clear();
    MAJParam();

    AffichageEcran();
}


void MainWindow::CosPress(){
    if(pa->GetPtr().size()<1){
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        TraitementErreur(e.GetInfos());
    }
    else{
        try{
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
    }
    ui->champEcr->clear();
    MAJParam();
    AffichageEcran();
}

void MainWindow::SinPress(){
    if(pa->GetPtr().size()<1){
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        TraitementErreur(e.GetInfos());
    }
    else{
        try{
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
    }
    ui->champEcr->clear();
    MAJParam();
    AffichageEcran();
}

void MainWindow::TanPress(){
    if(pa->GetPtr().size()<1){
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        TraitementErreur(e.GetInfos());
    }
    else{
        try{
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
    }
    ui->champEcr->clear();
    MAJParam();
    AffichageEcran();
}


void MainWindow::CoshPress(){
    if(pa->GetPtr().size()<1){
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        TraitementErreur(e.GetInfos());
    }
    else{
        try{
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
    }
    ui->champEcr->clear();
    MAJParam();
    AffichageEcran();
}

void MainWindow::SinhPress(){
    if(pa->GetPtr().size()<1){
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        TraitementErreur(e.GetInfos());
    }
    else{
        try{
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
    }
    ui->champEcr->clear();
    MAJParam();
    AffichageEcran();
}

void MainWindow::TanhPress(){
    if(pa->GetPtr().size()<1){
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        TraitementErreur(e.GetInfos());
    }
    else{
        try{
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
    }
    ui->champEcr->clear();
    MAJParam();
    AffichageEcran();
}


void MainWindow::PowPress()
{
    int stop=0;
    if(pa->GetPtr().size()<2){
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        TraitementErreur(e.GetInfos());
    }
    else{
        try{
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
            // La suite n'est pas exécutée si il y a eu une exception
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

        if(tmp1->GetType()!="entier" || tmp2->GetType()!="entier")
        {
            pa->Empiler(s2); pa->Empiler(s1);
            ps->Empiler(tmp2); ps->Empiler(tmp1);
            throw ExceptionCalculatrice("Modulo impossible, argument(s) non entier(s)");
        }

        Constante* c = &(tmp2->operator%(tmp1));
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
