#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

#include "pile.h"
#include "constante.h"
#include "fonctionsAnnexe.h"
#include "exceptionCalculatrice.h"
#include "memento.h"


namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    PileStockage* ps;
    PileAffichage* pa;
    Gardien* g;
    static bool complexe;
    static std::string typeDeCste;
    static bool clavier;
    static std::string operateur;
    static std::string angle;
    //friend class ExceptionCalculatrice;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void AffichageEcran();
    static void InitParam();
    static void MAJParam();

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
    void MoinsPress();
    void EntrerPress();
    void MenuComplexe();
    void MenuEntier();
    void MenuReel();
    void MenuRationnel();
    void MenuClavier();
    void MenuDegres();
    void MenuRadians();
    void AnnulerPress();
    void SwapPress();
    void ClearPress();
    void DupPress();
    void DropPress();
    void SumPress();
    void MeanPress();
};




#endif // MAINWINDOW_H
