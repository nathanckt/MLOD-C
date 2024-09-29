// gcc -W -Wall -std=c99 linkedListOfMusic.c mySpitofy.c -o mySpitofy
// gcc -W -Wall -fsanitize=address -g -std=c99 linkedListOfMusic.c mySpitofy.c -o mySpitofy
// gcc -W -Wall -Wno-unused-parameter -std=c99 linkedListOfMusic.c mySpitofy.c -o mySpitofy

#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void afficheElement(Element v){
    printf("\n");
    printf("name : %s \n", v.name);
    printf("artist : %s \n", v.artist);
    printf("album : %s \n", v.album);
    printf("genre : %s \n", v.genre);
    printf("Disc Number : %d \n", v.discNumber);
    printf("Track Number : %d \n", v.trackNumber);
    printf("Year : %d \n", v.year);
}

void detruireElement(Element v){
    //TODO
}

int numberOfMusic(FILE *dataFile){
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

void readMusic(char *filename, Liste l){
    FILE *dataFile = fopen(filename,"r");

    int numbersOfMusic = numberOfMusic(dataFile), maxline = 2048, i = 0;
    char *ligne;
    ligne = malloc(maxline * sizeof(char));

    while(fgets(ligne, maxline, dataFile) != NULL) {
        Element newElement; //Problème avec la portée ?? 
		if(strcmp(ligne, "\n") != 0){
			char *token;

			token = strtok(ligne, ";");
			newElement.name = strdup(token);
            
            token = strtok(NULL, ";");
			newElement.artist = strdup(token);

            token = strtok(NULL, ";");
			newElement.album = strdup(token);

            token = strtok(NULL, ";");
			newElement.genre = strdup(token);

            token = strtok(NULL, ";");
			newElement.discNumber = atoi(token);

            token = strtok(NULL, ";");
			newElement.trackNumber = atoi(token);

            token = strtok(NULL, ";");
			newElement.year = atoi(token);

            ajoutFin_i(newElement, l);

			i++;
		}
    }
    free(ligne);
}

int main(void){
    char *dataFile;
    dataFile = "music.csv";

    Liste l;
    l = NULL;
    readMusic(dataFile,l);
    afficheListe_i(l);
}

