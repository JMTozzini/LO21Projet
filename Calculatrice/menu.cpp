#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::MenuComplexe()
{
    complexe=ui->actionMode_Complexe->isChecked();
    MainWindow::MAJParam();
}


void MainWindow::MenuEntier()
{
    ui->actionReel->setChecked(0);
    ui->actionRationnel->setChecked(0);
    ui->actionEntier->setChecked(1);
    typeDeCste="entier";
    MainWindow::MAJParam();

}

void MainWindow::MenuReel()
{
    ui->actionEntier->setChecked(0);
    ui->actionRationnel->setChecked(0);
    ui->actionReel->setChecked(1);
    typeDeCste="reel";
    MainWindow::MAJParam();

}

void MainWindow::MenuRationnel()
{
    ui->actionReel->setChecked(0);
    ui->actionEntier->setChecked(0);
    ui->actionRationnel->setChecked(1);
    typeDeCste="rationnel";
    MainWindow::MAJParam();

}

void MainWindow::MenuClavier()
{
    clavier=ui->actionClavier->isChecked();
    MainWindow::MAJParam();

    // A voir comment on change l'interface en fonction du boolean clavier...
}

void MainWindow::MenuDegres()
{
    ui->actionRadians->setChecked(0);
    ui->actionDegres->setChecked(1);
    angle="degres";
    MainWindow::MAJParam();

}

void MainWindow::MenuRadians()
{
    ui->actionDegres->setChecked(0);
    ui->actionRadians->setChecked(1);
    angle="radians";
    MainWindow::MAJParam();

}
