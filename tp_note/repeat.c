#include <stdio.h>
#include <stdlib.h>

int* repeat(int *t1, int *t2, int taille, int tailleFinale){

    int *tab;
    tab = malloc(tailleFinale*sizeof(int));
    int compteur = 0;


    for(int i = 0 ; i < taille ; i++){
        for(int j = 0 ; j < t1[i] ; j++){
            tab[compteur] = t2[i];
            compteur++;
        }
    }

    return tab;
}

void afficheTab(int *tab, int taille){
    printf("(");
    for(int i = 0 ; i < taille ; i++){
        printf(" %d ", tab[i]);
    }
    printf(")");
}

int main(void){
    printf("Hello World\n");
    int tab1[] = {1,2,3,5};
    int tab2[] = {10,3,8,2};
    int taille = 4;
    int tailleFinale = 0;
    for(int i = 0 ; i < taille; i++){
        tailleFinale = tailleFinale + tab1[i];
    }
    int *resultat = repeat(tab1, tab2, taille, tailleFinale);
    afficheTab(resultat, tailleFinale);
    free(*resultat);
}