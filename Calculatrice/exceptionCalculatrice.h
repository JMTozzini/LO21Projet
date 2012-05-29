#ifndef EXCEPTIONCALCULATRICE_H
#define EXCEPTIONCALCULATRICE_H

#include <QString>

class ExceptionCalculatrice
{
    QString infos;

public:
    ExceptionCalculatrice(QString s) : infos(s){}
    void GetInfos() const;
};

#endif // EXCEPTIONCALCULATRICE_H
