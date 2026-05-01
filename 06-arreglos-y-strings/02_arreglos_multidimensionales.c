/*
 * ============================================================
 * Modulo 06 -- Arreglos y Strings
 * Archivo: 02_arreglos_multidimensionales.c
 * ============================================================
 *
 * Este archivo explica los arreglos multidimensionales en C.
 *
 * Un arreglo multidimensional es un arreglo con mas de un indice.
 * El caso mas comun es una matriz de dos dimensiones, parecida a una
 * tabla con filas y columnas.
 *
 * Ejemplo:
 *
 *   int matriz[3][3];
 *
 * Eso significa una matriz con 3 filas y 3 columnas.
 *
 * Para acceder a un elemento se usan dos indices:
 *
 *   matriz[fila][columna]
 *
 * Recuerda que en C los indices empiezan en 0.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 02_arreglos_multidimensionales 02_arreglos_multidimensionales.c
 *
 * Ejecutar:
 *   Windows: 02_arreglos_multidimensionales.exe
 *   Linux/macOS: ./02_arreglos_multidimensionales
 */

#include <stdio.h>

#define FILAS 3
#define COLS 3

/*
 * Imprime una matriz con formato de tabla.
 */
void imprimirMatriz(int mat[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++) {
        printf("  [");

        for (int j = 0; j < COLS; j++) {
            printf("%3d", mat[i][j]);

            if (j < COLS - 1) {
                printf(",");
            }
        }

        printf(" ]\n");
    }
}

/*
 * Suma dos matrices.
 *
 * Para sumar matrices, se suman los elementos que estan en la misma
 * posicion.
 */
void sumarMatrices(int a[FILAS][COLS], int b[FILAS][COLS], int resultado[FILAS][COLS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultado[i][j] = a[i][j] + b[i][j];
        }
    }
}

/*
 * Multiplica dos matrices 3x3.
 *
 * La multiplicacion de matrices requiere tres bucles:
 * - uno para recorrer filas
 * - uno para recorrer columnas
 * - uno para calcular la suma de productos
 */
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
    printf("=== ARREGLOS MULTIDIMENSIONALES ===\n\n");

    /*
     * Declaracion e inicializacion de una matriz 3x3.
     */
    int tabla[FILAS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Matriz original:\n");
    imprimirMatriz(tabla);

    /*
     * Acceso a elementos individuales.
     */
    printf("\n=== ACCESO A ELEMENTOS ===\n");
    printf("Elemento en [0][0]: %d\n", tabla[0][0]);
    printf("Elemento en [1][2]: %d\n", tabla[1][2]);
    printf("Elemento en [2][2]: %d\n", tabla[2][2]);

    /*
     * Recorrido con bucles anidados.
     */
    printf("\n=== RECORRIDO CON BUCLES ANIDADOS ===\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("tabla[%d][%d] = %d\n", i, j, tabla[i][j]);
        }
    }

    /*
     * Suma de matrices.
     */
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

    /*
     * Multiplicacion de matrices.
     */
    printf("\n=== MULTIPLICACION DE MATRICES ===\n");

    int producto[FILAS][COLS];
    multiplicarMatrices(matrizA, matrizB, producto);

    printf("A x B:\n");
    imprimirMatriz(producto);

    return 0;
}
