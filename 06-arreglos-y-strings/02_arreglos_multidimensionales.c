/*
 * Modulo 06 -- Arreglos y Strings
 * Archivo: 02_arreglos_multidimensionales.c
 *
 * Demuestra arreglos de dos dimensiones (matrices):
 *   - Declaracion de matrices
 *   - Recorrido con bucles anidados
 *   - Operaciones con matrices (suma, multiplicacion)
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 02_arreglos_multidimensionales 02_arreglos_multidimensionales.c
 */

#include <stdio.h>

#define FILAS 3
#define COLS 3

/* Imprime una matriz con formato de tabla */
void imprimirMatriz(int mat[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++) {
        printf("  [");
        for (int j = 0; j < COLS; j++) {
            printf("%3d", mat[i][j]);
            if (j < COLS - 1) printf(",");
        }
        printf(" ]\n");
    }
}

/* Suma dos matrices y almacena el resultado en una tercera */
void sumarMatrices(int a[FILAS][COLS], int b[FILAS][COLS], int resultado[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultado[i][j] = a[i][j] + b[i][j];
        }
    }
}

/* Multiplica dos matrices 3x3 y almacena el resultado */
void multiplicarMatrices(int a[FILAS][COLS], int b[FILAS][COLS], int resultado[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                resultado[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(void) {

    /* --- Declaracion de matrices --- */
    printf("=== DECLARACION DE MATRICES ===\n");

    int tabla[FILAS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Matriz original:\n");
    imprimirMatriz(tabla);

    /* --- Acceso a elementos --- */
    printf("\n=== ACCESO A ELEMENTOS ===\n");

    printf("Elemento en [0][0]: %d\n", tabla[0][0]);
    printf("Elemento en [1][2]: %d\n", tabla[1][2]);
    printf("Elemento en [2][2]: %d\n", tabla[2][2]);

    /* --- Recorrido con bucles anidados --- */
    printf("\n=== RECORRIDO CON BUCLES ANIDADOS ===\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("  tabla[%d][%d] = %d\n", i, j, tabla[i][j]);
        }
    }

    /* --- Suma de matrices --- */
    printf("\n=== SUMA DE MATRICES ===\n");

    int matrizA[FILAS][COLS] = {
        {1, 0, 2},
        {3, 1, 0},
        {0, 2, 1}
    };

    int matrizB[FILAS][COLS] = {
        {2, 1, 0},
        {0, 3, 1},
        {1, 0, 2}
    };

    int suma[FILAS][COLS];

    printf("Matriz A:\n");
    imprimirMatriz(matrizA);

    printf("Matriz B:\n");
    imprimirMatriz(matrizB);

    sumarMatrices(matrizA, matrizB, suma);

    printf("A + B:\n");
    imprimirMatriz(suma);

    /* --- Multiplicacion de matrices --- */
    printf("\n=== MULTIPLICACION DE MATRICES ===\n");

    int producto[FILAS][COLS];
    multiplicarMatrices(matrizA, matrizB, producto);

    printf("A x B:\n");
    imprimirMatriz(producto);

    return 0;
}
