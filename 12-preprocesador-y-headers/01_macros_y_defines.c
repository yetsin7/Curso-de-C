/*
 * ============================================================
 * Modulo 12 -- Preprocesador y Headers
 * Archivo: 01_macros_y_defines.c
 * ============================================================
 *
 * Este archivo explica macros y constantes con #define.
 *
 * El preprocesador trabaja antes que el compilador. Una de sus tareas es
 * reemplazar texto. Por ejemplo, si defines PI como 3.14159, el
 * preprocesador reemplaza PI por ese valor antes de compilar.
 *
 * Las macros pueden ser utiles, pero deben escribirse con cuidado porque
 * no funcionan igual que una funcion normal.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 01_macros 01_macros_y_defines.c
 *
 * Ejecutar:
 *   Windows: 01_macros.exe
 *   Linux/macOS: ./01_macros
 */

#include <stdio.h>

/*
 * Constantes con #define.
 *
 * Esto no crea variables. Es sustitucion textual antes de compilar.
 */
#define PI        3.14159265358979
#define MAX_ITEMS 50
#define AUTOR     "Curso de C"

/*
 * Macros funcionales.
 *
 * Los parentesis son fundamentales para evitar errores de precedencia.
 */
#define SQUARE(x)   ((x) * (x))
#define ABSOLUTO(n) ((n) < 0 ? -(n) : (n))

/*
 * Macro multilinea.
 *
 * El patron do-while(0) hace que la macro se comporte como una sola
 * instruccion cuando se usa en un if, while u otro bloque.
 */
#define SALUDAR(nombre) \
    do { \
        printf("Hola, %s!\n", (nombre)); \
    } while (0)

/*
 * #undef elimina una macro definida previamente.
 */
#define TEMPORAL 42
#undef TEMPORAL

int main(void) {
    printf("=== CONSTANTES CON #define ===\n");
    printf("Autor: %s\n", AUTOR);
    printf("Pi: %.6f\n", PI);
    printf("Maximo de items: %d\n", MAX_ITEMS);

    printf("\n=== MACROS FUNCIONALES ===\n");
    printf("SQUARE(5)   = %d\n", SQUARE(5));
    printf("SQUARE(2+3) = %d\n", SQUARE(2 + 3));
    printf("ABSOLUTO(-7) = %d\n", ABSOLUTO(-7));
    printf("ABSOLUTO(7)  = %d\n", ABSOLUTO(7));

    printf("\n=== MACRO MULTILINEA ===\n");
    SALUDAR("Programador");

    printf("\n=== IMPORTANCIA DE LOS PARENTESIS ===\n");
    printf("Sin parentesis, una macro puede producir resultados inesperados.\n");
    printf("Con parentesis: SQUARE(2+3) = %d\n", SQUARE(2 + 3));

    printf("\n=== MACROS PREDEFINIDAS ===\n");
    printf("Archivo: %s\n", __FILE__);
    printf("Linea:   %d\n", __LINE__);
    printf("Fecha:   %s\n", __DATE__);
    printf("Hora:    %s\n", __TIME__);

    printf("\n=== #undef ===\n");
    printf("La macro TEMPORAL fue eliminada con #undef.\n");
    printf("Despues de eliminarla, ya no se puede usar.\n");

    return 0;
}
