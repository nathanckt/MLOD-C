#include <stdio.h>
#include <stdlib.h>

enum Mois {jan = 1, fev, mars, avr, mai, juin, juil, aout, sept, oct, nov, dec};

struct Date{
    int jour; 
    enum Mois mois; 
    int annee;
};

void initialiseDate(struct Date *d){
    int j, a;
    enum Mois m;
    printf("Entrer le jour : ");
    scanf("%d", &j);
    int mois;
    printf("Entrer le mois (1-12) : ");
    scanf("%d", &mois);
    m = (enum Mois)mois;

    printf("Entrer l'année : ");
    scanf("%d", &a);

    d->jour = j;
    d->mois = m;
    d->annee = a;
}

void afficheDate(struct Date *d){
    printf("%d", d->jour);
    printf("/");

    printf("%u", d->mois);
    printf("/");

    printf("%d", d->annee);
}

struct Date creerDateParCopie(){
    int j, a;
    printf("Entrer le jour : ");
    scanf("%d", &j);

    enum Mois m;
    int mois;
    printf("Entrer le mois (1-12) : ");
    scanf("%d", &mois);
    m = (enum Mois)mois;

    printf("Entrer l'année : ");
    scanf("%d", &a);

    struct Date d; 

    d.jour = j;
    d.mois = m;
    d.annee = a;

    return d;
}

struct Date *newDate(){
    int j, a;
    printf("Entrer le jour : ");
    scanf("%d", &j);

    enum Mois m;
    int mois;
    printf("Entrer le mois (1-12) : ");
    scanf("%d", &mois);
    m = (enum Mois)mois;

    printf("Entrer l'année : ");
    scanf("%d", &a);

    struct Date *d = (struct Date*)malloc(sizeof(struct Date)); 

    d->jour = j;
    d->mois = m;
    d->annee = a;

    return d;
}

int main (void){
    struct Date *date;
    date = newDate();
    afficheDate(date);
    //...
    free(date);  
}

