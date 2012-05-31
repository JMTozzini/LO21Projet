=> En fait ça marche nickel tu avais raison tout à l'heure ! C'est cool je pensais que c'était un problème plus grave

- Il faut que tu mettes ton algo pour la conversion d'un réel en rationnel dans la surcharge du + dans les classes Reel et Rationnel.

- Pour la sauvegarde des paramètres, il faut sauver l'état de la pile… J'avais zappé. Du coup il faudrait que je puisse avoir le dernier élément sans la dépiler. Est-ce que tu sais comment faire ça avec le modèle de pile que tu as mis ?


- J'ai commencé la classe complexe. 
	- Le soucis c'est qu'il faut instancier des objets de type Base dans le constructeur. Du coup j'ai mis base en classe non abstraite en définissant les fonctions sans rien mettre dedans. Si on la laisse abstraite, il faut surcharger le constructeur avec des int, float, et 4 arguments pour les rationnel. En plus je sais même pas si dans un complexe la partie imaginaire et la partie réelle sont de même type : est-ce qu'on peut avoir  1.2 $ 4  par exemple ?
	- Ensuite, j'ai surcharger operator+ pour Base pour qu'il choisisse tout seul quelle méthode + appeler, comme pour Constante. Mais ça marche pas.
	

Je m'y pencherai plus ce soir!
