#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//PS : Une Sequence Max ne demarrera pas a 0, cela peut fournir une sequence differente des autres fonctions
//ce qui dit comparaison incorrect dans le script

void main (int argc, char *argv[])
{
	int Max = atoi(argv[1]), Idi = 1, Idj = 1;
	int SousSeq = 0,SousSeqMax = 0,j,i;
	
	for(j = 2; j < argc; j++){
		//SousSeq as comme bornes Idj et j
		SousSeq += atoi(argv[j]);
		//SousSeqMax additioné a la nouvelle cellule du tableau
		//SouSeqMax contient la meilleur SousSeq entre Idj et j
		SousSeqMax += atoi(argv[j]);
		
		//Si la nouvelle cellule est superieur a la SousSeqMax alors
		//SousSeq max est la nouvelle cellule
		//(dans le cas où SousSeqMax est/etait negatif)
		if(atoi(argv[j]) >= SousSeqMax)
		{
			SousSeqMax = atoi(argv[j]);
			i = j;
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
			Max = SousSeqMax;
			SousSeq = 0;
			SousSeqMax = 0;
			Idj = j;
			Idi = i;
			if(i+1 < argc)
				i = i+1;
		}
	}
	printf("La sous sequence Max est de %d, la borne k est %d, la borne l est %d\n",Max,Idi-1,Idj-1);
}
	
	

