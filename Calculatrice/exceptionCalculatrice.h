#ifndef EXCEPTIONCALCULATRICE_H
#define EXCEPTIONCALCULATRICE_H

#include <QString>
#include <QWidget>
#include <iostream>

class ExceptionCalculatrice
{
    QString infos;

public:
    ExceptionCalculatrice(QString s="") : infos(s){}
    QString GetInfos() const{return infos;}
};

#endif // EXCEPTIONCALCULATRICE_H
