#include "fonctionsAnnexe.h"
#include "constante.h"

Reel* ToReel(QString& s){
    s.remove(" ");
    s.replace(s.indexOf(","),1,".");
    return new Reel(s);
}

Rationnel* ToRationnel(QString& s){
    s.remove(" ");
    QStringList list1 = s.split("/");
    Rationnel* ra=new Rationnel(list1.value(0).toInt(),list1.value(1).toInt());
    ra->Simplifier();
    return ra;
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



int PGCD(int min, int max)
{
    int res=max-min;
    if(min==0)
        return max;
    else if(res>=min)
        PGCD(min,res);
    else if(min>0)
        PGCD(res,min);
    else
        return -1;
}

void Rationnel::Simplifier()
{
    int res;

    if(numerateur<=denominateur)
        res=PGCD(numerateur,denominateur);
    else
        res=PGCD(denominateur,numerateur);

    if(res==-1){res=-1;}

    numerateur/=res; denominateur/=res;
}
