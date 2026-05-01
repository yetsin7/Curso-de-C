/*
 * ============================================================
 * Modulo 08 -- Punteros
 * Archivo: 04_dobles_punteros.c
 * ============================================================
 *
 * Este archivo explica los dobles punteros.
 *
 * Un doble puntero es un puntero que guarda la direccion de otro puntero.
 *
 * Ejemplo:
 *
 *   int valor = 42;
 *   int *ptr = &valor;
 *   int **doble = &ptr;
 *
 * Significado:
 *
 *   valor  guarda un numero.
 *   ptr    guarda la direccion de valor.
 *   doble  guarda la direccion de ptr.
 *
 * Los dobles punteros se usan para modificar punteros desde funciones,
 * trabajar con arreglos dinamicos de dos dimensiones y manejar estructuras
 * mas avanzadas.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 04_dobles 04_dobles_punteros.c
 *
 * Ejecutar:
 *   Windows: 04_dobles.exe
 *   Linux/macOS: ./04_dobles
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Esta funcion cambia la direccion a la que apunta un puntero.
 *
 * Para poder modificar el puntero original, necesitamos recibir la
 * direccion de ese puntero. Por eso usamos int **.
 */
void reasignarPuntero(int **ptr, int *nuevaDireccion) {
    *ptr = nuevaDireccion;
}

int main(void) {
    printf("=== PUNTERO A PUNTERO ===\n");

    int valor = 42;
    int *ptr = &valor;
    int **doble = &ptr;

    printf("valor   = %d\n", valor);
    printf("ptr     = %p\n", (void *)ptr);
    printf("*ptr    = %d\n", *ptr);
    printf("doble   = %p\n", (void *)doble);
    printf("*doble  = %p\n", (void *)*doble);
    printf("**doble = %d\n", **doble);

    /*
     * **doble llega hasta el valor original.
     */
    **doble = 99;
    printf("Despues de **doble = 99: valor = %d\n", valor);

    printf("\n=== MODIFICAR DIRECCIONES ===\n");

    int a = 100;
    int b = 200;
    int *selector = &a;

    printf("Antes: selector apunta a %d\n", *selector);

    reasignarPuntero(&selector, &b);

    printf("Despues: selector apunta a %d\n", *selector);

    printf("\n=== ARREGLO 2D DINAMICO ===\n");

    /*
     * Esta parte prepara una matriz dinamica.
     *
     * matriz es un doble puntero porque apunta a un arreglo de punteros.
     * Cada puntero representa una fila.
     */
    int filas = 3;
    int columnas = 4;

    int **matriz = malloc(filas * sizeof(int *));

    if (matriz == NULL) {
        printf("Error: no se pudo reservar memoria para las filas.\n");
        return 1;
    }

    for (int i = 0; i < filas; i++) {
        matriz[i] = malloc(columnas * sizeof(int));

        if (matriz[i] == NULL) {
            printf("Error: no se pudo reservar memoria para la fila %d.\n", i);

            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }

            free(matriz);
            return 1;
        }
    }

    /*
     * Llenar la matriz con valores consecutivos.
     */
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i * columnas + j + 1;
        }
    }

    printf("Matriz %dx%d:\n", filas, columnas);

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%3d", matriz[i][j]);
        }
        printf("\n");
    }

    /*
     * matriz[1][2] equivale a *(*(matriz + 1) + 2).
     */
    printf("Elemento [1][2] usando notacion normal: %d\n", matriz[1][2]);
    printf("Elemento [1][2] usando punteros:        %d\n", *(*(matriz + 1) + 2));

    /*
     * Liberar memoria.
     *
     * Primero se libera cada fila y al final el arreglo de punteros.
     */
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}
