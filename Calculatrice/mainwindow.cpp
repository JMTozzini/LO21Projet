#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow),
    ps(new PileStockage()), pa(new PileAffichage()), g(new Gardien())
{
    ui->setupUi(this);

    // Configuration Ecrans
    ui->champAff->setFontPointSize(17);
    ui->champAff->setAlignment(Qt::AlignCenter);
    ui->champAff->setReadOnly(true);

    // Configuration Menu
    ui->actionMode_Complexe->setCheckable(true); // par défaut false
    ui->actionReel->setCheckable(true);
    ui->actionEntier->setCheckable(true);
    ui->actionRationnel->setCheckable(true);
    ui->actionClavier->setCheckable(true);
    ui->actionDegres->setCheckable(true);
    ui->actionRadians->setCheckable(true);

    // Numéro
    QObject::connect(ui->un,SIGNAL(clicked()),this,SLOT(Num1Press()));
    QObject::connect(ui->deux,SIGNAL(clicked()),this,SLOT(Num2Press()));
    QObject::connect(ui->trois,SIGNAL(clicked()),this,SLOT(Num3Press()));
    QObject::connect(ui->quatre,SIGNAL(clicked()),this,SLOT(Num4Press()));
    QObject::connect(ui->cinq,SIGNAL(clicked()),this,SLOT(Num5Press()));
    QObject::connect(ui->six,SIGNAL(clicked()),this,SLOT(Num6Press()));
    QObject::connect(ui->sept,SIGNAL(clicked()),this,SLOT(Num7Press()));
    QObject::connect(ui->huit,SIGNAL(clicked()),this,SLOT(Num8Press()));
    QObject::connect(ui->neuf,SIGNAL(clicked()),this,SLOT(Num9Press()));
    QObject::connect(ui->zero,SIGNAL(clicked()),this,SLOT(Num0Press()));

    //Connection des types
    QObject::connect(ui->coma,SIGNAL(clicked()),this,SLOT(ComaPress()));
    QObject::connect(ui->expr,SIGNAL(clicked()),this,SLOT(ExprPress()));
    QObject::connect(ui->cmplx,SIGNAL(clicked()),this,SLOT(CmplxPress()));

    // Opérateurs binaire
    QObject::connect(ui->plus,SIGNAL(clicked()),this,SLOT(PlusPress()));
    QObject::connect(ui->moins,SIGNAL(clicked()),this,SLOT(MoinsPress()));
    QObject::connect(ui->multi,SIGNAL(clicked()),this,SLOT(MultPress()));
    QObject::connect(ui->div,SIGNAL(clicked()),this,SLOT(DivPress()));

    // Opérateurs unaires
    QObject::connect(ui->sin,SIGNAL(clicked()),this,SLOT(SinPress()));
    QObject::connect(ui->cos,SIGNAL(clicked()),this,SLOT(CosPress()));
    QObject::connect(ui->tan,SIGNAL(clicked()),this,SLOT(TanPress()));


    // Entrer
    QObject::connect(ui->entrer,SIGNAL(clicked()),this,SLOT(EntrerPress()));

    // Menu
    QObject::connect(ui->actionMode_Complexe,SIGNAL(triggered()),this,SLOT(MenuComplexe()));
    QObject::connect(ui->actionEntier,SIGNAL(triggered()),this,SLOT(MenuEntier()));
    QObject::connect(ui->actionReel,SIGNAL(triggered()),this,SLOT(MenuReel()));
    QObject::connect(ui->actionRationnel,SIGNAL(triggered()),this,SLOT(MenuRationnel()));
    QObject::connect(ui->actionClavier,SIGNAL(triggered()),this,SLOT(MenuClavier()));
    QObject::connect(ui->actionDegres,SIGNAL(triggered()),this,SLOT(MenuDegres()));
    QObject::connect(ui->actionRadians,SIGNAL(triggered()),this,SLOT(MenuRadians()));



    // Annuler & Rétablir
    QObject::connect(ui->actionAnnuler, SIGNAL(triggered()),this,SLOT(AnnulerPress()));

    // Opération sur Pile
    QObject::connect(ui->swap, SIGNAL(clicked()), this, SLOT(SwapPress()));
    QObject::connect(ui->clear, SIGNAL(clicked()), this, SLOT(ClearPress()));
    QObject::connect(ui->dup, SIGNAL(clicked()), this, SLOT(DupPress()));
    QObject::connect(ui->drop, SIGNAL(clicked()), this, SLOT(DropPress()));
    QObject::connect(ui->sum,SIGNAL(clicked()), this, SLOT(SumPress()));
    QObject::connect(ui->mean,SIGNAL(clicked()), this, SLOT(MeanPress()));
    QObject::connect(ui->eval,SIGNAL(clicked()),this,SLOT(EvalPress()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AffichageEcran()
{
    ui->champAff->clear();

    std::deque<QString> ptr=pa->GetPtr();

    for(unsigned int i=0;i<ptr.size();i++)
        ui->champAff->append(pa->GetVal(i));
}




// Fonctions pour l'initialisation et la mise à jour des paramètres

void MainWindow::InitParam(){


    std::ifstream fichier("param.txt", ios::in);  // Ouverture en lecture du fichier de paramètres
    if(fichier)  // l'ouverture fonctionne -> on récupère les valeurs des paramètres
    {
        string tmp, tmp_pile;
        getline(fichier, tmp);
        complexe=atoi(tmp.c_str());
        getline(fichier, typeDeCste);
        getline(fichier, tmp);
        clavier=atoi(tmp.c_str());
        getline(fichier, angle);
        getline(fichier, tmp_pile); // lit "pile" ou "pile vide"
        if(tmp_pile!="pile vide"){
            while(getline(fichier, tmp_pile)){
                std::cout<<"recup val="<<tmp_pile<<"   ";
                QString* tmp2= new QString(tmp_pile.c_str());
                QRegExp exp("'*'");
                exp.setPatternSyntax(QRegExp::Wildcard);
                if(exp.exactMatch(tmp_pile.c_str())){Expression* c=new Expression(*tmp2); ps->Empiler(c); pa->Empiler(*tmp2);std::cout<<"expr"<<std::endl;}
                else if(tmp2->contains('$')){Complexe* c=ToComplexe(*tmp2); ps->Empiler(c); pa->Empiler(*tmp2);std::cout<<"cmplx"<<std::endl;}
                else if(tmp2->contains('.') || tmp2->contains(',')){Reel* c=ToReel(*tmp2); ps->Empiler(c); pa->Empiler(*tmp2);std::cout<<"reel"<<std::endl;}
                else if(tmp2->contains('/')){Rationnel* c=ToRationnel(*tmp2); ps->Empiler(c); pa->Empiler(*tmp2);std::cout<<"rationnel"<<std::endl;}
                else {Entier* c=new Entier(*tmp2); ps->Empiler(c); pa->Empiler(*tmp2);std::cout<<"entier"<<std::endl;}

            }

            ApplicationMenu();

            AffichageEcran();

        }
    }
    else{ // Sinon le fichier n'existait pas, on ouvre en écriture et on l'initialise avec les valeurs pas défaut
        std::ofstream fichier("param.txt", ios::out);

        if(fichier)
        {
            fichier<<0<<std::endl;
            complexe=0;
            fichier<<"entier"<<std::endl;
            typeDeCste="entier";
            fichier<<1<<std::endl;
            clavier=1;
            fichier<<"degres"<<std::endl;
            angle="degres";
            fichier<<"pile vide"<<std::endl;
        }
        else
            cerr << "Erreur à l'ouverture !" << endl;

    }
    fichier.close();
}

void MainWindow::MAJParam(){
    std::ofstream fichier("param.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

    if(fichier)  // si l'ouverture a réussi
    {
        fichier<<complexe<<std::endl;
        fichier<<typeDeCste<<std::endl;
        fichier<<clavier<<std::endl;
        fichier<<angle<<std::endl;
        fichier<<"pile"<<std::endl;
        pa->Save(fichier);
        fichier.close();
    }
    else  // sinon
        cerr << "Erreur à l'ouverture !" << endl;
}


void MainWindow::ApplicationMenu(){
    if(complexe) ui->actionMode_Complexe->setChecked(true);
    if(clavier) ui->actionClavier->setChecked(true);
    if(typeDeCste=="entier") ui->actionEntier->setChecked(true);
    else if(typeDeCste=="reel") ui->actionReel->setChecked(true);
    else ui->actionRationnel->setChecked(true);
    if (angle=="degres") ui->actionDegres->setChecked(true);
    else ui->actionRadians->setChecked(true);

    if(!clavier){
        ui->un->setVisible(false);
        ui->deux->setVisible(false);
        ui->trois->setVisible(false);
        ui->quatre->setVisible(false);
        ui->cinq->setVisible(false);
        ui->six->setVisible(false);
        ui->sept->setVisible(false);
        ui->huit->setVisible(false);
        ui->neuf->setVisible(false);
        ui->zero->setVisible(false);
        ui->coma->setVisible(false);
        ui->expr->setVisible(false);
        ui->cmplx->setVisible(false);
        ui->plus->setVisible(false);
        ui->moins->setVisible(false);
        ui->div->setVisible(false);
        ui->eval->setVisible(false);
        ui->entrer->setVisible(false);
        ui->del->setVisible(false);
        ui->opBinaires->setVisible(false);
        ui->opPile->setVisible(false);
        ui->opUnaires->setVisible(false);
        ui->sin->setVisible(false);
        ui->cos->setVisible(false);
        ui->tan->setVisible(false);
        ui->sinh->setVisible(false);
        ui->cosh->setVisible(false);
        ui->tanh->setVisible(false);
        ui->ln->setVisible(false);
        ui->log->setVisible(false);
        ui->inv->setVisible(false);
        ui->sqrt->setVisible(false);
        ui->sqr->setVisible(false);
        ui->cube->setVisible(false);
        ui->fact->setVisible(false);
        ui->sign->setVisible(false);
        ui->swap->setVisible(false);
        ui->sum->setVisible(false);
        ui->mean->setVisible(false);
        ui->clear->setVisible(false);
        ui->dup->setVisible(false);
        ui->drop->setVisible(false);
        ui->multi->setVisible(false);
        ui->pow->setVisible(false);
        ui->mod->setVisible(false);
    }

   else{
            ui->un->setVisible(true);
            ui->deux->setVisible(true);
            ui->trois->setVisible(true);
            ui->quatre->setVisible(true);
            ui->cinq->setVisible(true);
            ui->six->setVisible(true);
            ui->sept->setVisible(true);
            ui->huit->setVisible(true);
            ui->neuf->setVisible(true);
            ui->zero->setVisible(true);
            ui->coma->setVisible(true);
            ui->expr->setVisible(true);
            ui->cmplx->setVisible(true);
            ui->plus->setVisible(true);
            ui->moins->setVisible(true);
            ui->div->setVisible(true);
            ui->eval->setVisible(true);
            ui->entrer->setVisible(true);
            ui->del->setVisible(true);
            ui->opBinaires->setVisible(true);
            ui->opPile->setVisible(true);
            ui->opUnaires->setVisible(true);
            ui->sin->setVisible(true);
            ui->cos->setVisible(true);
            ui->tan->setVisible(true);
            ui->sinh->setVisible(true);
            ui->cosh->setVisible(true);
            ui->tanh->setVisible(true);
            ui->ln->setVisible(true);
            ui->log->setVisible(true);
            ui->inv->setVisible(true);
            ui->sqrt->setVisible(true);
            ui->sqr->setVisible(true);
            ui->cube->setVisible(true);
            ui->fact->setVisible(true);
            ui->sign->setVisible(true);
            ui->swap->setVisible(true);
            ui->sum->setVisible(true);
            ui->mean->setVisible(true);
            ui->clear->setVisible(true);
            ui->dup->setVisible(true);
            ui->drop->setVisible(true);
            ui->multi->setVisible(true);
            ui->pow->setVisible(true);
            ui->mod->setVisible(true);
    }
}
