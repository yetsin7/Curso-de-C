/*
 * ============================================================
 * Modulo 06 -- Arreglos y Strings
 * Archivo: 05_ejercicios.c
 * ============================================================
 *
 * Este archivo contiene ejercicios para practicar arreglos y strings.
 *
 * Debes reforzar:
 *
 *   - arreglos de una dimension
 *   - matrices
 *   - recorrido con for
 *   - strings terminados en '\0'
 *   - funciones que reciben arreglos
 *   - busqueda de valores
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
    printf("=== EJERCICIOS DEL MODULO 06 ===\n\n");

    /*
     * Ejercicio 1:
     * Crea un arreglo de 10 enteros y calcula la suma de todos.
     *
     * Pista:
     * Usa un for para recorrer el arreglo desde el indice 0 hasta el 9.
     */
    printf("Ejercicio 1: Crea un arreglo de 10 enteros y calcula la suma.\n");

    /*
     * Ejercicio 2:
     * Escribe una funcion que invierta un string en el mismo arreglo.
     *
     * Ejemplo:
     *   "hola" debe convertirse en "aloh".
     *
     * Pista:
     * Intercambia el primer caracter con el ultimo, el segundo con el
     * penultimo, y asi sucesivamente.
     */
    printf("Ejercicio 2: Escribe una funcion que invierta un string.\n");

    /*
     * Ejercicio 3:
     * Dada una matriz 3x3, encuentra el valor maximo.
     *
     * Pista:
     * Usa dos bucles for: uno para filas y otro para columnas.
     */
    printf("Ejercicio 3: En una matriz 3x3, encuentra el valor maximo.\n");

    /*
     * Ejercicio 4:
     * Implementa un contador de vocales en un string.
     *
     * Pista:
     * Recorre el string caracter por caracter hasta encontrar '\0'.
     */
    printf("Ejercicio 4: Implementa un contador de vocales en un string.\n");

    /*
     * Ejercicio 5:
     * Busca un numero dentro de un arreglo.
     *
     * Si lo encuentras, muestra su indice.
     * Si no lo encuentras, muestra un mensaje indicando que no existe.
     */
    printf("Ejercicio 5: Busca un numero dentro de un arreglo.\n");

    return 0;
}
