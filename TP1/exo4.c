#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//PS : Une Sequence Max ne demarrera pas a 0, cela peut fournir une sequence differente des autres fonctions
//ce qui dit comparaison incorrect dans le script

void main (int argc, char *argv[])
{
	int MaxValue = atoi(argv[1]), KMax = 1, LMax = 1;
	int SousSeqValue = 0,MaxBisValue = 0,j,LMaxBis=2;
	
	for(j = 2; j < argc; j++){
		//SousSeq as comme bornes Idj et j
		SousSeq += atoi(argv[j]);
		//SousSeqMax additioné a la nouvelle cellule du tableau
		//SouSeqMax contient la meilleur SousSeq entre Idj et j
		SousSeqMax += atoi(argv[j]);
		
		//Si la nouvelle cellule est superieur a la SousSeqMax alors
		//SousSeq max est la nouvelle cellule
		//(dans le cas où SousSeqMax est/etait negatif)
		if(atoi(argv[j]) > SousSeqMax)
		{
			MaxBisValue = atoi(argv[j]);
			LMaxBis = j;
		}		
		//Si SousSeq est superieur a zero, elle rajoute sa valeur a
		//la Sequence Max et est remise a zero
		//Car une valeur positive ne peut etre que benefique au max
		if(SousSeq > 0)
		{
			Max += SousSeq;
			SousSeq = 0;
			Idj = j;
		}
		//Si SousSeqMax est superieur a la Sequence Max alors
		//toute les SousSeq sont remise a zero a la recherche d'une valeur
		//superieur a la valeur negative trouvée
		if(SousSeqMax > Max)
		{
			MaxValue = MaxBisValue;
			SousSeqValue = 0;
			MaxBisValue = 0;
			LMax = j;
			KMax = LMaxBis;
			if(LMaxBis+1 < argc)
				LMaxBis = LMaxBis+1;
		}
	}
	printf("%d %d %d\n",MaxValue,KMax-1,LMax-1);
}
	
	

