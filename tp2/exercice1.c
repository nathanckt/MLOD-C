#include <stdio.h>

void echangeContenu (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int a = 20;
    int b = 10;
    echangeContenu(&a,&b);
    printf("a : %i et b : %i",a,b);
}