#include <stdio.h>
#include <stdlib.h>

void main(int argc, char ** argv)
{
	FILE* output = fopen("Resultat3Color.cnf","w");
	int nbSommet = atoi(argv[1]);
	int nbArete = atoi(argv[2]);
	int nbCouleur = 3;
	int nbVariable = nbSommet*nbCouleur;
	int nbClause = nbArete * nbCouleur + nbSommet;
	int sommet, couleur;
	int aretes[argc-3], i;
	for(i=3; i < argc; i++)
		aretes[i-3] = atoi(argv[i]);
	
	fprintf(output,"p cnf %d %d\n\n",nbVariable,nbClause);
	
	//un sommet ne peut avoir que une couleur
	for(sommet=0;sommet<nbSommet;sommet++)
	{
		for(couleur=0;couleur<nbCouleur;couleur++)
		{
			fprintf(output,"%d ",(couleur*nbSommet+sommet)+1);
		}
		fprintf(output,"0\n");
	}
	//les aretes entre chaque sommet (pour chaque couleur)
	for(couleur=0;couleur<nbCouleur;couleur++)
		for(i=0; i<(nbArete*2); i++){
			fprintf(output,"%d %d 0\n",-(aretes[i]+(couleur*nbSommet)),-(aretes[i+1]+(couleur*nbSommet)));
			i++;
		}
}
