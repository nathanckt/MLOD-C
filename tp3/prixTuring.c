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
	unsigned int annee;
	char *nom; // \0 à la fin
	char *sujet; // \0 à la fin
} Gagnant;

typedef struct gagnantsS{
	Gagnant *gagnants;
	int nombreGagnants;
} Gagnants;

int numberOfWinners(FILE *dataFile){
	rewind(dataFile);
	int number, maxline;
	char *ligne;

	maxline = 2048;
    ligne = malloc(maxline * sizeof(char));

    number = 0;

    while(fgets(ligne, maxline, dataFile) != NULL) {
        number++;
    }

    free(ligne);
	return number;
}

void readWinners(FILE *DataFile, Gagnants *listeGagnants){

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
	
	printf("nombre de gagnants : %d \n",numberOfWinners(dataFile));

	//readWinners
	Gagnants listeGagnants;
	readWinners(dataFile, &listeGagnants);

	//test-readWinners
	if(listeGagnants.gagnants[3].nom == "John McCarthy"){
		printf("c'est stocké avec succès ! \n");
	}


	fclose(dataFile); 
	fclose(outputFile); 

	return EXIT_SUCCESS;
}
