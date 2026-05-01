/*
 * Modulo 04 -- Bucle for
 * Archivo: 02_bucle_for.c
 *
 * Demuestra el bucle for en C:
 *   - Bucle for basico
 *   - Bucle for con decremento
 *   - Bucles for anidados
 *   - Impresion de patrones (triangulo, cuadrado)
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o bucle_for 02_bucle_for.c
 */

#include <stdio.h>

int main(void) {
    /* ===== BUCLE FOR BASICO ===== */
    printf("=== Conteo del 1 al 5 ===\n");

    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    /* Tabla de multiplicar */
    printf("\n=== Tabla del 7 ===\n");

    for (int i = 1; i <= 10; i++) {
        printf("  7 x %2d = %2d\n", i, 7 * i);
    }

    /* ===== FOR CON DECREMENTO ===== */
    printf("\n=== Cuenta regresiva ===\n");

    for (int i = 5; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\nDespegue!\n");

    /* ===== FOR ANIDADO: Tabla de multiplicar 3x3 ===== */
    printf("\n=== Tabla de multiplicar 3x3 ===\n");

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("%d*%d=%-4d", i, j, i * j);
        }
        printf("\n");
    }

    /* ===== PATRON: Triangulo de asteriscos ===== */
    printf("\n=== Triangulo de asteriscos ===\n");

    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    /* ===== PATRON: Cuadrado de asteriscos ===== */
    printf("\n=== Cuadrado de asteriscos 5x5 ===\n");

    int tamano = 5;

    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            printf("* ");
        }
        printf("\n");
    }

    /* ===== PATRON: Piramide centrada ===== */
    printf("\n=== Piramide centrada ===\n");

    for (int i = 1; i <= 5; i++) {
        /* Espacios en blanco */
        for (int j = 0; j < 5 - i; j++) {
            printf(" ");
        }
        /* Asteriscos */
        for (int j = 0; j < (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    /* ===== FOR CON PASO DE 2 ===== */
    printf("\n=== Numeros pares del 0 al 10 ===\n");

    for (int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
