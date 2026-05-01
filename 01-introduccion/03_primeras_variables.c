/*
 * ============================================================
 * Modulo 01 -- Introduccion a C
 * Archivo: 03_primeras_variables.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este programa explica que son las variables y como se usan los
 * tipos de datos mas basicos en C.
 *
 * Una variable es un espacio en la memoria de la computadora donde
 * podemos guardar un dato temporalmente mientras el programa se ejecuta.
 *
 * Imagina una variable como una caja con nombre:
 *
 *   - El nombre identifica la caja.
 *   - El tipo indica que clase de dato puede guardar.
 *   - El valor es lo que hay dentro de la caja.
 *
 * Ejemplo:
 *
 *   int edad = 30;
 *
 * Significa:
 *
 *   - int: la variable guarda un numero entero.
 *   - edad: ese es el nombre de la variable.
 *   - 30: ese es el valor guardado.
 *
 * ------------------------------------------------------------
 * Tipos basicos usados en este archivo
 * ------------------------------------------------------------
 *
 * int:
 *   Guarda numeros enteros, sin parte decimal.
 *   Ejemplos: 10, -5, 0, 2026.
 *
 * float:
 *   Guarda numeros con decimales, pero con precision limitada.
 *   Ejemplos: 3.5, 36.6, -10.25.
 *
 * double:
 *   Guarda numeros con decimales con mayor precision que float.
 *   Se usa cuando necesitas mas exactitud.
 *
 * char:
 *   Guarda un solo caracter.
 *   Ejemplos: 'A', 'B', 'C', '7'.
 *
 * ------------------------------------------------------------
 * Compilar
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o variables 03_primeras_variables.c
 *
 * Ejecutar en Windows:
 *
 *   variables.exe
 *
 * Ejecutar en Linux/macOS:
 *
 *   ./variables
 *
 */

#include <stdio.h>

int main(void) {
    printf("=== Primeras variables en C ===\n");

    /*
     * Declarar una variable significa crearla.
     *
     * En C, primero escribimos el tipo de dato, luego el nombre de la
     * variable y, si queremos, le asignamos un valor inicial.
     */

    /* int guarda numeros enteros, es decir, numeros sin decimales. */
    int edad = 30;
    int anio_actual = 2026;

    /*
     * float guarda numeros con decimales.
     *
     * La letra f al final de 36.6f indica que el numero debe tratarse
     * como float y no como double.
     */
    float temperatura = 36.6f;

    /*
     * double tambien guarda numeros decimales, pero con mas precision
     * que float. Es comun usar double para calculos mas exactos.
     */
    double pi = 3.14159265358979;

    /*
     * char guarda un solo caracter.
     *
     * Los valores char se escriben entre comillas simples.
     */
    char letra_inicial = 'C';

    /*
     * Para imprimir variables con printf(), usamos especificadores
     * de formato.
     *
     * Un especificador de formato le dice a printf() que tipo de dato
     * se va a mostrar.
     *
     * Algunos especificadores comunes:
     *
     *   %d  -> int
     *   %f  -> float o double
     *   %c  -> char
     */
    printf("\nVariables declaradas:\n");
    printf("Edad (int):              %d\n", edad);
    printf("Anio actual (int):       %d\n", anio_actual);
    printf("Temperatura (float):     %.1f\n", temperatura);
    printf("Pi (double):             %.10f\n", pi);
    printf("Letra inicial (char):    %c\n", letra_inicial);

    /*
     * Tambien podemos hacer operaciones matematicas con variables.
     */
    int a = 15;
    int b = 4;

    printf("\nOperaciones con a=%d y b=%d:\n", a, b);
    printf("Suma:             %d + %d = %d\n", a, b, a + b);
    printf("Resta:            %d - %d = %d\n", a, b, a - b);
    printf("Multiplicacion:   %d * %d = %d\n", a, b, a * b);

    /*
     * Cuidado:
     * Cuando divides dos enteros en C, el resultado tambien es entero.
     *
     * Por eso 15 / 4 da 3 y no 3.75.
     *
     * La parte decimal se pierde porque a y b son variables de tipo int.
     */
    printf("Division entera:  %d / %d = %d\n", a, b, a / b);

    return 0;
}
