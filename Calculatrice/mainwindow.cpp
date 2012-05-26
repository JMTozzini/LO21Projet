#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <map>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), ps(new PileStockage()), pa(new PileAffichage())
{
    ui->setupUi(this);

    ui->champAff->setFontPointSize(30);
    ui->champAff->setAlignment(Qt::AlignCenter);

    // Configuration Menu
    ui->actionMode_Complexe->setCheckable(true); // par défaut false
    ui->actionReel->setCheckable(true);
    ui->actionEntier->setCheckable(true);
    ui->actionEntier->setChecked(true);
    ui->actionRationnel->setCheckable(true);
    ui->actionClavier->setCheckable(true);
    ui->actionClavier->setChecked(true);
    ui->actionDegres->setCheckable(true);
    ui->actionRadians->setCheckable(true);
    ui->actionClavier->setChecked(true);
    ui->actionDegres->setChecked(true);

    // Utilisation d'un fichier pour sauver les paramètres






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

    // Opérations
    QObject::connect(ui->plus,SIGNAL(clicked()),this,SLOT(PlusPress()));

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

std::string MainWindow::complexe;
std::string MainWindow::typeDeCste;
std::string MainWindow::operateur="rien";
std::string MainWindow::clavier;
std::string MainWindow::angle;



void MainWindow::InitParam(){


    std::ifstream fichier("param.txt", ios::in);  // Ouverture en lecture du fichier de paramètres
    if(fichier)  // l'ouverture fonctionne -> on récupère les valeurs des paramètres
    {
        getline(fichier, complexe);
        getline(fichier, typeDeCste);
        getline(fichier, clavier);
        getline(fichier, angle);

        std::cout<<"if complexe="<<complexe<<std::endl; // test

    }
    else{ // Sinon le fichier n'existait pas, on ouvre en écriture et on l'initialise avec les valeurs pas défaut
        std::ofstream fichier("param.txt", ios::out);

        if(fichier)
        {
            fichier<<"0"<<std::endl;
            complexe="0";
            fichier<<"entier"<<std::endl;
            typeDeCste="entier";
            fichier<<"1"<<std::endl;
            clavier="1";
            fichier<<"degre"<<std::endl;
            angle="degre";
            std::cout<<"else complexe="<<complexe<<std::endl; // test

        }
        else
            cerr << "Erreur à l'ouverture !" << endl;

    }
    fichier.close();
}

void MainWindow::MAJParam(){
    std::ofstream fichier("param1.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

    if(fichier)  // si l'ouverture a réussi
    {
        fichier<<complexe<<std::endl;

        fichier<<typeDeCste<<std::endl;
        fichier<<clavier<<std::endl;
        fichier<<angle<<std::endl;
        std::cout<<"Ok MAJ"<<complexe<<std::endl;

    }
    else  // sinon
        cerr << "Erreur à l'ouverture !" << endl;
}

