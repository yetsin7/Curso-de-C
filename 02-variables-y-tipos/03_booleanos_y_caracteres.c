/*
 * Modulo 02 - Booleanos y Caracteres
 * Compilar: gcc -Wall -Wextra -std=c11 -o 03_booleanos 03_booleanos_y_caracteres.c
 *
 * Explora el tipo bool desde stdbool.h, el tipo char como letra y
 * como codigo ASCII, conversiones de tipos y cast explicito.
 */

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    printf("=== MODULO 02 - BOOLEANOS Y CARACTERES ===\n\n");

    /* --- Tipo bool --- */
    printf("--- Tipo bool ---\n");

    bool activo = true;
    bool visible = false;
    bool completado = 1;
    bool pendiente = 0;

    printf("activo:    %d (true=%d, false=%d)\n", activo, activo, !activo);
    printf("visible:   %d\n", visible);
    printf("completado:%d\n", completado);
    printf("pendiente: %d\n", pendiente);

    /* --- char como letra y como numero ASCII --- */
    printf("\n--- char como letra y como numero ---\n");

    char letra1 = 'A';
    char letra2 = 'z';
    char simbolo = '$';

    printf("Letra '%c' tiene codigo ASCII: %d\n", letra1, letra1);
    printf("Letra '%c' tiene codigo ASCII: %d\n", letra2, letra2);
    printf("Simbolo '%c' tiene codigo ASCII: %d\n", simbolo, simbolo);

    /* --- Crear char desde codigo ASCII --- */
    printf("\n--- Crear char desde codigo numerico ---\n");

    char c1 = 65;
    char c2 = 97;
    char c3 = 33;

    printf("ASCII 65 es: %c\n", c1);
    printf("ASCII 97 es: %c\n", c2);
    printf("ASCII 33 es: %c\n", c3);

    /* --- Conversion de tipos (cast) --- */
    printf("\n--- Conversion de tipos (cast) ---\n");

    int entero = 7;
    double decimal = 2.5;

    /* Division entera: pierde el decimal */
    int resultado_ent = entero / 2;
    printf("7 / 2 (entero)      = %d\n", resultado_ent);

    /* Division con cast: conserva el decimal */
    double resultado_dec = (double)entero / 2;
    printf("7 / 2 (con cast)    = %.1f\n", resultado_dec);

    /* Double a int: trunca la parte decimal */
    int truncado = (int)decimal;
    printf("2.5 casteado a int  = %d\n", truncado);

    /* Char a int y viceversa */
    char letra = 'M';
    int codigo = (int)letra;
    char desde_num = (char)77;

    printf("'%c' como entero    = %d\n", letra, codigo);
    printf("77 como char        = %c\n", desde_num);

    /* --- Tamano de tipos --- */
    printf("\n--- Tamano en bytes ---\n");

    printf("sizeof(bool): %zu bytes\n", sizeof(bool));
    printf("sizeof(char): %zu bytes\n", sizeof(char));

    /* --- Rango de char --- */
    printf("\n--- Rango de char ---\n");

    printf("Char como signed: %d a %d\n", -128, 127);
    printf("Char como unsigned: 0 a 255\n");

    return 0;
}
