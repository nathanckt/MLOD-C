/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

typedef struct gagnantS{
	int annee;
	char nom;
	char nature;
} Gagnant;

int numberOfWinners(FILE *dataFile){
	int number, countPointVirgule;
	char caractere;
	number = 0;
	while ((caractere = fgetc(dataFile)) != EOF){
		if(caractere == ';'){
			countPointVirgule++;
			if(countPointVirgule == 2){
				number++;
			}
		}
	}
	return number;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	char copie;

    FILE *dataFile, *outputFile;

	dataFile = fopen(filename,"r"); 
	outputFile = fopen(outputFilename,"w"); 

	if(dataFile==NULL) {
		printf ("Code de l'erreur : %d\n", errno);
		if (errno == ENOENT)
			printf ("Le fichier n'existe pas !\n");
		else
			printf ("Erreur inconnue\n");
		return EXIT_FAILURE;
	}
	
	while ((copie = fgetc(dataFile)) != EOF){
		fputc(copie,outputFile);
	}

	fclose(dataFile); 
	fclose(outputFile); 

	printf("nombre de gagnants : %d \n",numberOfWinners(dataFile));

	return EXIT_SUCCESS;
}
