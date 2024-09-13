#include <stdio.h>

int nbrParfait (int x){
    int sommeDiviseurs = 0;
    for(int i = 0; i < x; i++){
        if (x%i == 0){
            sommeDiviseurs += i;
        }
    }

    if (sommeDiviseurs == x){
        return 1;
    }
    else{
        return 0;
    }
}

void afficheNombresParfaits (int max){
    for(int i = 0; i < max; i++){
        if (nbrParfait(i)){
            printf("%i \n", i);
        }
    }
}

int main(void){
    int max;
    scanf("%i", &max);
    afficheNombresParfaits(max);
}