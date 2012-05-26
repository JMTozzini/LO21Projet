#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::MenuComplexe()
{
    bool tmp=ui->actionMode_Complexe->isChecked();
    if(tmp)
        complexe="1";
    else
        complexe="0";
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

void MainWindow::MenuClavier()
{
    bool tmp=ui->actionClavier->isChecked();
    if(tmp)
        clavier="1";
    else
        clavier="0";    // A voir comment on change l'interface en fonction du boolean clavier...
}

void MainWindow::MenuDegres()
{
    ui->actionRadians->setChecked(0);
    ui->actionDegres->setChecked(1);
    angle="degres";
}

void MainWindow::MenuRadians()
{
    ui->actionDegres->setChecked(0);
    ui->actionRadians->setChecked(1);
    angle="radians";
}
