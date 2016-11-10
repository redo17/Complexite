#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	FILE* output = fopen("ResultatKernel.cnf","w");
	int nbSommet = atoi(argv[1]);
	int nbArete = atoi(argv[2]);
	int nbClause = nbArete + nbSommet;
	int sommet,arete;
	int aretes[argc-3][2], i,j,arg = 3;
	for( i=0; i<nbArete; i++)
		for(j=0; j < 2; j++, arg++)
			aretes[i][j] = atoi(argv[arg]);

	fprintf(output,"p cnf %d %d\n\n",nbSommet,nbClause);
	
	//une arrete ne peu pas avoir 2 sommet kernel
	for(arete = 0; arete <nbArete; arete++)
		fprintf(output,"-%d -%d 0\n",aretes[arete][0],aretes[arete][1]);
	
	//un sommet doit soit etre kernel soit avoir un arc dirigé sur un kernel
	for(sommet = 1; sommet <(nbSommet+1); sommet++){
		fprintf(output,"%d ",sommet);
		for(i=0; i < argc-3; i++)
			if(aretes[i][0] == sommet)
				fprintf(output,"%d ",aretes[i][1]);
		fprintf(output,"0\n");
	}
	return 0;
}
