/*
 * Modulo 08 -- Punteros a funciones
 * Compilar: gcc -Wall -Wextra -std=c11 -o 03_funciones 03_punteros_a_funciones.c
 *
 * Demuestra:
 *   - Declaracion de puntero a funcion
 *   - Patron callback
 *   - Arreglo de punteros a funciones
 *   - Caso practico: selector de operaciones
 */

#include <stdio.h>

/* Operaciones aritmeticas basicas */
int sumar(int a, int b) { return a + b; }
int restar(int a, int b) { return a - b; }
int multiplicar(int a, int b) { return a * b; }

/* Funcion que recibe un callback */
void ejecutarCallback(int a, int b, int (*operacion)(int, int), const char *nombre) {
    int resultado = operacion(a, b);
    printf("  %s(%d, %d) = %d\n", nombre, a, b, resultado);
}

int main(void) {
    /* -----------------------------------------------
     * 1. Declaracion de puntero a funcion
     * ----------------------------------------------- */
    printf("=== PUNTERO A FUNCION ===\n");

    /* int (*fn)(int, int) -- puntero a funcion que recibe dos int y devuelve int */
    int (*fn)(int, int);

    fn = sumar;
    printf("5 + 3 = %d\n", fn(5, 3));

    fn = multiplicar;
    printf("5 * 3 = %d\n", fn(5, 3));

    /* -----------------------------------------------
     * 2. Patron callback
     * ----------------------------------------------- */
    printf("\n=== PATRON CALLBACK ===\n");

    printf("Callbacks con diferentes operaciones:\n");
    ejecutarCallback(10, 4, sumar, "sumar");
    ejecutarCallback(10, 4, restar, "restar");
    ejecutarCallback(10, 4, multiplicar, "multiplicar");

    /* -----------------------------------------------
     * 3. Arreglo de punteros a funciones
     * ----------------------------------------------- */
    printf("\n=== ARREGLO DE PUNTEROS A FUNCIONES ===\n");

    /* Tabla de operaciones: cada indice es una operacion */
    int (*operaciones[])(int, int) = {sumar, restar, multiplicar};
    const char *nombres[] = {"Suma", "Resta", "Multiplicacion"};
    int totalOps = sizeof(operaciones) / sizeof(operaciones[0]);

    int x = 8, y = 3;
    for (int i = 0; i < totalOps; i++) {
        printf("  %s: %d\n", nombres[i], operaciones[i](x, y));
    }

    /* -----------------------------------------------
     * 4. Caso practico: selector de operaciones
     * ----------------------------------------------- */
    printf("\n=== SELECTOR DE OPERACIONES ===\n");

    printf("Introduzca dos numeros y elija operacion (1=Suma, 2=Resta, 3=Multiplicacion)\n");

    int num1 = 15, num2 = 6;
    int opcion = 2;  /* Simulamos entrada del usuario */

    printf("Numeros: %d y %d, Opcion: %d\n", num1, num2, opcion);

    if (opcion >= 1 && opcion <= totalOps) {
        int resultado = operaciones[opcion - 1](num1, num2);
        printf("Resultado: %s(%d, %d) = %d\n",
               nombres[opcion - 1], num1, num2, resultado);
    } else {
        printf("Opcion invalida\n");
    }

    return 0;
}
