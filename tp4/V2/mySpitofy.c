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


Liste readMusic(char *filename, Liste l){
    FILE *dataFile = fopen(filename,"r");

    int maxline = 2048;
    char *ligne;
    ligne = malloc(maxline * sizeof(char));
    fgets(ligne, maxline, dataFile); // Passe la première ligne

    while(fgets(ligne, maxline, dataFile) != NULL) {
        Element newElement;
        newElement = malloc(sizeof(struct music_s));
		if(strcmp(ligne, "\n") != 0){
			char *token;

			token = strtok(ligne, ",");
            if (token != NULL) newElement->name = strdup(token);

            token = strtok(NULL, ",");
            if (token != NULL) newElement->artist = strdup(token);

            token = strtok(NULL, ",");
            if (token != NULL) newElement->album = strdup(token);

            token = strtok(NULL, ",");
            if (token != NULL) newElement->genre = strdup(token);

            token = strtok(NULL, ",");
            if (token != NULL) newElement->discNumber = atoi(token);

            token = strtok(NULL, ",");
            if (token != NULL) newElement->trackNumber = atoi(token);

            token = strtok(NULL, "\n");
            if (token != NULL) newElement->year = atoi(token);

            l = ajoutFin_i(newElement, l);

		}
    }
    free(ligne);
    return l;
}

int main(void){
    char *dataFile;
    dataFile = "music.csv";

    Liste l;
    l = NULL;
    l = readMusic(dataFile,l);
    afficheListe_i(l);
    return 0;
}

