/*
 * ============================================================
 * Modulo 05 -- Funciones
 * Archivo: 05_ejercicios.c
 * ============================================================
 *
 * Este archivo contiene ejercicios para practicar funciones en C.
 *
 * Debes reforzar:
 *
 *   - crear prototipos
 *   - definir funciones
 *   - usar parametros
 *   - devolver valores con return
 *   - usar funciones void
 *   - modificar valores usando punteros
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 05_ejercicios 05_ejercicios.c
 *
 * Ejecutar:
 *   Windows: 05_ejercicios.exe
 *   Linux/macOS: ./05_ejercicios
 */

#include <stdio.h>

int main(void) {
    printf("=== EJERCICIOS DEL MODULO 05 ===\n\n");

    /*
     * Ejercicio 1:
     * Crea una funcion llamada celsius_a_fahrenheit.
     *
     * Debe recibir un double con grados Celsius y devolver un double
     * con grados Fahrenheit.
     *
     * Formula:
     *   F = C * 9 / 5 + 32
     */
    printf("Ejercicio 1: Crea una funcion celsius_a_fahrenheit.\n");

    /*
     * Ejercicio 2:
     * Crea una funcion llamada es_palindromo.
     *
     * Debe recibir un entero y devolver 1 si se lee igual al reves,
     * o 0 si no se lee igual.
     *
     * Ejemplos:
     *   121 es palindromo.
     *   123 no es palindromo.
     */
    printf("Ejercicio 2: Crea una funcion es_palindromo.\n");

    /*
     * Ejercicio 3:
     * Crea una funcion llamada factorial_iterativo.
     *
     * Debe calcular el factorial usando un bucle, no recursividad.
     */
    printf("Ejercicio 3: Crea una funcion factorial_iterativo.\n");

    /*
     * Ejercicio 4:
     * Crea una funcion llamada intercambiar.
     *
     * Debe recibir dos punteros a int e intercambiar los valores reales
     * de esas dos variables.
     */
    printf("Ejercicio 4: Crea una funcion intercambiar con punteros.\n");

    /*
     * Ejercicio 5:
     * Crea una funcion void llamada imprimir_linea.
     *
     * Debe recibir un caracter y una cantidad. Luego debe imprimir ese
     * caracter la cantidad indicada de veces.
     */
    printf("Ejercicio 5: Crea una funcion void imprimir_linea.\n");

    return 0;
}
