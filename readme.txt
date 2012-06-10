try{...}catch(Exception e){TraitementErreur(e.GetInfos);} // pour l'affichage dans la barre du bas

- On a bossé en même temps sur le projet, du cout j'ai du mixer les deux versions, essaye de retester tes fonctions parce que je suis pas sûre de tout avoir bien gardé.
- Ton mod marche, mais je sais pas si ya pas un soucis avec le type de retour, parce que quand je fais :

1
1
mod
1
mod

Ca plante. J'ai pas plus regardé ton code, mais c'est chelou
-> Chez moi ça fonctionne...

Modulo, Factorielle, Signe, sqr, cube, sqrt, inv terminés. Mise a jour de Div grâce à Signe

Corrections erreurs dans affichageOp.cpp 

J'ai fait la variable utilisateur x, defini comme une constante* dans mainwindow
-> Je comprend pas comment marche ce x, il me met "valeur non reconnue"
=> il faut d'abord que tu enregistre une valeur pour x, en faisant 'x=1$2' par exemple, et que tu evalues l'expression
Ensuite tu peux utiliser x directement.
J'ai ajouté la sauvegarde de la valeur dans le fichier param.txt
<<<<<<< HEAD
=======


J'ai un soucis avec la sauvegarde de la pile. Je sais pass si c'est ça qui te fait planter, mais en tous c'est sûr que c'est source de bugs..
Le problème c'est quand on veut sauvegarder une pile vide. Comment est-ce qu'on peut savoir si la pile de stockage est vide ou pas ?
J'avais fait :
if(ps->GetPtr().empty()){
            fichier<<"pile"<<std::endl;
            pa->Save(fichier);
        }
parce que ps est un deque
Mais ça renvoie 1 alors que la pile est vide.. T'as pas une idée?
->peut-etre tester ps->GetPtr()[0] ? 

=> Non ça marche pas non plus, le pointeur existe maisn il a rien dedans.. Du coup on peut pas sauvegarder une pile vide.
Tu crashes toujours avec les changements que j'ai fait ? J'ai remis le x
->Je crash encore...
