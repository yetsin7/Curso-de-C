/*
 * ============================================================
 * Modulo 12 -- Preprocesador y Headers
 * Archivo: 04_proyecto_modular.c
 * ============================================================
 *
 * Este archivo muestra un mini-proyecto modular usando headers propios.
 *
 * Un programa modular separa responsabilidades. En vez de poner todo en
 * un solo archivo sin organizacion, se separan constantes, prototipos e
 * implementaciones.
 *
 * En este ejemplo:
 *
 *   constantes.h  contiene macros y constantes.
 *   utilidades.h  contiene prototipos de funciones.
 *   este archivo   implementa y usa esas funciones.
 *
 * En proyectos profesionales, las implementaciones suelen separarse en
 * archivos .c adicionales. Aqui se mantienen juntas para que el ejemplo
 * sea facil de compilar como archivo independiente.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 04_modular 04_proyecto_modular.c
 *
 * Ejecutar:
 *   Windows: 04_modular.exe
 *   Linux/macOS: ./04_modular
 */

#include <stdio.h>
#include "constantes.h"
#include "utilidades.h"

/*
 * Implementacion de imprimir_separador.
 */
void imprimir_separador(void) {
    for (int i = 0; i < MAX_SIZE / 2; i++) {
        putchar('-');
    }

    putchar('\n');
}

/*
 * Implementacion de log_debug.
 */
void log_debug(const char *archivo, int linea, const char *mensaje) {
    printf("[DEBUG %s:%d] %s\n", archivo, linea, mensaje);
}

/*
 * Factorial recursivo con validacion simple.
 */
long factorial(int n) {
    if (n < 0) {
        return -1;
    }

    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

/*
 * Verifica si un numero es primo.
 */
int es_primo(int n) {
    if (n <= 1) {
        return 0;
    }

    if (n <= 3) {
        return 1;
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    printf("=== PROYECTO MODULAR -- MODULO 12 ===\n");
    imprimir_separador();

    printf("Version del modulo: %d\n", VERSION);
    printf("Tamano maximo soportado: %d\n", MAX_SIZE);

    printf("\n=== CALCULOS CON MACROS ===\n");

    int a = 12;
    int b = 7;

    printf("MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("MIN(%d, %d) = %d\n", a, b, MIN(a, b));
    printf("SQUARE(%d)  = %d\n", a, SQUARE(a));

    printf("\n=== FUNCIONES UTILITARIAS ===\n");

    log_debug(__FILE__, __LINE__, "Ejecutando pruebas");

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
        printf("%.1f C -> %.1f F\n", temp_c[i], CELSIUS_A_FAHRENHEIT(temp_c[i]));
    }

    imprimir_separador();
    log_debug(__FILE__, __LINE__, "Programa finalizado");

    return 0;
}
