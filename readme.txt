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

Reste le LN sachant que LOG(X)=LN(X)/LN(10)

Corrections erreurs dans affichageOp.cpp 

J'ai fait la variable utilisateur x, defini comme une constante* dans mainwindow
-> Je comprend pas comment marche ce x, il me met "valeur non reconnue"
=> il faut d'abord que tu enregistre une valeur pour x, en faisant 'x=1$2' par exemple, et que tu evalues l'expression
Ensuite tu peux utiliser x directement.
J'ai ajouté la sauvegarde de la valeur dans le fichier param.txt