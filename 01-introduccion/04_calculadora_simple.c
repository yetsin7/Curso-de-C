/*
 * Modulo 01 -- Introduccion a C
 * Archivo: 04_calculadora_simple.c
 *
 * Mini-proyecto: una calculadora basica que demuestra el uso de
 * variables, printf, y operaciones aritmeticas en C.
 *
 * Este programa calcula y muestra resultados de operaciones
 * con dos numeros de ejemplo, simulando una calculadora basica.
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o calculadora 04_calculadora_simple.c
 * Ejecutar: calculadora.exe   (Windows)
 *           ./calculadora     (Linux/macOS)
 */

#include <stdio.h>

int main(void) {
    printf("=== Calculadora Simple en C ===\n");

    /* Numeros de ejemplo para las operaciones */
    float numero1 = 24.5f;
    float numero2 = 7.0f;

    printf("\nNumero 1: %.1f\n", numero1);
    printf("Numero 2: %.1f\n", numero2);

    /* Operaciones aritmeticas basicas */
    float suma = numero1 + numero2;
    float resta = numero1 - numero2;
    float multiplicacion = numero1 * numero2;
    float division = numero1 / numero2;

    printf("\n--- Resultados ---\n");
    printf("Suma:              %.1f + %.1f = %.2f\n", numero1, numero2, suma);
    printf("Resta:             %.1f - %.1f = %.2f\n", numero1, numero2, resta);
    printf("Multiplicacion:    %.1f * %.1f = %.2f\n", numero1, numero2, multiplicacion);
    printf("Division:          %.1f / %.1f = %.2f\n", numero1, numero2, division);

    /* Calculo con numeros enteros */
    int dias_trabajo = 5;
    int horas_diarias = 8;
    int total_horas = dias_trabajo * horas_diarias;

    printf("\n--- Ejemplo practico ---\n");
    printf("Dias de trabajo: %d\n", dias_trabajo);
    printf("Horas por dia: %d\n", horas_diarias);
    printf("Total horas semanales: %d\n", total_horas);

    /* Conversion de unidades */
    float metros = 150.0f;
    float centimetros = metros * 100.0f;

    printf("\n--- Conversion de unidades ---\n");
    printf("%.1f metros equivalen a %.1f centimetros\n", metros, centimetros);

    printf("\n=== Fin de la calculadora ===\n");

    return 0;
}
