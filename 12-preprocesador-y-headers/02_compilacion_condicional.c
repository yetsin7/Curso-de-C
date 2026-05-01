/*
 * ============================================================
 * Modulo 12 -- Preprocesador y Headers
 * Archivo: 02_compilacion_condicional.c
 * ============================================================
 *
 * Este archivo explica la compilacion condicional.
 *
 * La compilacion condicional permite incluir o excluir partes del codigo
 * dependiendo de macros definidas antes de compilar.
 *
 * Esto se usa para:
 *
 *   - activar mensajes de depuracion
 *   - compilar codigo diferente segun el sistema operativo
 *   - habilitar o deshabilitar funciones
 *   - crear versiones distintas del mismo programa
 *
 * Compilar normal:
 *   gcc -Wall -Wextra -std=c11 -o 02_condicional 02_compilacion_condicional.c
 *
 * Compilar con DEBUG:
 *   gcc -Wall -Wextra -std=c11 -DDEBUG -o 02_condicional_debug 02_compilacion_condicional.c
 *
 * Compilar con nivel de optimizacion personalizado:
 *   gcc -Wall -Wextra -std=c11 -DNIVEL_OPT=3 -o 02_condicional 02_compilacion_condicional.c
 */

#include <stdio.h>

/*
 * Deteccion de plataforma.
 *
 * Algunas macros son definidas automaticamente por el compilador segun
 * el sistema operativo.
 */
#ifdef _WIN32
    #define SO "Windows"
#elif defined(__linux__)
    #define SO "Linux"
#elif defined(__APPLE__)
    #define SO "macOS"
#else
    #define SO "Desconocido"
#endif

/*
 * Si NIVEL_OPT no fue definido por linea de comandos, usamos 1.
 */
#ifndef NIVEL_OPT
    #define NIVEL_OPT 1
#endif

/*
 * LOG solo imprime mensajes cuando DEBUG esta definido.
 */
#ifdef DEBUG
    #define LOG(msg) printf("[LOG] %s\n", msg)
#else
    #define LOG(msg) ((void)0)
#endif

int main(void) {
    printf("=== DETECCION DE PLATAFORMA ===\n");
    printf("Sistema operativo detectado: %s\n", SO);

    printf("\n=== #ifdef / #ifndef ===\n");

#ifdef DEBUG
    printf("[DEBUG] Modo de depuracion ACTIVADO\n");
    printf("[DEBUG] Este bloque existe porque compilaste con -DDEBUG\n");
#else
    printf("Modo de depuracion DESACTIVADO\n");
    printf("Compila con -DDEBUG para activar mensajes extra.\n");
#endif

    printf("\n=== #if / #elif / #else ===\n");

#if NIVEL_OPT == 3
    printf("Optimizacion MAXIMA\n");
#elif NIVEL_OPT == 2
    printf("Optimizacion MEDIA\n");
#else
    printf("Optimizacion MINIMA o por defecto\n");
#endif

    printf("NIVEL_OPT actual: %d\n", NIVEL_OPT);

    printf("\n=== #if CON EXPRESIONES ===\n");

#define ANIO 2026

#if ANIO > 2025
    printf("Estamos en una version posterior a 2025\n");
#elif ANIO == 2025
    printf("Estamos exactamente en 2025\n");
#else
    printf("Estamos antes de 2025\n");
#endif

    printf("\n=== MACRO LOG CONDICIONAL ===\n");

    LOG("Este mensaje solo aparece si DEBUG esta activo");

#ifndef DEBUG
    printf("LOG no imprimio nada porque DEBUG no esta activo.\n");
#endif

    return 0;
}
