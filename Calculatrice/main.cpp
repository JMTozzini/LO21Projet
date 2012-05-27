#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    /*
    Reel* r=new Reel(2.50);
    Entier * e=new Entier(2);
    QString s("02.50");
    Reel* r2=new Reel(s);

    r2->Afficher();

    PileStockage* ps=new PileStockage();

    ps->Empiler(*e);
    ps->Empiler(*r);

    ps->AffichagePile();

    //Constante& c1 = (ps->Depiler());
    //Constante* c2 = &(ps->Depiler());

    Constante& c3 = ((ps->Depiler()) + &(ps->Depiler()));

    ps->Empiler(c3);

    ps->AffichagePile();

    return 0;
    */


    QApplication a(argc, argv);
    MainWindow::InitParam();
    MainWindow w;
    w.show();

    return a.exec();

}
