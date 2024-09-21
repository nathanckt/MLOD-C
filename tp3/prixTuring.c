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

void infosAnnee(Gagnants *listeGagnants, unsigned int annee){
	for(int i = 0 ; i < listeGagnants->nombreGagnants ; i++){
		if(listeGagnants->gagnants[i].annee == annee){
			printf("L'annee %d, le(s) gagnant(s) ont été : %s \nNature des travaux : %s",annee, listeGagnants->gagnants[i].nom, listeGagnants->gagnants[i].sujet);
		}
	}
}


unsigned int cherchePremiereAnnee(Gagnants *listeGagnants){
	unsigned int res = listeGagnants->gagnants[0].annee;
	for(int i = 1 ; i < listeGagnants->nombreGagnants ; i++){
		if (res > listeGagnants->gagnants[i].annee){
			res = listeGagnants->gagnants[i].annee;
		}
	}
	return res;
}
void afficheWinners(Gagnants *listeGagnants){
	for(int i = 0 ; i < listeGagnants->nombreGagnants; i++){
		printf("annee : %d \n", listeGagnants->gagnants[i].annee);
		printf("nom : %s \n", listeGagnants->gagnants[i].nom);
		printf("sujet : %s \n", listeGagnants->gagnants[i].sujet);
		printf("\n");
	}
}
void sortTuringWinnersByYear(Gagnants *listeGagnants){
	unsigned int anneeEnCours = cherchePremiereAnnee(listeGagnants);
	printf("annee = %d \n",anneeEnCours);
	Gagnants tempG;
	Gagnants *temp = &tempG;
	temp->nombreGagnants = listeGagnants->nombreGagnants;
	temp->gagnants = malloc((temp->nombreGagnants)*sizeof(Gagnant));

	for(int i = 0 ; i < listeGagnants->nombreGagnants ; i++){
		for(int j = 0 ; j < listeGagnants->nombreGagnants ; j++){
			if(listeGagnants->gagnants[j].annee == (anneeEnCours+i)){
				temp->gagnants[i].annee = listeGagnants->gagnants[j].annee;
				temp->gagnants[i].nom = listeGagnants->gagnants[j].nom;
				temp->gagnants[i].sujet = listeGagnants->gagnants[j].sujet;
			}
		}
	}

	//Copie du temp dans la liste gagnants initiale
	for(int j = 0 ; j < listeGagnants->nombreGagnants ; j++){
			listeGagnants->gagnants[j].annee = temp->gagnants[j].annee;
			listeGagnants->gagnants[j].nom = temp->gagnants[j].nom;
			listeGagnants->gagnants[j].sujet = listeGagnants->gagnants[j].sujet;
		}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
    char *filename = NULL;
    char *outputFilename = NULL;
    int annee = -1; 
    int sort = 0; 

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 < argc) {
                outputFilename = argv[++i];  
            } else {
                fprintf(stderr, "L'option -o nécessite un nom de fichier.\n");
                return EXIT_FAILURE;
            }
        } else if (strcmp(argv[i], "--info") == 0) {
            if (i + 1 < argc) {
                annee = atoi(argv[++i]);  
            } else {
                fprintf(stderr, "L'option --info nécessite une année.\n");
                return EXIT_FAILURE;
            }
        } else if (strcmp(argv[i], "--sort") == 0) {
            sort = 1;  
        } else {
            filename = argv[i];  
        }
    }

    if (filename == NULL) {
        fprintf(stderr, "Aucun fichier d'entrée spécifié.\n");
        return EXIT_FAILURE;
    }

    FILE *dataFile = fopen(filename, "r");
    if (dataFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return EXIT_FAILURE;
    }

    Gagnants listeGagnants;
    readWinners(dataFile, &listeGagnants);
    fclose(dataFile);

    if (annee != -1) {
        infosAnnee(&listeGagnants, annee);  
    }

    if (sort == 1) {
        sortTuringWinnersByYear(&listeGagnants);
    }

    if (outputFilename != NULL) {
        FILE *outputFile = fopen(outputFilename, "w");
        if (outputFile == NULL) {
            perror("Erreur lors de l'ouverture du fichier de sortie");
            free(listeGagnants.gagnants); 
            return EXIT_FAILURE;
        }

        printWinners(outputFile, &listeGagnants);  
        fclose(outputFile);  
    }

    free(listeGagnants.gagnants);

    return EXIT_SUCCESS;
}
