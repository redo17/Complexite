#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main (int argc, char *argv[])
{
	int Max = atoi(argv[1]), Idi = 0, Idj = 0;
	int SousSeq,i,j,k;
	
	for(i = 1; i < argc; i++){
		for(j = i; j < argc ; j++)
		{
			SousSeq = 0;
			for(k = i; k <= j; k++)
			{
				SousSeq += atoi(argv[k]);
			}
			if(SousSeq > Max)
			{
				Max = SousSeq;
				Idi = i;
				Idj = j;
			}
		}
	}
	printf("%d %d",Idi-1,Idj-1);
}
