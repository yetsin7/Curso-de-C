/*
 * ============================================================
 * Modulo 04 -- Control de Flujo
 * Archivo: 05_ejercicios.c
 * ============================================================
 *
 * Este archivo contiene ejercicios para practicar control de flujo.
 *
 * Debes reforzar:
 *
 *   - if, else if y else
 *   - switch y case
 *   - for
 *   - while
 *   - do-while
 *   - break y continue
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o ejercicios 05_ejercicios.c
 *
 * Ejecutar:
 *   Windows: ejercicios.exe
 *   Linux/macOS: ./ejercicios
 */

#include <stdio.h>

int main(void) {
    printf("=== Ejercicios de Control de Flujo ===\n\n");

    /*
     * Ejercicio 1:
     * Pide una nota al usuario y muestra APROBADO o REPROBADO.
     *
     * Regla:
     * - Si la nota es mayor o igual a 60, aprobo.
     * - Si la nota es menor que 60, reprobo.
     *
     * Pista:
     * Usa scanf para leer la nota y un if para tomar la decision.
     */
    printf("Ejercicio 1: Pide una nota y muestra APROBADO o REPROBADO\n");
    /* Tu codigo aqui */
    printf("\n");

    /*
     * Ejercicio 2:
     * Usa un for para imprimir los numeros del 10 al 1.
     *
     * Pista:
     * El contador debe empezar en 10 y disminuir hasta llegar a 1.
     */
    printf("Ejercicio 2: Imprime del 10 al 1 en orden descendente\n");
    /* Tu codigo aqui */
    printf("\n");

    /*
     * Ejercicio 3:
     * Usa un while para sumar numeros ingresados por el usuario hasta
     * que el usuario escriba 0.
     *
     * Pista:
     * Necesitas una variable para el numero ingresado y otra para la suma.
     */
    printf("Ejercicio 3: Suma numeros hasta que el usuario escriba 0\n");
    /* Tu codigo aqui */
    printf("\n");

    /*
     * Ejercicio 4:
     * Crea un menu con switch para convertir temperaturas.
     *
     * Opciones sugeridas:
     * 1. Celsius a Fahrenheit
     * 2. Fahrenheit a Celsius
     * 3. Salir
     */
    printf("Ejercicio 4: Crea un menu para convertir entre Celsius y Fahrenheit\n");
    /* Tu codigo aqui */
    printf("\n");

    /*
     * Ejercicio 5:
     * Usa continue para imprimir solo los numeros impares del 1 al 20.
     *
     * Pista:
     * Si el numero es par, usa continue para saltarlo.
     */
    printf("Ejercicio 5: Imprime solo los numeros impares del 1 al 20\n");
    /* Tu codigo aqui */
    printf("\n");

    printf("=== Fin de los ejercicios ===\n");

    return 0;
}
