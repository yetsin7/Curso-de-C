/*
 * ============================================================
 * Modulo 08 -- Punteros
 * Archivo: 01_punteros_basicos.c
 * ============================================================
 *
 * Este archivo explica los punteros desde cero.
 *
 * Un puntero es una variable que guarda una direccion de memoria.
 *
 * Una variable normal guarda un valor:
 *
 *   int edad = 25;
 *
 * Un puntero guarda la direccion donde vive ese valor:
 *
 *   int *ptr = &edad;
 *
 * Conceptos clave:
 *
 *   &  obtiene la direccion de una variable.
 *   *  permite acceder al valor guardado en esa direccion.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 01_basicos 01_punteros_basicos.c
 *
 * Ejecutar:
 *   Windows: 01_basicos.exe
 *   Linux/macOS: ./01_basicos
 */

#include <stdio.h>

int main(void) {
    printf("=== QUE ES UN PUNTERO ===\n");

    /*
     * edad es una variable normal de tipo int.
     * ptr es un puntero a int.
     *
     * &edad obtiene la direccion de memoria de edad.
     */
    int edad = 25;
    int *ptr = &edad;

    printf("Valor de edad:      %d\n", edad);
    printf("Direccion de edad:  %p\n", (void *)&edad);
    printf("Valor de ptr:       %p\n", (void *)ptr);
    printf("Valor usando *ptr:  %d\n", *ptr);

    printf("\n=== OPERADOR & ===\n");

    /*
     * El operador & significa direccion de.
     *
     * Cada variable vive en alguna direccion de memoria.
     */
    float precio = 19.99f;
    char inicial = 'A';

    printf("Direccion de precio:  %p\n", (void *)&precio);
    printf("Direccion de inicial: %p\n", (void *)&inicial);

    printf("sizeof(int):   %zu bytes\n", sizeof(int));
    printf("sizeof(float): %zu bytes\n", sizeof(float));
    printf("sizeof(char):  %zu byte\n", sizeof(char));

    printf("\n=== OPERADOR * O DESREFERENCIA ===\n");

    /*
     * Desreferenciar significa entrar a la direccion que guarda el puntero
     * para leer o modificar el valor real.
     */
    int numero = 42;
    int *p = &numero;

    printf("Antes: numero = %d\n", numero);

    *p = 100;
    printf("Despues de *p = 100: numero = %d\n", numero);

    *p += 5;
    printf("Despues de *p += 5: numero = %d\n", numero);

    printf("\n=== PUNTERO NULL ===\n");

    /*
     * NULL significa que el puntero no apunta a una direccion valida.
     *
     * Nunca debes usar * sobre un puntero NULL.
     */
    int *vacio = NULL;
    printf("Puntero NULL: %p\n", (void *)vacio);

    if (vacio == NULL) {
        printf("El puntero es NULL. No se debe desreferenciar.\n");
    }

    int dato = 77;
    int *valido = &dato;

    if (valido != NULL) {
        printf("Puntero valido. Valor: %d\n", *valido);
    }

    printf("\n=== IMPRESION DE DIRECCIONES CON %%p ===\n");

    int a = 10;
    int b = 20;
    int c = 30;

    printf("&a = %p\n", (void *)&a);
    printf("&b = %p\n", (void *)&b);
    printf("&c = %p\n", (void *)&c);

    /*
     * Las direcciones pueden verse diferentes cada vez que ejecutas el
     * programa. Eso es normal.
     */

    return 0;
}
