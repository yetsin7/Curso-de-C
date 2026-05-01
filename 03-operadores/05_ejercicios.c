/*
 * Modulo 03 -- Ejercicios de Operadores
 * Archivo: 05_ejercicios.c
 *
 * Archivo con 4 ejercicios practicos para reforzar
 * el uso de operadores aritmeticos, de comparacion,
 * logicos y bitwise.
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 05_ejercicios 05_ejercicios.c
 */

#include <stdio.h>

int main(void) {
    printf("=== EJERCICIOS - MODULO 03: OPERADORES ===\n\n");

    /* Ejercicio 1: Calcula el area de un triangulo (base=10, altura=6)
       Formula: area = (base * altura) / 2. Usa float para decimales */
    printf("Ejercicio 1: Area de triangulo (base=10, altura=6)\n");
    /* TODO: Escribe tu codigo aqui */
    printf("\n");

    /* Ejercicio 2: Compara dos temperaturas (temp1=32, temp2=28)
       Muestra cual es mayor usando el operador ternario */
    printf("Ejercicio 2: Compara temperaturas (32 vs 28)\n");
    /* TODO: Escribe tu codigo aqui */
    printf("\n");

    /* Ejercicio 3: Verifica si un numero esta en [10, 50] usando && */
    printf("Ejercicio 3: Verifica si 35 esta entre 10 y 50\n");
    /* TODO: Escribe tu codigo aqui */
    printf("\n");

    /* Ejercicio 4: Determina si 17 es par o impar usando bitwise
       Pista: num & 1 == 0 significa par */
    printf("Ejercicio 4: Es 17 par o impar? (usa bitwise)\n");
    /* TODO: Escribe tu codigo aqui */
    printf("\n");

    printf("=== Fin de ejercicios ===\n");
    return 0;
}
