#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void main ()
{
	int Tab[10];
	int Max = 0, Idi = 0, Idj = 0;
	int SousSeqMax,i ,j;
	
	srand(time(NULL));
	for(i = 0; i < 10; i++)
		Tab[i] = rand()%20 -10;
	
	for(i = 0; i < 10; i++)
		printf("%d ",Tab[i]);
	printf("\n");
	
	for(i = 0; i < 10; i++){
		SousSeqMax = Tab[i];
		if(SousSeqMax > Max)
		{
			Max = SousSeqMax;
			Idi = i;
			Idj = i;
		}
		for(j = i+1; j < 10 ; j++)
		{
			SousSeqMax += Tab[j];
			if(SousSeqMax > Max)
			{
				Max = SousSeqMax;
				Idi = i;
				Idj = j;
			}
		}
	}
	printf("La sous sequence Max est de %d, la borne k est %d, la borne l est %d\n",Max,Idi,Idj);
}
	
	

