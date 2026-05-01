/*
 * Modulo 11 -- Memoria Dinamica
 * Archivo: 02_calloc_y_realloc.c
 *
 * Demuestra calloc y realloc:
 *   - calloc vs malloc (inicializacion en cero)
 *   - realloc para redimensionar bloques
 *   - Patron seguro de realloc con puntero temporal
 *   - Arreglo dinamico que crece progresivamente
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 02_calloc_y_realloc 02_calloc_y_realloc.c
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    /* --- calloc vs malloc --- */
    printf("=== calloc vs malloc ===\n");

    /* malloc reserva pero NO inicializa (valores indeterminados) */
    int *con_malloc = malloc(5 * sizeof(int));
    printf("malloc (sin inicializar): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", con_malloc[i]);
    }
    printf("\n");
    free(con_malloc);

    /* calloc reserva E inicializa todos los bytes a cero */
    int *con_calloc = calloc(5, sizeof(int));
    printf("calloc (inicializado a cero): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", con_calloc[i]);
    }
    printf("\n");
    free(con_calloc);

    /* --- realloc basico --- */
    printf("\n=== realloc basico ===\n");

    /* Empezar con 3 elementos */
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

    /* Redimensionar a 6 elementos usando patron seguro */
    int nuevaCapacidad = 6;
    /* Usar puntero temporal: si realloc falla, datos sigue valido */
    int *temporal = realloc(datos, nuevaCapacidad * sizeof(int));

    if (temporal == NULL) {
        fprintf(stderr, "Error: realloc fallo\n");
        free(datos);
        return 1;
    }

    /* Solo actualizar el puntero original si tuvo exito */
    datos = temporal;

    /* Agregar nuevos elementos */
    datos[3] = 40;
    datos[4] = 50;
    datos[5] = 60;

    printf("Redimensionado (%d elementos): ", nuevaCapacidad);
    for (int i = 0; i < nuevaCapacidad; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");

    free(datos);

    /* --- Arreglo que crece dinamicamente --- */
    printf("\n=== Arreglo que crece ===\n");

    int tamano = 0;
    int capacidadActual = 2;
    int *arreglo = calloc(capacidadActual, sizeof(int));

    if (arreglo == NULL) {
        fprintf(stderr, "Error: calloc fallo\n");
        return 1;
    }

    /* Agregar 8 elementos, creciendo cuando sea necesario */
    for (int i = 1; i <= 8; i++) {
        /* Si no hay espacio, duplicar capacidad */
        if (tamano >= capacidadActual) {
            capacidadActual *= 2;
            int *temp = realloc(arreglo, capacidadActual * sizeof(int));

            if (temp == NULL) {
                fprintf(stderr, "Error: no se pudo expandir\n");
                free(arreglo);
                return 1;
            }
            arreglo = temp;
            printf("  Capacidad expandida a: %d\n", capacidadActual);
        }

        arreglo[tamano] = i * i;  /* guardar cuadrados: 1, 4, 9, 16... */
        tamano++;
    }

    printf("Arreglo final (%d elementos): ", tamano);
    for (int i = 0; i < tamano; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    free(arreglo);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
