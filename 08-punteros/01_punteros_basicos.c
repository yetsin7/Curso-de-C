/*
 * Modulo 08 -- Punteros basicos
 * Compilar: gcc -Wall -Wextra -std=c11 -o 01_basicos 01_punteros_basicos.c
 *
 * Demuestra:
 *   - Que es un puntero y como se declara
 *   - Operador & (direccion de)
 *   - Operador * (desreferencia)
 *   - Puntero NULL
 *   - Impresion de direcciones con %p
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* -----------------------------------------------
     * 1. Que es un puntero
     * ----------------------------------------------- */
    printf("=== QUE ES UN PUNTERO ===\n");

    /* Un puntero es una variable que almacena una direccion de memoria */
    int edad = 25;
    int *ptr = &edad;  /* ptr guarda la direccion de edad */

    printf("Valor de edad:    %d\n", edad);
    printf("Direccion de edad: %p\n", (void *)&edad);
    printf("Valor de ptr:      %p (misma direccion)\n", (void *)ptr);
    printf("Valor en *ptr:     %d (acceso al dato)\n", *ptr);

    /* -----------------------------------------------
     * 2. Operador & (direccion de)
     * ----------------------------------------------- */
    printf("\n=== OPERADOR & ===\n");

    float precio = 19.99f;
    char inicial = 'A';

    printf("Direccion de precio: %p\n", (void *)&precio);
    printf("Direccion de inicial: %p\n", (void *)&inicial);

    /* Cada tipo tiene un tamaño distinto en memoria */
    printf("sizeof(int):   %zu bytes\n", sizeof(int));
    printf("sizeof(float): %zu bytes\n", sizeof(float));
    printf("sizeof(char):  %zu byte\n", sizeof(char));

    /* -----------------------------------------------
     * 3. Operador * (desreferencia)
     * ----------------------------------------------- */
    printf("\n=== OPERADOR * (DESREFERENCIA) ===\n");

    int numero = 42;
    int *p = &numero;

    printf("Antes: numero = %d\n", numero);
    *p = 100;  /* Modifica numero a traves del puntero */
    printf("Despues de *p = 100: numero = %d\n", numero);

    /* Lectura y escritura con el mismo puntero */
    printf("Lectura con *p:    %d\n", *p);
    printf("Escritura: *p += 5\n");
    *p += 5;
    printf("Resultado: numero = %d\n", numero);

    /* -----------------------------------------------
     * 4. Puntero NULL
     * ----------------------------------------------- */
    printf("\n=== PUNTERO NULL ===\n");

    int *vacio = NULL;
    printf("Puntero NULL: %p\n", (void *)vacio);

    /* Siempre verificar antes de desreferenciar */
    if (vacio == NULL) {
        printf("El puntero es NULL -- no se puede acceder\n");
    }

    int dato = 77;
    int *valido = &dato;
    if (valido != NULL) {
        printf("Puntero valido -- valor: %d\n", *valido);
    }

    /* -----------------------------------------------
     * 5. Impresion con %p
     * ----------------------------------------------- */
    printf("\n=== IMPRESION CON %%p ===\n");

    int a = 10, b = 20, c = 30;
    printf("Direcciones de variables locales:\n");
    printf("  &a = %p\n", (void *)&a);
    printf("  &b = %p\n", (void *)&b);
    printf("  &c = %p\n", (void *)&c);

    return 0;
}
