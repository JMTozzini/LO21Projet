#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::EvalPress()
{
    try
    {
        QString s=pa->Depiler();
        Constante* c=&(ps->Depiler());

        if(c->GetType()=="expression")
        {
            s.remove("'");
            QStringList liste = s.split(" ");
            for(int i=0;i<liste.size();i++)
            {
                ui->champEcr->insert(liste.value(i));
                EntrerPress();
            }

        }
    }
    catch(ExceptionCalculatrice e){e.GetInfos();}

    ui->champEcr->clear();
    AffichageEcran();
    MAJParam();
}
