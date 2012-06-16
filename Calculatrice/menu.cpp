/**
\file menu.cpp
**/



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
    MAJParam();

}

void MainWindow::MenuReel()
{
    ui->actionEntier->setChecked(0);
    ui->actionRationnel->setChecked(0);
    ui->actionReel->setChecked(1);
    typeDeCste="reel";
    MAJParam();

}

void MainWindow::MenuRationnel()
{
    ui->actionReel->setChecked(0);
    ui->actionEntier->setChecked(0);
    ui->actionRationnel->setChecked(1);
    typeDeCste="rationnel";
    MAJParam();

}

void MainWindow::MenuClavier()
{
    clavier=ui->actionClavier->isChecked();
    MAJParam();
    ApplicationMenu();
}

void MainWindow::MenuDegres()
{
    ui->actionRadians->setChecked(0);
    ui->actionDegres->setChecked(1);
    angle="degres";
    MAJParam();

}

void MainWindow::MenuRadians()
{
    ui->actionDegres->setChecked(0);
    ui->actionRadians->setChecked(1);
    angle="radians";
    MAJParam();

}
