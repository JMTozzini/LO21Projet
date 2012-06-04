#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::EvalPress()
{
    QString s=pa->Depiler();
    Constante *c=&(ps->Depiler());

    /*QRegExp exp("'*'");
    exp.setPatternSyntax(QRegExp::Wildcard);

    if(exp.exactMatch(s)){*/
    //je pense que c'est plus robuste de tester le type de ps

    if(c->GetType()=="expression") //J'ai pas compris ce que tu voulais faire... La ça fonctionne mais j'ai fait completement autre chose
    {
        std::cout<<"c'est une expression"<<std::endl;
        s.remove("'");
        QStringList liste = s.split(" ");
        for(int i=0;i<liste.size();i++)
        {
            //std::cout<<liste.value(i).toStdString()<<std::endl;
            ui->champEcr->insert(liste.value(i));
            EntrerPress();
        }
        /*s.remove("'");
        QString exp=eval(s);
        // Remettre '
        pa->Empiler(exp);
        ps->Empiler(new Expression(exp));*/
    }
    ui->champEcr->clear();
    AffichageEcran();
    MAJParam();

}
