/**
\mainpage Documentation de notre projet de LO21

\section Introduction
Ce document a pour but d'expliquer le code de notre projet de l'UV LO21 : une Calculatrice à notation polonaise inversée, implémentée en C++.

**/

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.InitParam();
    w.setWindowIcon(QIcon("iconeCalculatte.png"));
    w.show();

    return a.exec();
}
