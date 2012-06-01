#ifndef FONCTIONANNEXE_H
#define FONCTIONANNEXE_H

#include "mainwindow.h"

QString& ToQString(Constante& c);
Reel* ToReel(QString& s);
Rationnel* ToRationnel(QString& s);
Complexe* ToComplexe(QString& s);

#endif // FONCTIONANNEXE_H
