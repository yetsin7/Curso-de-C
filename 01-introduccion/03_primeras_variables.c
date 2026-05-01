/*
 * Modulo 01 -- Introduccion a C
 * Archivo: 03_primeras_variables.c
 *
 * Este archivo introduce los tipos basicos de variables en C:
 *   - int: numeros enteros
 *   - float: numeros decimales de precision simple
 *   - double: numeros decimales de precision doble
 *   - char: un solo caracter
 *
 * Tambien muestra como usar printf con especificadores de formato
 * para imprimir cada tipo de variable.
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o variables 03_primeras_variables.c
 * Ejecutar: variables.exe   (Windows)
 *           ./variables     (Linux/macOS)
 */

#include <stdio.h>

int main(void) {
    printf("=== Primeras variables en C ===\n");

    /* int: almacena numeros enteros (sin parte decimal) */
    int edad = 30;
    int año_actual = 2026;

    /* float: numeros decimales de precision simple (6-7 digitos) */
    float temperatura = 36.6f;

    /* double: numeros decimales de precision doble (15-16 digitos) */
    double pi = 3.14159265358979;

    /* char: almacena un solo caracter, se usa comilla simple */
    char letra_inicial = 'C';

    /* Imprimir variables con sus especificadores de formato */
    printf("\nVariables declaradas:\n");
    printf("Edad (int):          %d\n", edad);         /* %d = entero decimal */
    printf("Año actual (int):    %d\n", año_actual);
    printf("Temperatura (float): %.1f\n", temperatura); /* %.1f = 1 decimal */
    printf("Pi (double):         %.10f\n", pi);         /* %.10f = 10 decimales */
    printf("Letra inicial (char): %c\n", letra_inicial); /* %c = caracter */

    /* Operaciones basicas con variables */
    int a = 15;
    int b = 4;

    printf("\nOperaciones con a=%d y b=%d:\n", a, b);
    printf("Suma:         %d + %d = %d\n", a, b, a + b);
    printf("Resta:        %d - %d = %d\n", a, b, a - b);
    printf("Multiplicacion: %d * %d = %d\n", a, b, a * b);
    printf("Division:     %d / %d = %d (entera)\n", a, b, a / b);

    return 0;
}
