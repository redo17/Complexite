#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main(int argc,char **argv)
{
	int nbSommets=atoi(argv[1]);
	int densite=atoi(argv[2]);
	int i,j;
	int nbArretes=0,nbArretesDupliquee=0;
	int random;
	srand(time(NULL));
	int check;
	
	int arretes[nbSommets][nbSommets];
		for(i=0 ; i < nbSommets ; i++)
	  {
		for(j=0 ; j<nbSommets ; j++)
		{
				arretes[i][j]=0;
		}
		}
	
	
	for(i=0 ; i < nbSommets ; i++)
	{
		for(j=0 ; j<nbSommets ; j++)
		{
			if(i==j)
				continue;
			random=rand()%100;
			if(random < densite){
				arretes[i][j]=1;
				nbArretes++;
			}
		}
	}
	
	for(i=0 ; i < nbSommets ; i++)
	{
		for(j=0 ; j<nbSommets ; j++)
		{
			if(arretes[i][j]==1){
				if(arretes[j][i]==1){
					arretes[j][i]=0;
					nbArretesDupliquee++;
				}
			}
		}
	}
	
	nbArretes = nbArretes - nbArretesDupliquee;
	
	FILE *f=fopen("grapheRand","w");
	fprintf(f,"%d %d",nbSommets,nbArretes);
	for(i=0 ; i < nbSommets ; i++)
	{
		for(j=0 ; j<nbSommets ; j++)
		{
			if(arretes[i][j]==1){
				if(arretes[j][i]==1){
					arretes[j][i]=0;
					nbArretesDupliquee++;
				}
				fprintf(f," %d %d",i+1,j+1);
			}
		}
	}
	return 0;
}
