#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::EvalPress()
{
    QString s=pa->Depiler();
    ps->Depiler();
    std::cout<<"coucou";

    QRegExp exp("'*'");
    exp.setPatternSyntax(QRegExp::Wildcard);

    if(exp.exactMatch(s)){
        s.remove("'");
        QString exp=eval(s);
        // Remettre '
        pa->Empiler(exp);
        ps->Empiler(new Expression(exp));
    }
    ui->champEcr->clear();
    AffichageEcran();
    MAJParam();

}
