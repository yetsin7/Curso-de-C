/*
 * 04_proyecto_modular.c -- Mini-proyecto modular usando headers propios
 * Compilar: gcc -Wall -Wextra -std=c11 -o 04_modular 04_proyecto_modular.c
 *
 * Implementa las funciones declaradas en utilidades.h,
 * usa las macros de constantes.h y demuestra programacion modular en C.
 */

#include <stdio.h>
#include "constantes.h"
#include "utilidades.h"

/* Implementacion: imprime un separador visual */
void imprimir_separador(void) {
    for (int i = 0; i < MAX_SIZE / 2; i++) {
        putchar('-');
    }
    putchar('\n');
}

/* Implementacion: registro de depuracion condicional */
void log_debug(const char *archivo, int linea, const char *mensaje) {
    printf("[DEBUG %s:%d] %s\n", archivo, linea, mensaje);
}

/* Implementacion: factorial recursivo con proteccion de rango */
long factorial(int n) {
    if (n < 0) {
        return -1; /* Indica error para numeros negativos */
    }
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

/* Implementacion: verifica primalidad de forma simple */
int es_primo(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

/* Programa principal: demuestra el uso modular */
int main(void) {
    printf("=== PROYECTO MODULAR -- MODULO 12 ===\n");
    imprimir_separador();

    /* Uso de constantes del header */
    printf("Version del modulo: %d\n", VERSION);
    printf("Tamano maximo soportado: %d\n", MAX_SIZE);

    /* Uso de macros funcionales */
    printf("\n=== CALCULOS CON MACROS ===\n");
    int a = 12, b = 7;
    printf("MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("MIN(%d, %d) = %d\n", a, b, MIN(a, b));
    printf("SQUARE(%d)  = %d\n", a, SQUARE(a));

    /* Uso de funciones del header */
    printf("\n=== FUNCIONES UTILITARIAS ===\n");
    log_debug("04_proyecto_modular.c", __LINE__, "Ejecutando pruebas");

    for (int i = 1; i <= 8; i++) {
        long fact = factorial(i);
        printf("Factorial de %2d = %5ld\n", i, fact);
    }

    printf("\n=== NUMEROS PRIMOS ===\n");
    printf("Primos entre 1 y %d:\n", MAX_SIZE / 2);
    int contador = 0;
    for (int i = 2; i <= MAX_SIZE / 2; i++) {
        if (es_primo(i)) {
            printf("%4d ", i);
            contador++;
            if (contador % 10 == 0) {
                putchar('\n');
            }
        }
    }
    putchar('\n');

    printf("\n=== TEMPERATURAS ===\n");
    double temp_c[] = {0.0, 20.0, 36.5, 100.0};
    int total = sizeof(temp_c) / sizeof(temp_c[0]);
    for (int i = 0; i < total; i++) {
        printf("%.1f C -> %.1f F\n", temp_c[i],
               CELSIUS_A_FAHRENHEIT(temp_c[i]));
    }

    imprimir_separador();
    log_debug("04_proyecto_modular.c", __LINE__, "Programa finalizado");

    return 0;
}
