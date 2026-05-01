/*
 * Modulo 05 — Ejercicios
 * Compilar: gcc -Wall -Wextra -std=c11 -o 05_ejercicios 05_ejercicios.c
 *
 * Cuatro tareas practicas para repasar funciones en C.
 */

#include <stdio.h>

int main(void) {
    printf("=== EJERCICIOS DEL MODULO 05 ===\n\n");

    printf("Ejercicio 1: Crea una funcion 'celsius_a_fahrenheit' que reciba\n");
    printf("             un double y retorne la temperatura en Fahrenheit.\n");
    printf("             Formula: F = C * 9/5 + 32\n\n");

    printf("Ejercicio 2: Escribe una funcion 'es_palindromo' que reciba un\n");
    printf("             entero y retorne 1 si se lee igual al reves.\n");
    printf("             Ejemplo: 121 -> si, 123 -> no.\n\n");

    printf("Ejercicio 3: Crea una funcion 'factorial_iterativo' que calcule\n");
    printf("             n! usando un bucle (sin recursividad).\n\n");

    printf("Ejercicio 4: Escribe una funcion 'intercambiar' que reciba dos\n");
    printf("             punteros a int y los intercambie. Pruebala en main.\n");

    return 0;
}
