// gcc -W -Wall -std=c99 linkedListOfMusic.c mySpitofy.c -o mySpitofy
// gcc -W -Wall -fsanitize=address -g -std=c99 linkedListOfMusic.c mySpitofy.c -o mySpitofy
// gcc -W -Wall -Wno-unused-parameter -std=c99 linkedListOfMusic.c mySpitofy.c -o mySpitofy

#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void afficheElement(Element v){
    if(v == NULL){
        return;
    }
    printf("\n");
    printf("name : %s \n", v->name);
    printf("artist : %s \n", v->artist);
    printf("album : %s \n", v->album);
    printf("genre : %s \n", v->genre);
    printf("Disc Number : %d \n", v->discNumber);
    printf("Track Number : %d \n", v->trackNumber);
    printf("Year : %d \n", v->year);
}

void detruireElement(Element v){
    //TODO
}

bool equalsElement(Element e1, Element e2){

}


void readMusic(char *filename, Liste l){
    FILE *dataFile = fopen(filename,"r");

    int maxline = 2048;
    char *ligne;
    ligne = malloc(maxline * sizeof(char));

    while(fgets(ligne, maxline, dataFile) != NULL) {
        Element newElement;
        newElement = malloc(sizeof(struct music_s));
		if(strcmp(ligne, "\n") != 0){
			char *token;

			token = strtok(ligne, ",");
			newElement->name = strdup(token);
            
            token = strtok(NULL, ",");
			newElement->artist = strdup(token);

            token = strtok(NULL, ",");
			newElement->album = strdup(token);

            token = strtok(NULL, ",");
			newElement->genre = strdup(token);

            token = strtok(NULL, ",");
			newElement->discNumber = atoi(token);

            token = strtok(NULL, ",");
			newElement->trackNumber = atoi(token);

            token = strtok(NULL, "\n");
			newElement->year = atoi(token);

            ajoutFin_i(newElement, l);

		}
    }
    free(ligne);
}

int main(void){
    char *dataFile;
    dataFile = "music.csv";

    //Test Affichage Struct

    Element chanson;
    chanson = malloc(sizeof(struct music_s));
    chanson->name = "Yolo";
    chanson->album = "Super Album";
    chanson->artist = "Mec super";
    chanson->discNumber = 12;
    chanson->trackNumber = 2;
    chanson->year = 2012;
    chanson->genre = "Pop";

    afficheElement(chanson);
    free(chanson);

    Liste l;
    l = NULL;
    readMusic(dataFile,l);
    afficheListe_i(l);
    return 0;
}

