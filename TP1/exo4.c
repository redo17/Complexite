#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Explications variables
//MaxValue contient le meilleur resultat actuel et final
//SousSeqValue contient les valeurs entre la borne droite de MaxValue et T[j]
//elle est utilisée pour trouver une nouvelle borne a droite de MaxValue
//MaxBisValue contient la meilleur sous sequence qui se trouve entre la borne gauche de MaxValue et T[j]
//elle est utilisée pour trouver une nouvelle borne a gauche de MaxValue



void main (int argc, char *argv[])
{
	int MaxValue = atoi(argv[1]), KMax = 1, LMax = 1;
	int SousSeqValue = 0,MaxBisValue = 0,j,i=2;
	
	for(j = 2; j < argc; j++){
		//SousSeqValue as comme bornes LMax et j
		SousSeqValue += atoi(argv[j]);
		//MaxBisValue additioné a la nouvelle cellule du tableau
		//MaxBisValue contient la meilleur sous sequence entre KMax et j
		MaxBisValue += atoi(argv[j]);
		
		//Si la nouvelle cellule est superieur a la MaxBisValue alors
		//MaxBisValue est la nouvelle cellule
		//(dans le cas où MaxBisValue est/etait negatif)
		if(atoi(argv[j]) > MaxBisValue)
		{
			MaxBisValue = atoi(argv[j]);
			i = j;
		}		
		//Si SousSeqValue est superieur a zero, elle rajoute sa valeur a
		//MaxValue et est remise a zero
		//Car une valeur positive ne peut etre que benefique au max
		if(SousSeqValue > 0)
		{
			MaxValue += SousSeqValue;
			SousSeqValue = 0;
			LMax = j;
		}
		//Si MaxBisValue est superieur a la Sequence Max alors
		//toute les SousSeq sont remise a zero a la recherche d'une valeur
		//superieur a la valeur negative trouvée
		if(MaxBisValue > MaxValue)
		{
			MaxValue = MaxBisValue;
			SousSeqValue = 0;
			MaxBisValue = 0;
			LMax = j;
			KMax = i;
			if(i+1 < argc)
				i = i+1;
		}
	}
	printf("%d %d %d\n",Max,KMax-1,LMax-1);
}
	
	

