#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* output = fopen("ResultatFinal.txt","w");
	FILE* input = fopen("ResultatMinisat.txt","r");
	int nbSommet = 729,i,ligne,colonne,valeur;
	char poubelle[50];
	
	//Enlever premiere ligne du minisat
	int sommet[nbSommet];
	fscanf(input,"%s",poubelle);
	if(strcmp(poubelle,"UNSAT") == 0){
		fclose(input);
		fclose(output);
		return 1; 
	}	
	fgets(poubelle,50,input);
	
	//Recuperer les valeurs
	for(i = 0; i< nbSommet;i++)
		fscanf(input,"%d ",&sommet[i]);
	fclose(input);
	
	//Afficher les valeurs
	for(ligne = 0; ligne< 9;ligne++){
		for(colonne = 0; colonne< 9;colonne++){
			for(valeur = 0; valeur< 9;valeur++)
				if(sommet[ligne*81 + colonne*9 + valeur]>0)
					fprintf(output, "%d",valeur);
		if(colonne == 2 || colonne == 5)
			fprintf(output, "X");
		}
	fprintf(output, "\n");
	if(ligne == 2 || ligne == 5)
		fprintf(output, "XXXXXXXXXXX\n");
	}
	fclose(output);
	
	return 0;
}
