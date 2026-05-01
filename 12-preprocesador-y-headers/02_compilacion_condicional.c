/*
 * 02_compilacion_condicional.c -- Compilacion condicional
 * Compilar: gcc -Wall -Wextra -std=c11 -o 02_condicional 02_compilacion_condicional.c
 * Con debug: gcc -Wall -Wextra -std=c11 -DDEBUG -o 02_condicional_debug 02_compilacion_condicional.c
 *
 * Demuestra #ifdef, #ifndef, #if, #elif, #else y deteccion de plataforma.
 */

#include <stdio.h>

/* Deteccion de plataforma en tiempo de compilacion */
#ifdef _WIN32
    #define SO "Windows"
#elif defined(__linux__)
    #define SO "Linux"
#elif defined(__APPLE__)
    #define SO "macOS"
#else
    #define SO "Desconocido"
#endif

/* Nivel de optimizacion configurado por linea de comandos */
#ifndef NIVEL_OPT
    #define NIVEL_OPT 1
#endif

int main(void) {
    printf("=== DETECCION DE PLATAFORMA ===\n");
    printf("Sistema operativo: %s\n", SO);

    printf("\n=== #ifdef / #ifndef ===\n");
#ifdef DEBUG
    printf("[DEBUG] Modo de depuracion ACTIVADO\n");
    printf("[DEBUG] Este bloque solo existe si compilas con -DDEBUG\n");
#else
    printf("Modo de depuracion DESACTIVADO\n");
    printf("Compila con -DDEBUG para activar los mensajes de depuracion\n");
#endif

    printf("\n=== #if / #elif / #else ===\n");
#if NIVEL_OPT == 3
    printf("Optimizacion MAXIMA -- compilacion mas lenta, mejor rendimiento\n");
#elif NIVEL_OPT == 2
    printf("Optimizacion MEDIA -- balance entre velocidad y tamano\n");
#else
    printf("Optimizacion MINIMA -- compilacion rapida para desarrollo\n");
#endif

    printf("\n=== #if CON EXPRESIONES ===\n");
#define ANIO 2026
#if ANIO > 2025
    printf("Estamos en una version posterior a 2025\n");
#elif ANIO == 2025
    printf("Estamos exactamente en 2025\n");
#else
    printf("Estamos antes de 2025\n");
#endif

    printf("\n=== INCLUSION DE ARCHIVOS SEGUN CONDICION ===\n");
#ifdef DEBUG
    #define LOG(msg) printf("[LOG] %s\n", msg)
#else
    #define LOG(msg) ((void)0)
#endif
    LOG("Este es un mensaje condicional de registro");
    printf("(Activa DEBUG para ver mensajes LOG reales)\n");

    return 0;
}
