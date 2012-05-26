#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::MenuComplexe()
{
    complexe=ui->actionMode_Complexe->isChecked();
}


void MainWindow::MenuEntier()
{
    ui->actionReel->setChecked(0);
    ui->actionRationnel->setChecked(0);
    ui->actionEntier->setChecked(1);
    typeDeCste="entier";
}

void MainWindow::MenuReel()
{
    ui->actionEntier->setChecked(0);
    ui->actionRationnel->setChecked(0);
    ui->actionReel->setChecked(1);
    typeDeCste="reel";
}

void MainWindow::MenuRationnel()
{
    ui->actionReel->setChecked(0);
    ui->actionEntier->setChecked(0);
    ui->actionRationnel->setChecked(1);
    typeDeCste="rationnel";
}
