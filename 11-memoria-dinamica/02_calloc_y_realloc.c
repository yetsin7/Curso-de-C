/*
 * ============================================================
 * Modulo 11 -- Memoria Dinamica
 * Archivo: 02_calloc_y_realloc.c
 * ============================================================
 *
 * Este archivo explica calloc y realloc.
 *
 * calloc:
 *   Reserva memoria y la inicializa en cero.
 *
 * realloc:
 *   Cambia el tamano de un bloque de memoria reservado previamente.
 *
 * Diferencia rapida:
 *
 *   malloc reserva memoria, pero no limpia su contenido.
 *   calloc reserva memoria y deja todo inicializado en cero.
 *   realloc intenta agrandar o reducir un bloque existente.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 02_calloc_y_realloc 02_calloc_y_realloc.c
 *
 * Ejecutar:
 *   Windows: 02_calloc_y_realloc.exe
 *   Linux/macOS: ./02_calloc_y_realloc
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("=== CALLOC ===\n");

    /*
     * calloc recibe dos argumentos:
     *
     *   cantidad de elementos
     *   tamano de cada elemento
     *
     * El resultado queda inicializado en cero.
     */
    int *con_calloc = calloc(5, sizeof(int));

    if (con_calloc == NULL) {
        fprintf(stderr, "Error: calloc fallo\n");
        return 1;
    }

    printf("calloc inicializado a cero: ");

    for (int i = 0; i < 5; i++) {
        printf("%d ", con_calloc[i]);
    }

    printf("\n");
    free(con_calloc);
    con_calloc = NULL;

    printf("\n=== REALLOC BASICO ===\n");

    int capacidad = 3;
    int *datos = malloc(capacidad * sizeof(int));

    if (datos == NULL) {
        fprintf(stderr, "Error: malloc fallo\n");
        return 1;
    }

    datos[0] = 10;
    datos[1] = 20;
    datos[2] = 30;

    printf("Original (%d elementos): ", capacidad);

    for (int i = 0; i < capacidad; i++) {
        printf("%d ", datos[i]);
    }

    printf("\n");

    /*
     * Patron seguro con realloc:
     *
     * No se debe asignar directamente asi:
     *
     *   datos = realloc(datos, nuevo_tamano);
     *
     * Si realloc falla, perderiamos la direccion original.
     * Por eso usamos un puntero temporal.
     */
    int nuevaCapacidad = 6;
    int *temporal = realloc(datos, nuevaCapacidad * sizeof(int));

    if (temporal == NULL) {
        fprintf(stderr, "Error: realloc fallo\n");
        free(datos);
        return 1;
    }

    datos = temporal;

    datos[3] = 40;
    datos[4] = 50;
    datos[5] = 60;

    printf("Redimensionado (%d elementos): ", nuevaCapacidad);

    for (int i = 0; i < nuevaCapacidad; i++) {
        printf("%d ", datos[i]);
    }

    printf("\n");

    free(datos);
    datos = NULL;

    printf("\n=== ARREGLO QUE CRECE DINAMICAMENTE ===\n");

    int tamano = 0;
    int capacidadActual = 2;
    int *arreglo = calloc(capacidadActual, sizeof(int));

    if (arreglo == NULL) {
        fprintf(stderr, "Error: calloc fallo\n");
        return 1;
    }

    /*
     * Agregamos 8 elementos.
     * Cuando el arreglo se llena, duplicamos su capacidad con realloc.
     */
    for (int i = 1; i <= 8; i++) {
        if (tamano >= capacidadActual) {
            capacidadActual *= 2;

            int *temp = realloc(arreglo, capacidadActual * sizeof(int));

            if (temp == NULL) {
                fprintf(stderr, "Error: no se pudo expandir el arreglo\n");
                free(arreglo);
                return 1;
            }

            arreglo = temp;
            printf("Capacidad expandida a: %d\n", capacidadActual);
        }

        arreglo[tamano] = i * i;
        tamano++;
    }

    printf("Arreglo final (%d elementos): ", tamano);

    for (int i = 0; i < tamano; i++) {
        printf("%d ", arreglo[i]);
    }

    printf("\n");

    free(arreglo);
    arreglo = NULL;

    printf("Memoria liberada correctamente.\n");

    return 0;
}
