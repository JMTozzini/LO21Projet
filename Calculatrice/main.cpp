#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow::InitParam();
    MainWindow w;
    w.show();
    MainWindow::MAJParam();

    return a.exec();
}
