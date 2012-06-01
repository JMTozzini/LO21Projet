#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow::InitParam();
//    MainWindow w;
//    w.show();

//    return a.exec();

    Complexe c1(new Entier(1), new Rationnel(1, 2));
    Complexe c2(new Rationnel(1,2), new Reel(2.1));
    Complexe c3=c1+c2;
    c3.Afficher();

}
