/*
 * ============================================================
 * Modulo 05 -- Funciones
 * Archivo: 03_recursividad.c
 * ============================================================
 *
 * Este archivo explica la recursividad.
 *
 * Una funcion recursiva es una funcion que se llama a si misma para
 * resolver un problema mas pequeno.
 *
 * Toda recursion necesita dos partes:
 *
 *   1. Caso base:
 *      Es la condicion que detiene la recursion.
 *
 *   2. Caso recursivo:
 *      Es la parte donde la funcion se llama a si misma.
 *
 * Si una funcion recursiva no tiene caso base, puede llamarse para
 * siempre hasta agotar la memoria de la pila de ejecucion.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 03_recursividad 03_recursividad.c
 *
 * Ejecutar:
 *   Windows: 03_recursividad.exe
 *   Linux/macOS: ./03_recursividad
 */

#include <stdio.h>

long long factorial(int n);
int fibonacci(int n);
long long factorial_traza(int n, int nivel);

int main(void) {
    printf("=== FACTORIAL RECURSIVO ===\n");

    /*
     * El factorial de un numero se calcula multiplicando desde ese
     * numero hasta 1.
     *
     * Ejemplo:
     *   5! = 5 * 4 * 3 * 2 * 1 = 120
     */
    for (int i = 0; i <= 7; i++) {
        printf("%d! = %lld\n", i, factorial(i));
    }

    printf("\n=== FIBONACCI RECURSIVO ===\n");

    /*
     * En Fibonacci, cada numero se obtiene sumando los dos anteriores.
     *
     * F(0) = 0
     * F(1) = 1
     * F(n) = F(n - 1) + F(n - 2)
     */
    printf("Primeros 10 numeros: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    printf("\n=== TRAZA DE LA PILA PARA 3! ===\n");

    /*
     * Esta version imprime las llamadas para que veas como la funcion
     * baja hasta el caso base y luego regresa con los resultados.
     */
    factorial_traza(3, 0);

    return 0;
}

/*
 * Calcula el factorial de n.
 *
 * Caso base:
 *   Si n es 0 o 1, el resultado es 1.
 *
 * Caso recursivo:
 *   n! = n * (n - 1)!
 */
long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return (long long)n * factorial(n - 1);
}

/*
 * Calcula el numero Fibonacci en la posicion n.
 *
 * Esta version es facil de entender, pero no es eficiente para numeros
 * grandes porque repite muchos calculos.
 */
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

/*
 * Muestra una traza del factorial.
 *
 * nivel indica que tan profunda es la llamada recursiva. Lo usamos
 * solo para imprimir espacios y visualizar mejor el proceso.
 */
long long factorial_traza(int n, int nivel) {
    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
    printf("|-- factorial(%d)\n", n);

    if (n <= 1) {
        for (int i = 0; i < nivel; i++) {
            printf("  ");
        }
        printf("|   retorna 1 porque llegamos al caso base\n");
        return 1;
    }

    long long resultado = (long long)n * factorial_traza(n - 1, nivel + 1);

    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
    printf("|   retorna %lld\n", resultado);

    return resultado;
}
