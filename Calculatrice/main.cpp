#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QRegExp>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow::InitParam();
    MainWindow w;
    w.show();

    return a.exec();
}
