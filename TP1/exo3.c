#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int* max3(int* x,int* y,int* z){

	int* maximum;maximum=malloc(3);
	
	if(x[0]>y[0]) maximum=x;
		else maximum=y;
	
	if (maximum[0]>z[0]) maximum=maximum;
		else maximum=z;

	return maximum;
}


int* SousSeqMilieu(int tab[],int Idi,int Idj)
{
	int element = Idi+(Idj-Idi)/2 +1;
	int* resultat;resultat=malloc(3);resultat[0]=0;
	int i,tmp=tab[element];

	resultat[0]=tab[element]; 

	for(i=element-1;i >= Idi ; i--)
	{
		tmp+=tab[i];
			if(tmp > resultat[0])
				{resultat[0]= tmp;resultat[1]=i;}
	}
	//printf("1ere boucle : %d %d \n",resultat[0],k);
	
	tmp= resultat[0];
	
	if((Idj - Idi) > 1)
	{
		for(i=element+1;i <= Idj ; i++)
		{
			tmp+=tab[i];
				if( tmp > resultat[0])
					{resultat[0]= tmp;resultat[2]=i;}
		}
	//printf("2eme boucle : %d %d \n",resultat[0],l);
	}

	return resultat;
}



int* SousSeq(int Tab[],int Idi,int Idj)
{
		int *maximum;
		maximum=malloc(3);	

		if(Idi==Idj)
			{maximum[0]=Tab[Idj];maximum[1]=Idi;maximum[2]=Idj; return maximum;}
			
		maximum=max3(
				SousSeq(Tab, Idi, Idi+((Idj-Idi)/2)),
				SousSeqMilieu(Tab, Idi, Idj),
				SousSeq(Tab, Idi+((Idj-Idi)/2)+1, Idj)
			);
		
	return maximum;
}


void main (int argc, char *argv[])
{
	int i,Tab[argc-1];
	for(i=1 ; i < argc ; i++)		
		Tab[i-1]=atoi(argv[i]);	
			
	int *resultat;
	resultat=malloc(3);
	resultat=SousSeq(Tab,0,argc-2);
	
	//printf("%d %d %d\n",resultat[0],resultat[1],resultat[2]);
	printf("La sous sequence Max est de %d, la borne k est %d, la borne l est %d\n",resultat[0],resultat[1],resultat[2]);
	

}
	
	
