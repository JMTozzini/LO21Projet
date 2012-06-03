#include "fonctionsAnnexe.h"

Reel* ToReel(QString& s){
    s.remove(" ");
    s.replace(s.indexOf(","),1,".");
    return new Reel(s);
}

Rationnel* ToRationnel(QString& s){
    s.remove(" ");
    QStringList list1 = s.split("/");
    return new Rationnel(list1.value(0).toInt(),list1.value(1).toInt());
}

Complexe* ToComplexe(QString& s)
{
    s.remove(" ");
    QStringList list1 = s.split("$");
    QString reel=list1.value(0), im=list1.value(1);
    Base *b1,*b2;

    if(reel.contains(",")) b1=ToReel(reel);
    else if(reel.contains("/")) b1=ToRationnel(reel);
    else b1=new Entier(reel.toInt());

    if(im.contains(",")) b2=ToReel(im);
    else if(im.contains("/")) b2=ToRationnel(im);
    else b2=new Entier(im.toInt());

    return (new Complexe(b1, b2));
}


QString eval(QString& s){
    QString tmp;
    for(int i=0; s.count(); i++)
        tmp+=*(s.data());


    return s;
}
