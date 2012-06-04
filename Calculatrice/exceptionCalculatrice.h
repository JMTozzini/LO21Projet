#ifndef EXCEPTIONCALCULATRICE_H
#define EXCEPTIONCALCULATRICE_H

#include <QString>
#include <iostream>

class ExceptionCalculatrice
{
    QString infos;

public:
    ExceptionCalculatrice(QString s="") : infos(s){}
    void GetInfos() const {std::cout<<infos.toStdString()<<std::endl;}

};

#endif // EXCEPTIONCALCULATRICE_H
