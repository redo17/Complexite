#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void main ()
{
	int Tab[10];
	int Max = 0,MaxG = 0, MaxD = 0,kmax = 0, lmax = 0,lmax1 = 0,kk = 0,ll = 0,n=10;
	int SousSeq,SousSeqG,SousSeqD,i ,j, lmaxD;
	
	srand(time(NULL));
	for(i = 0; i < 10; i++) Tab[i] = rand()%20 -10;
	
	for(i = 0; i < 10; i++) printf("%d ",Tab[i]);

	printf("\n");
	
	for(i = 0; i < (n/2); i++)
	{
		SousSeqG = 0; SousSeqD = 0;lmaxD = n;

		for(j = i; j < (n/2) ; j++)
		{
			SousSeqG += Tab[j]; SousSeqD += Tab[n-j-1];lmaxD--;
			if(SousSeqG > MaxG)
			{
				MaxG = SousSeqG;
				kmax = i;
			}
			if(SousSeqD > MaxD)
			{
				MaxD = SousSeqD;
				lmax = n-j-1;
				lmax1 = n-lmaxD-1;				
			}
		}
	}
	
	printf("La sous sequence Max Gauche est de %d et Droite est de %d , la borne k est %d, la borne l est %d \n",MaxG,MaxD,kmax+1,lmax+lmax1+1);
	
	for(i = kmax; i < lmax+lmax1; i++)
	{
		SousSeq = 0;

		for(j = i; j < lmax+lmax1+1 ; j++)
		{
			SousSeq += Tab[j];
			if(SousSeq > Max)
			{
				Max = SousSeq;
				kk = i;
				ll = j;
			}
		}
	}
	printf("La sous sequence Max est de %d , la borne k est %d, la borne l est %d\n",Max,kk+1,ll+1);
}
	
	

