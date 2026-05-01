/*
 * ============================================================
 * Modulo 01 -- Introduccion a C
 * Archivo: 05_ejercicios.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este archivo contiene ejercicios para practicar lo aprendido en el
 * primer modulo del curso.
 *
 * La idea no es solo leer el codigo, sino modificarlo, experimentar
 * y comprobar que entiendes cada parte.
 *
 * En programacion se aprende escribiendo codigo. Por eso este archivo
 * imprime instrucciones claras para que puedas resolverlas una por una.
 *
 * ------------------------------------------------------------
 * Que debes practicar aqui
 * ------------------------------------------------------------
 *
 *   1. Crear variables.
 *   2. Usar tipos como int, float y char.
 *   3. Mostrar informacion con printf().
 *   4. Hacer operaciones matematicas simples.
 *   5. Compilar y ejecutar un programa en C.
 *
 * ------------------------------------------------------------
 * Compilar
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o ejercicios 05_ejercicios.c
 *
 * Ejecutar en Windows:
 *
 *   ejercicios.exe
 *
 * Ejecutar en Linux/macOS:
 *
 *   ./ejercicios
 *
 */

#include <stdio.h>

int main(void) {
    printf("=== Ejercicios Modulo 01 ===\n\n");

    /*
     * Ejercicio 1:
     * Crea variables para guardar tu nombre y tu edad.
     *
     * Pista:
     * - Para la edad puedes usar int.
     * - Para el nombre, por ahora puedes imprimirlo directamente con printf().
     *
     * Ejemplo de idea:
     *   int edad = 20;
     *   printf("Mi nombre es Mauricio y tengo %d anios.\n", edad);
     */
    printf("1. Crea un programa que imprima tu nombre y edad usando variables.\n");

    /*
     * Ejercicio 2:
     * Declara dos numeros, sumalos y divide el resultado entre 2.
     *
     * Si quieres que el promedio tenga decimales, usa float o double.
     */
    printf("2. Declara dos numeros y calcula su promedio. Muestra el resultado.\n");

    /*
     * Ejercicio 3:
     * Convierte una temperatura de Celsius a Fahrenheit.
     *
     * Formula:
     *   F = C * 9 / 5 + 32
     *
     * Donde:
     * - C es la temperatura en Celsius.
     * - F es la temperatura en Fahrenheit.
     */
    printf("3. Convierte una temperatura de Celsius a Fahrenheit.\n");
    printf("   Formula: F = C * 9 / 5 + 32\n");

    /*
     * Ejercicio 4:
     * Crea tres variables char para guardar las letras A, B y C.
     *
     * Recuerda:
     * Los caracteres se escriben entre comillas simples.
     *
     * Ejemplo:
     *   char letra = 'A';
     */
    printf("4. Imprime los caracteres A, B, C usando variables de tipo char.\n");

    /*
     * Recomendacion final:
     * Resuelve un ejercicio a la vez. Despues de cada cambio, compila
     * el archivo para comprobar que no introdujiste errores.
     */
    printf("\nConsejo: resuelve un ejercicio, compila y prueba antes de seguir.\n");

    return 0;
}
