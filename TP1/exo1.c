#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void main ()
{
	int Tab[10];
	int Max = 0, Idi = 0, Idj = 0;
	int SousSeq,i ,j,k;
	
	srand(time(NULL));
	
	for(i = 0; i < 10; i++)
		Tab[i] = rand()%20 -10;
	
	for(i = 0; i < 10; i++)
		printf("%d ",Tab[i]);
	printf("\n");
	
	for(i = 0; i < 10; i++){
		for(j = i; j < 10 ; j++)
		{
			SousSeq = 0;
			for(k = i; k <= j; k++)
			{
				SousSeq += Tab[k];
				if(SousSeq > Max)
				{
					Max = SousSeq;
					Idi = i;
					Idj = j;
				}
			}
		}
	}
	printf("La sous sequence Max est de %d, la borne k est %d, la borne l est %d\n",Max,Idi+1,Idj+1);
}
	
	

