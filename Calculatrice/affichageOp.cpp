#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::PlusPress()
{
    if(pa->GetPtr().size()<2)
    {
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        e.GetInfos();
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
        e.GetInfos();
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
        catch(ExceptionCalculatrice e){e.GetInfos();}

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
        e.GetInfos();
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
        catch(ExceptionCalculatrice e){e.GetInfos();}

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
        e.GetInfos();
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
        e.GetInfos();
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
        e.GetInfos();
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
        e.GetInfos();
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
        e.GetInfos();
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
        e.GetInfos();
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
        e.GetInfos();
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
    if(pa->GetPtr().size()<2){
        ExceptionCalculatrice e("Pas assez d'operandes dans la pile");
        e.GetInfos();
    }
    else{
        try{
            QString a=pa->Depiler(), b=pa->Depiler();
            Constante* tmp1=&(ps->Depiler());
            Constante* tmp2=&(ps->Depiler());
            if(tmp1->GetType()=="complexe" || tmp2->GetType()=="complexe"){
                pa->Empiler(b); pa->Empiler(a);
                ps->Empiler(tmp2); ps->Empiler(tmp1);
                throw ExceptionCalculatrice("Erreur d'operation : pow impossible avec un complexe");
            }
            else{
                Constante* c;
                c = &(tmp2->powFonction(tmp1));
                if(c->GetType()=="rationnel")
                    c->Simplifier();
                ps->Empiler(c);
                pa->Empiler(c->GetQString());
            }
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
