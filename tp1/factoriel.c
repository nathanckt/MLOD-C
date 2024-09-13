#include <stdio.h>

typedef unsigned long long TypeEntier;
TypeEntier factorielle(TypeEntier n){
    TypeEntier resultat = 1;

    for(TypeEntier i = 1; i <= n; i++){
        resultat *= i;
    }

    return resultat;
}; 

int main(void) {
    TypeEntier resutlat = 0;
    resutlat = factorielle(10);
    printf("%llu",resutlat);
}


