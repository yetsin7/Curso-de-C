/*
 * Modulo 08 -- Dobles punteros
 * Compilar: gcc -Wall -Wextra -std=c11 -o 04_dobles 04_dobles_punteros.c
 *
 * Demuestra:
 *   - Concepto de puntero a puntero
 *   - Preparacion para arreglos 2D dinamicos
 *   - Modificacion de direcciones de punteros
 */

#include <stdio.h>
#include <stdlib.h>

/* Modifica la direccion a la que apunta un puntero */
void reasignarPuntero(int **ptr, int *nuevaDireccion) {
    *ptr = nuevaDireccion;  /* Cambia la direccion almacenada en ptr */
}

int main(void) {
    /* -----------------------------------------------
     * 1. Concepto de puntero a puntero
     * ----------------------------------------------- */
    printf("=== PUNTERO A PUNTERO ===\n");

    int valor = 42;
    int *ptr = &valor;     /* Un nivel de indireccion */
    int **doble = &ptr;    /* Dos niveles de indireccion */

    printf("valor     = %d\n", valor);
    printf("ptr       = %p  (direccion de valor)\n", (void *)ptr);
    printf("*ptr      = %d  (valor de la variable)\n", *ptr);
    printf("doble     = %p  (direccion de ptr)\n", (void *)doble);
    printf("*doble    = %p  (mismo que ptr)\n", (void *)*doble);
    printf("**doble   = %d  (mismo que valor)\n", **doble);

    /* Modificar a traves del doble puntero */
    **doble = 99;
    printf("Despues de **doble = 99: valor = %d\n", valor);

    /* -----------------------------------------------
     * 2. Modificacion de direcciones de punteros
     * ----------------------------------------------- */
    printf("\n=== MODIFICAR DIRECCIONES ===\n");

    int a = 100, b = 200;
    int *selector = &a;

    printf("Antes: selector apunta a %d\n", *selector);
    reasignarPuntero(&selector, &b);
    printf("Despues: selector apunta a %d\n", *selector);

    /* -----------------------------------------------
     * 3. Preparacion para arreglo 2D dinamico
     * ----------------------------------------------- */
    printf("\n=== PREPARACION ARREGLO 2D ===\n");

    int filas = 3, columnas = 4;

    /* Allocar arreglo de punteros (una fila de punteros) */
    int **matriz = malloc(filas * sizeof(int *));
    if (matriz == NULL) {
        printf("Error de memoria\n");
        return 1;
    }

    /* Allocar cada fila */
    for (int i = 0; i < filas; i++) {
        matriz[i] = malloc(columnas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Error de memoria en fila %d\n", i);
            return 1;
        }
    }

    /* Llenar la matriz */
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i * columnas + j + 1;
        }
    }

    /* Imprimir la matriz */
    printf("Matriz %dx%d:\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("  %2d", matriz[i][j]);
        }
        printf("\n");
    }

    /* Acceder a un elemento con doble desreferencia */
    printf("Elemento [1][2] via punteros: %d\n", *(*(matriz + 1) + 2));

    /* Liberar memoria en orden inverso */
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
