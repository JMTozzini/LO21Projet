#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), ps(new PileStockage()), pa(new PileAffichage())
{
    ui->setupUi(this);

    // Configuration Ecrans
    ui->champAff->setFontPointSize(30);
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

    if(complexe) ui->actionMode_Complexe->setChecked(true);
    if(clavier) ui->actionClavier->setChecked(true);
    if(typeDeCste=="entier") ui->actionEntier->setChecked(true);
    else if(typeDeCste=="reel") ui->actionReel->setChecked(true);
    else ui->actionRationnel->setChecked(true);
    if (angle=="degres") ui->actionDegres->setChecked(true);
    else ui->actionRadians->setChecked(true);


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

    // Opérateurs unaires
    QObject::connect(ui->eval,SIGNAL(clicked()),this,SLOT(EvalPress()));

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
                QString* tmp2= new QString(tmp_pile.c_str());

                QRegExp exp("'*'");
                exp.setPatternSyntax(QRegExp::Wildcard);
                if(exp.exactMatch(tmp_pile.c_str())){Expression* c=new Expression(*tmp2); ps->Empiler(c); pa->Empiler(*tmp2);}
                else if(tmp_pile.find('$')){Complexe* c=ToComplexe(*tmp2); ps->Empiler(c); pa->Empiler(*tmp2);}
                else if(tmp_pile.find(',')){Reel* c=ToReel(*tmp2); ps->Empiler(c); pa->Empiler(*tmp2);}
                else if(tmp_pile.find('/')){Rationnel* c=ToRationnel(*tmp2); ps->Empiler(c); pa->Empiler(*tmp2);}
                else {Entier* c=new Entier(*tmp2); ps->Empiler(c); pa->Empiler(*tmp2);}


            }

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

