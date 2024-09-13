#include <stdio.h>
#include <math.h>

int squareOfSum (int n){
    int somme = 0;
    for(int i = 0; i < n; i++){
        somme += i;
    }

    somme *= somme;

    return somme;
}


int sumOfSquare(int n){
    int somme = 0;
    for(int i = 0; i < n; i++){
        somme += pow(n,2);
    }

    return somme;
}

int main (void){
    int n;
    scanf("%i", &n);
    int difference = sumOfSquare(n) - squareOfSum(n);
    printf("\n %i \n", difference);
}