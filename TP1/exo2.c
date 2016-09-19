#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main (int argc, char *argv[])
{
<<<<<<< HEAD
	int Max = atoi(argv[1]), Idi = 0, Idj = 0;
=======
	int Max = atoi(argv[1]), Idi = 1, Idj = 1;
>>>>>>> b038a41eab56354c90f0d5d501b6e19d3a2a4dc7
	int SousSeq,i,j;
	
	for(i = 1; i < argc; i++){
		SousSeq = 0;
		for(j = i; j < argc ; j++)
		{
			SousSeq += atoi(argv[j]);
			if(SousSeq > Max)
			{
				Max = SousSeq;
				Idi = i;
				Idj = j;
			}
		}
	}
	printf("La sous sequence Max est de %d, la borne k est %d, la borne l est %d\n",Max,Idi-1,Idj-1);
}
	
	

