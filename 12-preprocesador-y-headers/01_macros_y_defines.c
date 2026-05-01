/*
 * 01_macros_y_defines.c -- Macros y defines en el preprocesador
 * Compilar: gcc -Wall -Wextra -std=c11 -o 01_macros 01_macros_y_defines.c
 *
 * Demuestra el uso de #define para constantes y macros funcionales,
 * la importancia de los parentesis y las macros predefinidas del compilador.
 */

#include <stdio.h>

/* Constantes con #define -- sustitucion textual antes de compilar */
#define PI        3.14159265358979
#define MAX_ITEMS 50
#define AUTOR     "Curso de C"

/* Macro funcional: los parentesis protegen contra errores de precedencia */
#define SQUARE(x)   ((x) * (x))
#define ABSOLUTO(n) ((n) < 0 ? -(n) : (n))

/* Macro multilinea con do-while para comportarse como una sola instruccion */
#define SALUDAR(nombre) \
    do { \
        printf("Hola, %s!\n", (nombre)); \
    } while (0)

/* Demonstrar como #undef elimina una macro */
#define TEMPoral 42
#undef TEMPoral
/* Si intentaramos usar TEMPoral aqui, el compilador daria error */

int main(void) {
    printf("=== CONSTANTES CON #define ===\n");
    printf("Autor: %s\n", AUTOR);
    printf("Pi: %.6f\n", PI);
    printf("Maximo de items: %d\n", MAX_ITEMS);

    printf("\n=== MACROS FUNCIONALES ===\n");
    printf("SQUARE(5)   = %d\n", SQUARE(5));
    printf("SQUARE(2+3) = %d (correcto: 25)\n", SQUARE(2+3));

    printf("ABSOLUTO(-7) = %d\n", ABSOLUTO(-7));
    printf("ABSOLUTO(7)  = %d\n", ABSOLUTO(7));

    printf("\n=== MACRO MULTILINEA ===\n");
    SALUDAR("Programador");

    printf("\n=== IMPORTANCIA DE LOS PARENTESIS ===\n");
    /* Sin parentesis: SQUARE(2+3) seria 2+3*2+3 = 11 (MAL) */
    /* Con parentesis: ((2+3)*(2+3)) = 25 (CORRECTO) */
    printf("Gracias a los parentesis: SQUARE(2+3) = %d\n", SQUARE(2+3));

    printf("\n=== MACROS PREDEFINIDAS ===\n");
    printf("Archivo: %s\n", __FILE__);
    printf("Linea:   %d\n", __LINE__);
    printf("Fecha:   %s\n", __DATE__);
    printf("Hora:    %s\n", __TIME__);

    printf("\n=== #undef DEMOSTRACION ===\n");
    printf("La macro TEMPoral fue eliminada con #undef\n");
    printf("Ya no se puede usar en este archivo.\n");

    return 0;
}
