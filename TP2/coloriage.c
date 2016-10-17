#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE* output = fopen("","w");
	FILE* input = fopen("Resultatminisat.txt","r");
	FILE* sommetFile = fopen("Resultat3Color.cnf","r");
	int nbSommet,i;
	char poubelle[50];
	
	fscanf(sommetFile, "%s %s %d %s", poubelle, poubelle, &nbSommet, poubelle);
	fclose (sommetFile);
	
	int sommet[nbSommet];
	fgets(poubelle,50,input);
	for(i = 0; i< nbSommet;i++)
		fscanf(input,"%d ",&sommet[i]);
	fclose(input);
	
	fputs("couleur 1 : ",output);
	for(i = 0; i< (nbSommet/3);i++)
		if(sommet[i]>0)
			fprintf(output, "%d ",sommet[i]);
			
	fputs("\ncouleur 2 : ",output);
	for(i = (nbSommet/3); i< ((2*nbSommet)/3);i++)
		if(sommet[i]>0)
			fprintf(output, "%d ",sommet[i]-(nbSommet/3));
			
	fputs("\ncouleur 3 : ",output);
	for(i = ((2*nbSommet)/3); i< nbSommet;i++)
		if(sommet[i]>0)
			fprintf(output, "%d ",sommet[i]-((2*nbSommet)/3));
	fclose(output);
}
