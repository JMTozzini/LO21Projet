#include "exceptionCalculatrice.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "mainwindow.h"
#include "ui_mainwindow.h"

void ExceptionCalculatrice::GetInfos() const
{
    std::cout << infos.toStdString() << std::endl;
    //ui->champAff->append(infos);
}
