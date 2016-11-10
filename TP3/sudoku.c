#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	FILE* output = fopen("ResultatSudoku.cnf","w");
	int nbCases = 9*9*9;
	char chaine[81];
	int nbClause = 0,i,ligne,colonne,valeur,ligneBis,colonneBis,valeurBis;
	
	scanf("%s", chaine);
	
	printf("%d", ((3/9) * 80) + ((3%9) * 9) + 8);
/*
52...6.........7.13...........4..8..6......5...........418.........3..2...87.....
...81...5....2..3.8....5.494..1...63.2.....9.37...2..878.2....6.4..5....6...98...
*/	
	// calcul du nombre de cases deja fixée dans le sudoku
	for(i = 0; i < 81; i++)
		if(chaine[i] != '.')
			 nbClause++;
			 
	// sa doit pas etre loin de ca
	nbClause += 9*9*4 + 9*9*9*4.5*4;
	
	fprintf(output,"p cnf %d %d\n\n",nbCases,nbClause);
	
	//au moins une valeur par case
	for(ligne = 0; ligne <9; ligne++)
		for(colonne = 0; colonne <9; colonne++){
			for(valeur = 1; valeur <=9; valeur++)
				fprintf(output,"%d ",81*ligne + 9*colonne + valeur);
			fprintf(output,"0\n");
		}
			
	//au moins une fois chaque chiffre sur chaque ligne
	for(ligne = 0; ligne <9; ligne++)
		for(valeur = 1; valeur <=9; valeur++){
			for(colonne = 0; colonne <9; colonne++)
				fprintf(output,"%d ",81*ligne + 9*colonne + valeur);
			fprintf(output,"0\n");
		}
	
	//au moins une fois chaque chiffre sur chaque colonne
	
	for(colonne = 0; colonne <9; colonne++)
		for(valeur = 1; valeur <=9; valeur++){
			for(ligne = 0; ligne <9; ligne++)
				fprintf(output,"%d ",81*ligne + 9*colonne + valeur);
			fprintf(output,"0\n");
		}
	//au moins une fois chaque chiffre dans chaque region
	//region 1
	for(valeur = 1; valeur <=9; valeur++){
		for(ligne = 0; ligne <3; ligne++)
			for(colonne = 0; colonne <3; colonne++)
				fprintf(output,"%d ",81*ligne + 9*colonne + valeur);
		fprintf(output,"0\n");
	}
	
	//region 2
	for(valeur = 1; valeur <=9; valeur++){
		for(ligne = 0; ligne <3; ligne++)
			for(colonne = 3; colonne <6; colonne++)
				fprintf(output,"%d ",81*ligne + 9*colonne + valeur);
		fprintf(output,"0\n");
	}
		
	//region 3
	for(valeur = 1; valeur <=9; valeur++){
		for(ligne = 0; ligne <3; ligne++)
			for(colonne = 6; colonne <9; colonne++)
				fprintf(output,"%d ",81*ligne + 9*colonne + valeur);
		fprintf(output,"0\n");
	}

	//region 4
	for(valeur = 1; valeur <=9; valeur++){
		for(ligne = 3; ligne <6; ligne++)
			for(colonne = 0; colonne <3; colonne++)
				fprintf(output,"%d ",81*ligne + 9*colonne + valeur);
		fprintf(output,"0\n");
	}

	//region 5
	for(valeur = 1; valeur <=9; valeur++){
		for(ligne = 3; ligne <6; ligne++)
			for(colonne = 3; colonne <6; colonne++)
				fprintf(output,"%d ",81*ligne + 9*colonne + valeur);
		fprintf(output,"0\n");
	}

	//region 6
	for(valeur = 1; valeur <=9; valeur++){
		for(ligne = 3; ligne <6; ligne++)
			for(colonne = 6; colonne <9; colonne++)
				fprintf(output,"%d ",81*ligne + 9*colonne + valeur);
		fprintf(output,"0\n");
	}		
	
	//region 7	
	for(valeur = 1; valeur <=9; valeur++){
		for(ligne = 6; ligne <9; ligne++)
			for(colonne = 0; colonne <3; colonne++)
				fprintf(output,"%d ",81*ligne + 9*colonne + valeur);
		fprintf(output,"0\n");
	}
		
	//region 8
	for(valeur = 1; valeur <=9; valeur++){
		for(ligne = 6; ligne <9; ligne++)
			for(colonne = 3; colonne <6; colonne++)
				fprintf(output,"%d ",81*ligne + 9*colonne + valeur);
		fprintf(output,"0\n");
	}
		
	//region 9
	for(valeur = 1; valeur <=9; valeur++){
		for(ligne = 6; ligne <9; ligne++)
			for(colonne = 6; colonne <9; colonne++)
				fprintf(output,"%d ",81*ligne + 9*colonne + valeur);
			fprintf(output,"0\n");
	}
		
	//au plus une valeur par case
	for(ligne = 0; ligne <9; ligne++)
		for(colonne = 0; colonne <9; colonne++)
			for(valeur = 1; valeur <=9; valeur++)
				for(valeurBis = valeur+1; valeurBis <=9; valeurBis++)
					fprintf(output,"-%d -%d 0\n",(81*ligne + 9*colonne + valeur), (81*ligne + 9*colonne + valeurBis));
					
	//au plus une fois chaque chiffre sur chaque ligne
	for(ligne = 0; ligne <9; ligne++)
		for(colonne = 0; colonne <9; colonne++)
			for(valeur = 1; valeur <=9; valeur++)
				for(ligneBis = ligne+1; ligneBis <9; ligneBis++)
					fprintf(output,"-%d -%d 0\n",81*ligne + 9*colonne + valeur, 81*ligneBis + 9*colonne + valeur);
					
	//au plus une fois chaque chiffre sur chaque colonne
	for(ligne = 0; ligne <9; ligne++)
		for(colonne = 0; colonne <9; colonne++)
			for(valeur = 1; valeur <=9; valeur++)
				for(colonneBis = colonne+1; colonneBis <9; colonneBis++)
					fprintf(output,"-%d -%d 0\n",81*ligne + 9*colonne + valeur, 81*ligne + 9*colonneBis + valeur);
				
	//au plus une fois chaque chiffre dans chaque region
	//region 1
	for(valeur = 1; valeur <=9; valeur++)
		for(ligne = 0; ligne <3; ligne++)
			for(colonne = 0; colonne <3; colonne++)
				for(ligneBis = ligne; ligneBis <3; ligneBis++)
					for(colonneBis = colonne+1; colonneBis <3; colonneBis++)
							fprintf(output,"-%d -%d 0\n",81*ligne + 9*colonne + valeur, 81*ligneBis + 9*colonneBis + valeur);
					
	//region 2
	for(valeur = 1; valeur <=9; valeur++)
		for(ligne = 0; ligne <3; ligne++)
			for(colonne = 3; colonne <6; colonne++)
				for(ligneBis = ligne; ligneBis <3; ligneBis++)
					for(colonneBis = colonne+1; colonneBis <6; colonneBis++)
							fprintf(output,"-%d -%d 0\n",81*ligne + 9*colonne + valeur, 81*ligneBis + 9*colonneBis + valeur);
						
	//region 3
	for(valeur = 1; valeur <=9; valeur++)
		for(ligne = 0; ligne <3; ligne++)
			for(colonne = 6; colonne <9; colonne++)
				for(ligneBis = ligne; ligneBis <3; ligneBis++)
					for(colonneBis = colonne+1; colonneBis <9; colonneBis++)
							fprintf(output,"-%d -%d 0\n",81*ligne + 9*colonne + valeur, 81*ligneBis + 9*colonneBis + valeur);
						
	//region 4
	for(valeur = 1; valeur <=9; valeur++)
		for(ligne = 3; ligne <6; ligne++)
			for(colonne = 0; colonne <3; colonne++)
				for(ligneBis = ligne; ligneBis <6; ligneBis++)
					for(colonneBis = colonne+1; colonneBis <3; colonneBis++)
							fprintf(output,"-%d -%d 0\n",81*ligne + 9*colonne + valeur, 81*ligneBis + 9*colonneBis + valeur);

	//region 5
	for(valeur = 1; valeur <=9; valeur++)
		for(ligne = 3; ligne <6; ligne++)
			for(colonne = 3; colonne <6; colonne++)
				for(ligneBis = ligne; ligneBis <6; ligneBis++)
					for(colonneBis = colonne+1; colonneBis <6; colonneBis++)
							fprintf(output,"-%d -%d 0\n",81*ligne + 9*colonne + valeur, 81*ligneBis + 9*colonneBis + valeur);

	//region 6
	for(valeur = 1; valeur <=9; valeur++)
		for(ligne = 3; ligne <6; ligne++)
			for(colonne = 6; colonne <9; colonne++)
				for(ligneBis = ligne; ligneBis <6; ligneBis++)
					for(colonneBis = colonne+1; colonneBis <9; colonneBis++)
							fprintf(output,"-%d -%d 0\n",81*ligne + 9*colonne + valeur, 81*ligneBis + 9*colonneBis + valeur);

	//region 7
	for(valeur = 1; valeur <=9; valeur++)
		for(ligne = 6; ligne <9; ligne++)
			for(colonne = 0; colonne <3; colonne++)
				for(ligneBis = ligne; ligneBis <9; ligneBis++)
					for(colonneBis = colonne+1; colonneBis <3; colonneBis++)
							fprintf(output,"-%d -%d 0\n",81*ligne + 9*colonne + valeur, 81*ligneBis + 9*colonneBis + valeur);

	//region 8
	for(valeur = 1; valeur <=9; valeur++)
		for(ligne = 6; ligne <9; ligne++)
			for(colonne = 3; colonne <6; colonne++)
				for(ligneBis = ligne; ligneBis <9; ligneBis++)
					for(colonneBis = colonne+1; colonneBis <6; colonneBis++)
							fprintf(output,"-%d -%d 0\n",81*ligne + 9*colonne + valeur, 81*ligneBis + 9*colonneBis + valeur);

	//region 9
	for(valeur = 1; valeur <=9; valeur++)
		for(ligne = 6; ligne <9; ligne++)
			for(colonne = 6; colonne <9; colonne++)
				for(ligneBis = ligne; ligneBis <9; ligneBis++)
					for(colonneBis = colonne+1; colonneBis <9; colonneBis++)
							fprintf(output,"-%d -%d 0\n",81*ligne + 9*colonne + valeur, 81*ligneBis + 9*colonneBis + valeur);

	//Les valeurs fixée du sudoku
	for(i = 0; i < 81; i++)
		if(chaine[i] != '.')
			fprintf(output,"%d 0\n",((i/9) * 81) + ((i%9) * 9) + chaine[i] - '0');
			 
	return 0;
}
