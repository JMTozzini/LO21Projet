=> En fait �a marche nickel tu avais raison tout � l'heure ! C'est cool je pensais que c'�tait un probl�me plus grave

- Il faut que tu mettes ton algo pour la conversion d'un r�el en rationnel dans la surcharge du + dans les classes Reel et Rationnel.

- Pour la sauvegarde des param�tres, il faut sauver l'�tat de la pile� J'avais zapp�. Du coup il faudrait que je puisse avoir le dernier �l�ment sans la d�piler. Est-ce que tu sais comment faire �a avec le mod�le de pile que tu as mis ?


- J'ai commenc� la classe complexe. 
	- Le soucis c'est qu'il faut instancier des objets de type Base dans le constructeur. Du coup j'ai mis base en classe non abstraite en d�finissant les fonctions sans rien mettre dedans. Si on la laisse abstraite, il faut surcharger le constructeur avec des int, float, et 4 arguments pour les rationnel. En plus je sais m�me pas si dans un complexe la partie imaginaire et la partie r�elle sont de m�me type : est-ce qu'on peut avoir  1.2 $ 4  par exemple ?
	- Ensuite, j'ai surcharger operator+ pour Base pour qu'il choisisse tout seul quelle m�thode + appeler, comme pour Constante. Mais �a marche pas.
	

Je m'y pencherai plus ce soir!
