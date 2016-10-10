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
	if(argc != 3){
		printf("requiert le nombre de tiroir en premier argument\n");
		printf("requiert le nom du fichier pour le resultat en second argument\n");
		return;		
	}

	FILE* output=fopen(argv[2],"w");
	int nbTiroir = atoi(argv[1]),nbClauses;
	int nbChaussette = nbTiroir + 1;
	int nbVariables;
	int tiroir, chaussette;
	int chaussette1, chaussette2;

	nbClauses = nbChaussette + nbTiroir*coefBin(nbChaussette,2);
	nbVariables =nbChaussette * nbTiroir;
	
	fprintf(output,"p cnf %d %d\n\n",nbVariables,nbClauses);
	
	//la chaussette se trouve dans un seul tiroir
	for(chaussette=0;chaussette<nbChaussette;chaussette++)
	{
		for(tiroir=0;tiroir<nbTiroir;tiroir++)
		{
			fprintf(output,"%d ",(tiroir*nbChaussette+chaussette)+1);
		}
		fprintf(output,"0\n");
	}
	//un tiroir contient une seule chaussette
	for(tiroir=0;tiroir<nbTiroir;tiroir++)
	{
		for(chaussette1=0;chaussette1<nbChaussette;chaussette1++)
		{
			for(chaussette2=chaussette1+1;chaussette2<nbChaussette;chaussette2++)
			{
				fprintf(output,"%d %d 0\n",-((tiroir*nbChaussette+chaussette1)+1),-((tiroir*nbChaussette+chaussette2)+1));
			}
		}
	}
}
