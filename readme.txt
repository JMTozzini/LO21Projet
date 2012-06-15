J'ai passer les deux pile et Gardien en singleton, si tu as un peu de tmps regarde si elles se comporte toujours bien, notamment Gardien.

Je n'arrive pas à mettre les fonctions annexes dans doxygen...
=> En fait il faut documenter chaque fichier .h avec /file, sinon il apparaît mais ya pas de page spéciale.
Je l'ai fait pour tous sauf ui_mainwindow.h, comme c'est un truc graphique je sais pas si on peut.
Tu sais si il faut beaucoup détailler les commentaires ou pas ? A mon avis ils vont juste lire comme ça..
-> Je pense que ça dépend, les chose pas très intuitive genre l'historique je vais essayer de le détailler un peu...

J'ai commencé un rapport en latex, ça te va ?
Je sais pas combien il faut faire de diagrammes de séquence, je pense que je vais en faire un autre pour les expressions..
->Problème de rapport, la norme c'est UFT8 donc si tu encode le rapport en MAC je peux pas le compiler, regarde s'il y a possibilité d'encoder en utf8 sous mac sinon ça va être chiant...
===> J'ai essayé de compiler ta version, et ça a mis des caractères spéciaux partout.. je sais pas si tu vas les voir chez toi, en tous cas si tu as gardé l'ancienne version remet la, je vais essayer de pas mettre ma version sur GitHub mais j'ai peur que ça fasse un conflit.
Pour les modifications je changerai la ligne de utf8 avec l'encodage mac, c'est pas grave.

J'ai ajouté une petite icone, c'est unpeu inutile mais bon... Il faut qu'elle soit dans le même dossier que l'executable (pas celui des sources)
===> Dommage chez moi elle marche pas..

Il reste quoi à faire du coup ?
->On fait le point Jeudi matin 8h30 à la bu ?
=======


A FAIRE
--------------


=> Ok normalement c'est bon, mis à part que y'a plus ta sécurisation d'opérations, j'espère que tu l'as encore.

- Mec le rapport fait 13 pages ! C'était censé être entre 3 et 5… Du coup j'ai enlevé la liste des figures et changé le style des titres, je sais pas si ça prend vraiment moins de place en tous cas je trouve ça plus joli perso. Bref si ça se plaît pas vire le.
->tu as rajouté un package que j'ai pas donc je peux pas modifier le rapport, il reste juste a voir les fautes d'orthographes parce que je suis archi nul.

- J'ai sécurisé des fonctions, l'annuler ne marche qu'au bout du deuxième clic j'arrive pas a voir pourquoi. Comme la démo est sur ton pc fait le tourner chez toi pour être sur que ça bug pas. Essaye également de mettre les raccourcis pour "Rétablir" & "Annuler".
