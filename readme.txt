- Operation pow termin�e normalement, apr�s y'a certains cas o� j'�tais pas s�re, �a serait bien que tu testes pour voir si �a te para�t logique.
Ah aussi : on peut pas faire pow sur un complexe, du coup �a fait pas l'op�ration mais �a le d�pile quand m�me.. Je sais pas si t'as une id�e pour �viter �a.
- J'avais fini cos, sin, tan, cosh, sinh et tanh aussi ce matin. J'ai aussi fait les complexes en croyant qu'on devait le faire, mais au final dans le sujet �a y �t� pas (non je l'ai pas lu avant.)
Bref je crois que je t'expliquerai �a demain.
++

7/06/12
- PowPress � voir

Annuler et rétablir fonctionnent !! 

Traitement d'erreur terminé, il faut encadrer le GetInfos() de exception avec TraitementErreur() :

try{...}catch(Exception e){TraitementErreur(e.GetInfos);} // pour l'affichage dans la barre du bas

