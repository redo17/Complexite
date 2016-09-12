#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void main (int argc, char *argv[])
{
	int Max = 0,MaxG = 0, MaxD = 0,kmax = 0, lmax = 0 ;
	int SousSeq,SousSeqG,SousSeqD,i ,j, z, m;
	
		
	for(i = 1; i < (argc/2)+1; i++)
	{
		SousSeqG = 0; SousSeqD = 0;z = argc;

		for(j = i; j < (argc/2)+1 ; j++)
		{
			SousSeqG += atoi(argv[j]);
			SousSeqD += atoi(argv[argc-j-1]);
			z--;

			if(SousSeqG > MaxG)
			{
				MaxG = SousSeqG;
				kmax = i;
			}

			if(SousSeqD > MaxD)
			{
				MaxD = SousSeqD;
				lmax = (argc-j-1) + (argc-z-1);
				//lmaxD = n-z-1;				
			}
		}
	}
	
	printf("La sous sequence Max Gauche est de %d et Droite est de %d , la borne k est %d, la borne l est %d \n",MaxG,MaxD,kmax+1,lmax+1);
	
	m = lmax ;	
	
	for(i = kmax; i < m; i++)
	{
		SousSeq = 0;

		for(j = i; j < m +1 ; j++)
		{
			SousSeq += atoi(argv[j]);

			if(SousSeq > Max)
			{
				Max = SousSeq;
				kmax = i;
				lmax = j;
			}
		}
	}
	printf("La sous sequence Max est de %d , la borne k est %d, la borne l est %d\n",Max,kmax+1,lmax+1);
}
	
	

