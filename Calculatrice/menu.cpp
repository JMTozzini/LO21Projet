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
    if(!clavier){
        ui->un->setVisible(false);
        ui->deux->setVisible(false);
        ui->trois->setVisible(false);
        ui->quatre->setVisible(false);
        ui->cinq->setVisible(false);
        ui->six->setVisible(false);
        ui->sept->setVisible(false);
        ui->huit->setVisible(false);
        ui->neuf->setVisible(false);
        ui->zero->setVisible(false);
        ui->coma->setVisible(false);
        ui->expr->setVisible(false);
        ui->cmplx->setVisible(false);
        ui->plus->setVisible(false);
        ui->moins->setVisible(false);
        ui->div->setVisible(false);
        ui->eval->setVisible(false);
        ui->entrer->setVisible(false);
        ui->del->setVisible(false);
        ui->opBinaires->setVisible(false);
        ui->opPile->setVisible(false);
        ui->opUnaires->setVisible(false);
        ui->sin->setVisible(false);
        ui->cos->setVisible(false);
        ui->tan->setVisible(false);
        ui->sinh->setVisible(false);
        ui->cosh->setVisible(false);
        ui->tanh->setVisible(false);
        ui->ln->setVisible(false);
        ui->log->setVisible(false);
        ui->inv->setVisible(false);
        ui->sqrt->setVisible(false);
        ui->sqr->setVisible(false);
        ui->cube->setVisible(false);
        ui->fact->setVisible(false);
        ui->sign->setVisible(false);
        ui->swap->setVisible(false);
        ui->sum->setVisible(false);
        ui->mean->setVisible(false);
        ui->clear->setVisible(false);
        ui->dup->setVisible(false);
        ui->drop->setVisible(false);
        ui->multi->setVisible(false);
        ui->pow->setVisible(false);
        ui->mod->setVisible(false);
}
    else{
        ui->un->setVisible(true);
        ui->deux->setVisible(true);
        ui->trois->setVisible(true);
        ui->quatre->setVisible(true);
        ui->cinq->setVisible(true);
        ui->six->setVisible(true);
        ui->sept->setVisible(true);
        ui->huit->setVisible(true);
        ui->neuf->setVisible(true);
        ui->zero->setVisible(true);
        ui->coma->setVisible(true);
        ui->expr->setVisible(true);
        ui->cmplx->setVisible(true);
        ui->plus->setVisible(true);
        ui->moins->setVisible(true);
        ui->div->setVisible(true);
        ui->eval->setVisible(true);
        ui->entrer->setVisible(true);
        ui->del->setVisible(true);
        ui->opBinaires->setVisible(true);
        ui->opPile->setVisible(true);
        ui->opUnaires->setVisible(true);
        ui->sin->setVisible(true);
        ui->cos->setVisible(true);
        ui->tan->setVisible(true);
        ui->sinh->setVisible(true);
        ui->cosh->setVisible(true);
        ui->tanh->setVisible(true);
        ui->ln->setVisible(true);
        ui->log->setVisible(true);
        ui->inv->setVisible(true);
        ui->sqrt->setVisible(true);
        ui->sqr->setVisible(true);
        ui->cube->setVisible(true);
        ui->fact->setVisible(true);
        ui->sign->setVisible(true);
        ui->swap->setVisible(true);
        ui->sum->setVisible(true);
        ui->mean->setVisible(true);
        ui->clear->setVisible(true);
        ui->dup->setVisible(true);
        ui->drop->setVisible(true);
        ui->multi->setVisible(true);
        ui->pow->setVisible(true);
        ui->mod->setVisible(true);
}
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
