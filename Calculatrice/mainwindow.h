/**
\file mainwindow.h
\brief Déclaration de la class MainWindow permettant la création de la fenêtre
**/

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
    bool complexe;
    std::string typeDeCste;
    bool clavier;
    std::string operateur;
    std::string angle;
    int nbreAff;

    //Variable utilisateur
    Constante* x;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /*!
      * \brief Méthode permettant l'affichage de la pile d'affichage sur l'ecran central.
      */
    void AffichageEcran();
    /*!
      * \brief Méthode permettant d'initialiser le contexte sauvegardé précédemment.
      */
    void InitParam();
    /*!
      * \brief Méthode permettant la mise à jour du contexte.
      */
    void MAJParam();
    /*!
      * \brief Méthode permettant d'appliquer les informations du menu.
      */
    void ApplicationMenu();
    /*!
      * \brief Méthode permettant d'afficher les erreurs sur l'écran d'erreur.
      */
    void TraitementErreur(QString);

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
    void DelPress();
    void ComaPress();
    void CmplxPress();
    void ExprPress();
    void DivPress();
    void ModPress();
    void PlusPress();
    void MoinsPress();
    void MultPress();
    void FactPress();
    void SignPress();
    void SqrPress();
    void CubePress();
    void SqrtPress();
    void InvPress();
    void LnPress();
    void LogPress();
    void EntrerPress();
    void MenuComplexe();
    void MenuEntier();
    void MenuReel();
    void MenuRationnel();
    void MenuClavier();
    void MenuDegres();
    void MenuRadians();
    void AnnulerPress();
    void RetablirPress();
    void SwapPress();
    void ClearPress();
    void DupPress();
    void DropPress();
    void SumPress();
    void MeanPress();
    void EvalPress();
    void CosPress();
    void SinPress();
    void TanPress();
    void CoshPress();
    void SinhPress();
    void TanhPress();
    void PowPress();
    void xPress();
    void xEgalPress();
};

#endif // MAINWINDOW_H
