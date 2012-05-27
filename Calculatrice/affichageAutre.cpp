#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::EntrerPress()
{
    QString s=ui->champEcr->text();


    pa->Empiler(s);
    AffichageEcran();

    if(s.contains(","))
    {
        s.remove(" ");
        s.replace(s.indexOf(","),1,".");
        s.push_back('0'); s.push_front('0'); // on entre 2,_ ou _,2 et ça fonctionne
        Reel* r=new Reel(s);
        ps->Empiler(*r);
        ps->AffichagePile();
    }

    /*
    else if(s=="+") // Je comprend pas à quoi ça sert ?
    {
        pa->Depiler();
        PlusPress();
    }
    else if(s=="-") // Je comprend pas à quoi ça sert ?
    {
        pa->Depiler();
        MoinsPress();
    }

    s ne peut jamais être égal à + ou - car lorsqu'on appuie sur une opération, on l'execute directement on ne l'affiche pas
    -> J'ai juste fait en sorte que quand on tappe au clavier sur + ou - puis entrer, il dépile les deux derniers éléments, les ajoutent et
    empile le nouvel élément. Est-ce que c'est un mauvais comportement ?
    Sans ça, quand on met + ou - au clavier, il empile un string dans la pile d'affichage, et le résultat de l'opération dans le pile de
    stockage.
    Le problème là c'est surtout : est-ce que le comportement attendu quand on appuie sur le bouton plus ou qu'on rentre + au clavier puis entrer
    est différent ?
    */

    else
    {
        Entier* e=new Entier(s);
        ps->Empiler(*e);

    }
    ui->champEcr->clear();
}

