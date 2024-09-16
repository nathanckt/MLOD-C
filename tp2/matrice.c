#include <stdio.h>
#include <stdint.h>

#define SIZE 5

// Fonction pour multiplier deux matrices
void matrix_mult(int64_t result[SIZE][SIZE], int64_t mat1[SIZE][SIZE], int64_t mat2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0; // Initialiser l'élément de la matrice résultat à 0
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Fonction pour afficher une matrice
void matrix_print(int64_t matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%lld ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    // Matrices initialisées
    int64_t matrice1[SIZE][SIZE] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    int64_t matrice2[SIZE][SIZE] = {{6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}};
    int64_t matriceResultat[SIZE][SIZE];

    // Appel des fonctions
    matrix_mult(matriceResultat, matrice1, matrice2);
    matrix_print(matriceResultat);

    // return EXIT_SUCCESS;
}

void matrix_mult_general(int rows1, int cols1, int cols2, int64_t result[rows1][cols2], int64_t mat1[rows1][cols1], int64_t mat2[cols1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void matrix_print_general(int rows, int cols, int64_t matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lld ", matrix[i][j]);
        }
        printf("\n");
    }
}
