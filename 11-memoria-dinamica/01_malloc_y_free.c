/*
 * ============================================================
 * Modulo 11 -- Memoria Dinamica
 * Archivo: 01_malloc_y_free.c
 * ============================================================
 *
 * Este archivo explica los fundamentos de malloc y free.
 *
 * En C existen diferentes zonas de memoria. Dos de las mas importantes son:
 *
 *   stack:
 *     Memoria automatica usada por variables locales normales.
 *
 *   heap:
 *     Memoria que el programador reserva manualmente durante la ejecucion.
 *
 * La memoria dinamica vive en el heap. Se usa cuando no sabemos de antemano
 * cuanta memoria necesitaremos o cuando queremos que los datos duren mas alla
 * del bloque donde fueron creados.
 *
 * Conceptos importantes:
 *
 *   malloc  reserva memoria, pero no la inicializa.
 *   sizeof  ayuda a calcular cuantos bytes se necesitan.
 *   free    libera memoria reservada con malloc.
 *   NULL    indica que un puntero no apunta a memoria valida.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 01_malloc_y_free 01_malloc_y_free.c
 *
 * Ejecutar:
 *   Windows: 01_malloc_y_free.exe
 *   Linux/macOS: ./01_malloc_y_free
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("=== MALLOC BASICO ===\n");

    /*
     * Reservar espacio para un solo entero.
     *
     * malloc devuelve un puntero a la memoria reservada.
     */
    int *num = malloc(sizeof(int));

    if (num == NULL) {
        fprintf(stderr, "Error: no se pudo reservar memoria\n");
        return 1;
    }

    *num = 42;
    printf("Valor guardado en memoria dinamica: %d\n", *num);

    /*
     * Toda memoria reservada con malloc debe liberarse con free.
     */
    free(num);
    num = NULL;

    printf("\n=== MALLOC PARA ARREGLO ===\n");

    int cantidad = 5;
    int *arreglo = malloc(cantidad * sizeof(int));

    if (arreglo == NULL) {
        fprintf(stderr, "Error: no se pudo reservar memoria para el arreglo\n");
        return 1;
    }

    /*
     * malloc no inicializa la memoria. Por eso llenamos el arreglo antes
     * de leer sus valores.
     */
    for (int i = 0; i < cantidad; i++) {
        arreglo[i] = (i + 1) * 10;
    }

    printf("Arreglo dinamico: ");

    for (int i = 0; i < cantidad; i++) {
        printf("%d ", arreglo[i]);
    }

    printf("\n");

    free(arreglo);
    arreglo = NULL;

    printf("\n=== MALLOC PARA STRING ===\n");

    const char *texto = "Hola C";

    /*
     * Sumamos 1 para guardar tambien el caracter nulo '\0'.
     */
    size_t longitud = strlen(texto) + 1;
    char *copia = malloc(longitud * sizeof(char));

    if (copia == NULL) {
        fprintf(stderr, "Error: no se pudo reservar memoria para el string\n");
        return 1;
    }

    strcpy(copia, texto);
    printf("Copia dinamica: \"%s\"\n", copia);

    free(copia);
    copia = NULL;

    printf("\n=== IMPORTANCIA DE NULL DESPUES DE FREE ===\n");

    int *ptr = malloc(sizeof(int));

    if (ptr == NULL) {
        fprintf(stderr, "Error: no se pudo reservar memoria\n");
        return 1;
    }

    *ptr = 100;
    printf("Antes de free: %d\n", *ptr);

    free(ptr);

    /*
     * Despues de free, el puntero conserva la direccion vieja.
     * Para evitar usarlo por accidente, lo asignamos a NULL.
     */
    ptr = NULL;

    if (ptr == NULL) {
        printf("Puntero asignado a NULL. Uso peligroso prevenido.\n");
    }

    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
