#ifndef FONCTIONANNEXE_H
#define FONCTIONANNEXE_H

#include "mainwindow.h"

/*!
  * \brief Fonction permettant de transformer une chaine de caractères en Réel.
  */
Reel* ToReel(QString& s);
/*!
  * \brief Fonction permettant de transformer une chaine de caractères en Rationnel.
  */
Rationnel* ToRationnel(QString& s);
/*!
  * \brief Fonction permettant de transformer une chaine de caractères en Complexe.
  */
Complexe* ToComplexe(QString& s);
/*!
  * Cette fonction permet l'utilisation de la fonction simplifier de la classe Rationnel.
  * \brief Fonction permettant de calculer le PGCD de deux int.
  * \return int.
  */
int PGCD(int,int);
/*!
  * Cette fonction permet l'utilisation de la fonction factoriel de la Calculatrice.
  * \brief Fonction permettant de calculer la factorielle d'un int.
  * \return int.
  */
int Factorielle(int);

#endif // FONCTIONANNEXE_H
