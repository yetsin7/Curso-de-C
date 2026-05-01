/*
 * Modulo 02 - Tipos Enteros
 * Compilar: gcc -Wall -Wextra -std=c11 -o 01_tipos_enteros 01_tipos_enteros.c
 *
 * Explora los tipos enteros en C: char, short, int, long, long long
 * y sus variantes unsigned. Muestra tamaños con sizeof y limites
 * desde limits.h.
 */

#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("=== MODULO 02 - TIPOS ENTEROS ===\n\n");

    /* --- Tipos enteros con signo --- */
    printf("--- Tipos con signo ---\n");

    char c = -10;
    short s = 1000;
    int i = 50000;
    long l = 2000000000L;
    long long ll = 9000000000000000000LL;

    printf("char: %d\n", c);
    printf("short: %d\n", s);
    printf("int: %d\n", i);
    printf("long: %ld\n", l);
    printf("long long: %lld\n", ll);

    /* --- Tipos enteros sin signo --- */
    printf("\n--- Tipos sin signo (unsigned) ---\n");

    unsigned char uc = 200;
    unsigned short us = 60000;
    unsigned int ui = 4000000000u;
    unsigned long ul = 3000000000UL;

    printf("unsigned char: %u\n", uc);
    printf("unsigned short: %u\n", us);
    printf("unsigned int: %u\n", ui);
    printf("unsigned long: %lu\n", ul);

    /* --- Tamano de cada tipo --- */
    printf("\n--- Tamano en bytes ---\n");

    printf("sizeof(char):       %zu bytes\n", sizeof(char));
    printf("sizeof(short):      %zu bytes\n", sizeof(short));
    printf("sizeof(int):        %zu bytes\n", sizeof(int));
    printf("sizeof(long):       %zu bytes\n", sizeof(long));
    printf("sizeof(long long):  %zu bytes\n", sizeof(long long));

    /* --- Limites de tipos --- */
    printf("\n--- Limites de tipos ---\n");

    printf("CHAR_MIN:   %d\n", CHAR_MIN);
    printf("CHAR_MAX:   %d\n", CHAR_MAX);
    printf("SHRT_MIN:   %d\n", SHRT_MIN);
    printf("SHRT_MAX:   %d\n", SHRT_MAX);
    printf("INT_MIN:    %d\n", INT_MIN);
    printf("INT_MAX:    %d\n", INT_MAX);
    printf("LONG_MAX:   %ld\n", LONG_MAX);
    printf("LLONG_MAX:  %lld\n", LLONG_MAX);
    printf("UINT_MAX:   %u\n", UINT_MAX);

    return 0;
}
