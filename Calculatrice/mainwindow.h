#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "pile.h"
#include "constante.h"

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void AffichageEcran();
    
private:
    Ui::MainWindow *ui;
    PileStockage* ps;
    PileAffichage* pa;

public slots:
    void Num1Press();
    void Num2Press();
    void Num3Press();
    void Num4Press();
    void Num5Press();
    void Num6Press();
    void Num7Press();
    void Num8Press();
    void Num9Press();
    void Num0Press();
    void ComaPress();
    void CmplxPress();
    void ExprPress();
    void PlusPress();
    void EntrerPress();
};

#endif // MAINWINDOW_H
