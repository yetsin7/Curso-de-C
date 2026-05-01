/*
 * Modulo 11 -- Memoria Dinamica
 * Archivo: 01_malloc_y_free.c
 *
 * Demuestra los fundamentos de malloc y free:
 *   - Reserva de memoria con malloc
 *   - Uso de sizeof para calcular bytes correctamente
 *   - Verificacion de NULL despues de malloc
 *   - Liberacion con free y asignacion a NULL
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 01_malloc_y_free 01_malloc_y_free.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    /* --- malloc basico --- */
    printf("=== malloc basico ===\n");

    /* Reservar espacio para un solo entero */
    int *num = malloc(sizeof(int));

    /* Siempre verificar si malloc devolvio NULL */
    if (num == NULL) {
        fprintf(stderr, "Error: no se pudo reservar memoria\n");
        return 1;
    }

    *num = 42;
    printf("Valor: %d\n", *num);

    /* Liberar y asignar NULL para evitar dangling pointer */
    free(num);
    num = NULL;

    /* --- malloc para arreglo --- */
    printf("\n=== malloc para arreglo ===\n");

    int cantidad = 5;
    /* Usar sizeof(int) para calcular el tamaño correcto en bytes */
    int *arreglo = malloc(cantidad * sizeof(int));

    if (arreglo == NULL) {
        fprintf(stderr, "Error: no se pudo reservar memoria\n");
        return 1;
    }

    /* malloc NO inicializa la memoria, contiene valores indeterminados */
    for (int i = 0; i < cantidad; i++) {
        arreglo[i] = (i + 1) * 10;
    }

    printf("Arreglo: ");
    for (int i = 0; i < cantidad; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    free(arreglo);
    arreglo = NULL;

    /* --- malloc para string --- */
    printf("\n=== malloc para string ===\n");

    const char *texto = "Hola C";
    /* +1 para el caracter nulo '\0' */
    size_t longitud = strlen(texto) + 1;

    char *copia = malloc(longitud * sizeof(char));

    if (copia == NULL) {
        fprintf(stderr, "Error: no se pudo reservar memoria\n");
        return 1;
    }

    strcpy(copia, texto);
    printf("Copia: \"%s\"\n", copia);

    free(copia);
    copia = NULL;

    /* --- Demostracion de dangling pointer (evitar en produccion) --- */
    printf("\n=== Importancia de NULL despues de free ===\n");

    int *ptr = malloc(sizeof(int));
    *ptr = 100;
    printf("Antes de free: %d\n", *ptr);

    free(ptr);
    ptr = NULL;  /* Sin esta linea, ptr seria un dangling pointer */

    /* Verificar que el puntero es NULL antes de usarlo */
    if (ptr == NULL) {
        printf("Puntero es NULL, uso seguro prevenido\n");
    }

    printf("\nMemoria liberada correctamente.\n");
    return 0;
}
