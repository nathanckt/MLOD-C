#include <stdio.h>
#include <stdlib.h>

typedef enum {jan = 1, fev, mars, avr, mai, juin, juil, aout, sept, oct, nov, dec} Mois;

typedef struct DateS{
    int jour; 
    Mois mois; 
    int annee;
} Date;

void initialiseDate(Date *d){
    int j, a;
    Mois m;
    printf("Entrer le jour : ");
    scanf("%d", &j);
    int mois;
    printf("Entrer le mois (1-12) : ");
    scanf("%d", &mois);
    m = (Mois)mois;

    printf("Entrer l'année : ");
    scanf("%d", &a);

    d->jour = j;
    d->mois = m;
    d->annee = a;
}

void afficheDate( Date *d){
    printf("%d", d->jour);
    printf("/");

    printf("%u", d->mois);
    printf("/");

    printf("%d", d->annee);
}

Date creerDateParCopie(){
    int j, a;
    printf("Entrer le jour : ");
    scanf("%d", &j);

    Mois m;
    int mois;
    printf("Entrer le mois (1-12) : ");
    scanf("%d", &mois);
    m = (Mois)mois;

    printf("Entrer l'année : ");
    scanf("%d", &a);

     Date d; 

    d.jour = j;
    d.mois = m;
    d.annee = a;

    return d;
}

Date *newDate(){
    Date *d = (Date*)malloc(sizeof(Date)); 
    printf("Entrer le jour : ");
    scanf("%d", &(d->jour));

    printf("Entrer le mois (1-12) : ");
    scanf("%d", (int *)&d->mois);

    printf("Entrer l'année : ");
    scanf("%d", &(d->annee));
    
    return d;
}

int main (void){
    Date *date;
    date = newDate();
    afficheDate(date);
    //...
    free(date);  
}

