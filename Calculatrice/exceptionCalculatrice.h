#ifndef EXCEPTIONCALCULATRICE_H
#define EXCEPTIONCALCULATRICE_H

#include <QString>

/*!
  * \class ExceptionCalculatrice
  * \brief Classe permettant de gérer les exceptions de la calculatrice.
  */
class ExceptionCalculatrice
{
    QString infos;

public:
    ExceptionCalculatrice(QString s="") : infos(s){}
    /*!
      * \brief Fonction permettant de renvoyer le détail de l'exception.
      * \return QString.
      */
    QString GetInfos() const{return infos;}
};

#endif // EXCEPTIONCALCULATRICE_H
