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

typedef struct {
	unsigned int annee;
	char *nom; // \0 à la fin
	char *sujet; // \0 à la fin
} Gagnant;

typedef struct{
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
		if(strcmp(ligne, "\n") != 0){
			number++;
		}
    }

    free(ligne);
	return number;
}

//listeGagnants doit être crée avant d'être passé en paramètre. Il faut passer une adresse en paramètre
void readWinners(FILE *dataFile, Gagnants *listeGagnants){
	int maxline = 2048, nombreWinners = numberOfWinners(dataFile), i = 0;
	rewind(dataFile);
	char *ligne;
	ligne = malloc(maxline * sizeof(char));
	listeGagnants->nombreGagnants = nombreWinners;
	listeGagnants->gagnants = malloc(nombreWinners*sizeof(Gagnant));

	while(fgets(ligne, maxline, dataFile) != NULL) {
		if(strcmp(ligne, "\n") != 0){
			char *token;

			token = strtok(ligne, ";");
			listeGagnants->gagnants[i].annee = atoi(token);

			token = strtok(NULL, ";");
			listeGagnants->gagnants[i].nom = strdup(token);

			token = strtok(NULL, "\n");
			listeGagnants->gagnants[i].sujet = strdup(token);

			i++;
		}
    }
}

// void printWinners(FILE *output, Gagnants *listeGagnants){
// 	rewind(output);
// 	char *annee, *nom, *sujet, *ligne;
// 	ligne = malloc(1024*sizeof(char));

// 	for(int i = 0 ; i < listeGagnants->nombreGagnants; i++){
// 		char charAnnee[4];
// 		sprintf(charAnnee, "%d", listeGagnants->gagnants[i].annee);
// 		annee = charAnnee;
// 		nom = listeGagnants->gagnants[i].nom;
// 		sujet = listeGagnants->gagnants[i].sujet;

// 		strcat(ligne, annee);
// 		strcat(ligne,";");
// 		strcat(ligne, nom);
// 		strcat(ligne,";");
// 		strcat(ligne, sujet);
// 		strcat(ligne,"\n");

// 		printf("%s", ligne);

// 	}

// 	free(ligne);
	
// }

void printWinners(FILE *output, Gagnants *listeGagnants){
    rewind(output);
    char *ligne;
	int maxline = 1024;

	ligne = malloc(maxline*sizeof(char));
    ligne[0] = '\0';

    for(int i = 0; i < listeGagnants->nombreGagnants; i++){
		ligne[0] = '\0';
        char charAnnee[5];
        sprintf(charAnnee, "%d", listeGagnants->gagnants[i].annee);

        sprintf(ligne, "%s;%s;%s\n", charAnnee, listeGagnants->gagnants[i].nom, listeGagnants->gagnants[i].sujet);
        
        fputs(ligne, output);
        printf("%s", ligne);
    }

	free(ligne);
}

void afficheWinners(Gagnants *listeGagnants){
	for(int i = 0 ; i < listeGagnants->nombreGagnants; i++){
		printf("annee : %d \n", listeGagnants->gagnants[i].annee);
		printf("nom : %s \n", listeGagnants->gagnants[i].nom);
		printf("sujet : %s \n", listeGagnants->gagnants[i].sujet);
		printf("\n");
	}
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

    FILE *dataFile, *outputFile;

	dataFile = fopen(filename,"r"); 
	outputFile = fopen(outputFilename,"w"); 
	
	printf("nombre de gagnants : %d \n",numberOfWinners(dataFile));

	//readWinners
	Gagnants listeGagnants;
	readWinners(dataFile, &listeGagnants);

	//afficheWinners(&listeGagnants);
	printWinners(outputFile, &listeGagnants);

	fclose(dataFile); 
	fclose(outputFile); 

	free(listeGagnants.gagnants);

	return EXIT_SUCCESS;
}
