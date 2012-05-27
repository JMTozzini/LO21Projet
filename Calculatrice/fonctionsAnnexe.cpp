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
