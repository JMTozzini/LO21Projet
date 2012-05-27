#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    /*
    std::deque<int> ptr;
    std::cout<< ptr.back()<<std::endl;
    try
    {
        ps->Depiler();
        ps->Depiler();
    }
    catch(ExceptionCalculatice)
    return 0;
    */

    QApplication a(argc, argv);
    MainWindow::InitParam();
    MainWindow w;
    w.show();

    return a.exec();
}
