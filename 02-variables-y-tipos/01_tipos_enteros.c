/*
 * ============================================================
 * Modulo 02 -- Variables y Tipos de Datos
 * Archivo: 01_tipos_enteros.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este programa explica los tipos enteros en C.
 *
 * Un tipo entero sirve para guardar numeros sin parte decimal.
 * Ejemplos de numeros enteros:
 *
 *   -10, 0, 25, 2026, 50000
 *
 * En C existen varios tipos enteros porque no todos ocupan la misma
 * cantidad de memoria ni soportan el mismo rango de valores.
 *
 * ------------------------------------------------------------
 * Idea clave
 * ------------------------------------------------------------
 *
 * Mientras mas grande sea el tipo, normalmente puede guardar numeros
 * mas grandes, pero tambien puede ocupar mas memoria.
 *
 * Por ejemplo:
 *
 *   char       suele ocupar poca memoria.
 *   int        suele ser el entero mas comun.
 *   long long  se usa para numeros enteros muy grandes.
 *
 * ------------------------------------------------------------
 * signed y unsigned
 * ------------------------------------------------------------
 *
 * signed significa "con signo".
 * Puede guardar numeros negativos, cero y positivos.
 *
 * unsigned significa "sin signo".
 * Solo puede guardar cero y numeros positivos.
 *
 * Como unsigned no guarda negativos, puede usar ese espacio para llegar
 * a valores positivos mas grandes.
 *
 * ------------------------------------------------------------
 * Compilar
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o 01_tipos_enteros 01_tipos_enteros.c
 *
 * Ejecutar en Windows:
 *
 *   01_tipos_enteros.exe
 *
 * Ejecutar en Linux/macOS:
 *
 *   ./01_tipos_enteros
 *
 */

#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("=== MODULO 02 - TIPOS ENTEROS ===\n\n");

    /*
     * Tipos enteros con signo.
     *
     * Estos tipos pueden guardar numeros negativos y positivos.
     */
    printf("--- Tipos con signo ---\n");

    char c = -10;
    short s = 1000;
    int i = 50000;
    long l = 2000000000L;
    long long ll = 9000000000000000000LL;

    /*
     * Cada tipo necesita su especificador correcto en printf().
     *
     * %d   se usa para int. char y short se convierten a int al imprimir.
     * %ld  se usa para long.
     * %lld se usa para long long.
     */
    printf("char:       %d\n", c);
    printf("short:      %d\n", s);
    printf("int:        %d\n", i);
    printf("long:       %ld\n", l);
    printf("long long:  %lld\n", ll);

    /*
     * Tipos enteros sin signo.
     *
     * No aceptan numeros negativos. Solo guardan cero y positivos.
     */
    printf("\n--- Tipos sin signo (unsigned) ---\n");

    unsigned char uc = 200;
    unsigned short us = 60000;
    unsigned int ui = 4000000000u;
    unsigned long ul = 3000000000UL;

    /*
     * %u  se usa para unsigned int.
     * %lu se usa para unsigned long.
     */
    printf("unsigned char:   %u\n", uc);
    printf("unsigned short:  %u\n", us);
    printf("unsigned int:    %u\n", ui);
    printf("unsigned long:   %lu\n", ul);

    /*
     * sizeof indica cuantos bytes ocupa un tipo o una variable.
     *
     * Un byte normalmente son 8 bits. Los bits son la unidad minima
     * de informacion en la computadora: solo pueden valer 0 o 1.
     */
    printf("\n--- Tamano en bytes ---\n");

    printf("sizeof(char):       %zu bytes\n", sizeof(char));
    printf("sizeof(short):      %zu bytes\n", sizeof(short));
    printf("sizeof(int):        %zu bytes\n", sizeof(int));
    printf("sizeof(long):       %zu bytes\n", sizeof(long));
    printf("sizeof(long long):  %zu bytes\n", sizeof(long long));

    /*
     * limits.h define constantes con los limites de cada tipo entero.
     *
     * Esto es util porque los tamanos exactos pueden variar dependiendo
     * del sistema y del compilador.
     */
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

    /*
     * Recomendacion practica:
     * Usa int para numeros enteros comunes. Usa long long cuando sepas
     * que necesitas numeros muy grandes. Usa unsigned solo cuando tenga
     * sentido que el valor nunca sea negativo, por ejemplo una cantidad.
     */

    return 0;
}
