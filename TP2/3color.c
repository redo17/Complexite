#include <stdio.h>
#include <stdlib.h>

double factorielle(int n)
{
	double resultat=n;
	while ( n>1 )
	{
		resultat*=(n-1);
		n--;
	}
	return resultat;	
}

double coefBin(int n,int k)
{
	return factorielle(n)/(factorielle(k)*(factorielle(n-k)));
}

void main(int argc, char ** argv)
{
	FILE* output = fopen("Resultat3Color.cnf","w");
	int nbSommet = atoi(argv[1]);
	int nbArete = atoi(argv[2]);
	int nbCouleur = 3;
	int nbVariables = nbSommet*nbCouleur;
	int nbClauses = nbArete^nbCouleur + nbSommet;
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
	{
		for(i=0; i<nbArete
			fprintf(output,"%d %d 0\n",-(arete);
	}
}
