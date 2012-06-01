#include "fonctionsAnnexe.h"

QString& ToQString(Constante& c)
{
    QString* s=new QString(' ');

    if(c.GetType()=="reel")
    {
        *s=QString::number(c.GetVal());
        s->replace(s->indexOf("."),1," , ");
    }
    else if (c.GetType()=="entier")
    {
        *s=QString::number(c.GetVal());
    }
    return *s;
}


Reel* ToReel(QString& s){
    s.remove(" ");
    s.replace(s.indexOf(","),1,".");
    return new Reel(s);
}

Rationnel* ToRationnel(QString& s){
    s.remove(" ");
    QStringList list1 = s.split("/");
    return new Rationnel(list1.value(1).toInt(),list1.value(2).toInt());
}

Complexe* ToComplexe(QString& s){
    s.remove(" ");
    QStringList list1 = s.split("/");
    QString reel=list1.value(1), im=list1.value(2);

    if(reel.contains(",")) Reel* b1=ToReel(reel);
    else if(reel.contains("/")) Rationnel* b1=ToRationnel(reel);
    else Entier* b1=new Entier(reel.toInt());

    if(im.contains(",")) Reel* b2=ToReel(im);
    else if(im.contains("/")) Rationnel* b2=ToRationnel(im);
    else Entier* b2=new Entier(im.toInt());

    Complexe* c=new Complexe(b1, b2);
}
