/*
 * Modulo 05 — Recursividad
 * Compilar: gcc -Wall -Wextra -std=c11 -o 03_recursividad 03_recursividad.c
 *
 * Temas: factorial recursivo, Fibonacci recursivo, caso base y pila de ejecucion.
 */

#include <stdio.h>

/* --- Prototipos --- */

/* Calcula n! de forma recursiva */
long long factorial(int n);

/* Calcula el n-esimo numero de Fibonacci */
int fibonacci(int n);

/* Factorial con traza para visualizar la pila */
long long factorial_traza(int n, int nivel);

/* --- Funcion principal --- */

int main(void) {
    printf("=== FACTORIAL RECURSIVO ===\n");
    for (int i = 0; i <= 7; i++) {
        printf("%d! = %lld\n", i, factorial(i));
    }

    printf("\n=== FIBONACCI RECURSIVO ===\n");
    printf("Primeros 10 numeros: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    printf("\n=== TRAZA DE LA PILA (3!) ===\n");
    factorial_traza(3, 0);

    return 0;
}

/* --- Implementaciones --- */

/*
 * factorial — Calcula n! recursivamente.
 * Caso base: 0! = 1, 1! = 1.
 * Recibe: n (numero no negativo).
 * Retorna: n! como long long.
 */
long long factorial(int n) {
    if (n <= 1) {
        return 1;  /* Caso base: evita recursión infinita */
    }
    return (long long)n * factorial(n - 1);
}

/*
 * fibonacci — Devuelve el n-esimo numero de Fibonacci.
 * Caso base: F(0)=0, F(1)=1.
 * Recibe: n (posicion en la serie).
 * Retorna: el numero correspondiente.
 */
int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/*
 * factorial_traza — Calcula factorial imprimiendo cada llamada.
 * Sirve para visualizar como funciona la pila de ejecucion.
 * Recibe: n (numero) y nivel (profundidad de la llamada).
 * Retorna: n! calculado.
 */
long long factorial_traza(int n, int nivel) {
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("|-- factorial(%d)\n", n);

    if (n <= 1) {
        for (int i = 0; i < nivel; i++) printf("  ");
        printf("|   -> retorna 1 (caso base)\n");
        return 1;
    }

    long long resultado = (long long)n * factorial_traza(n - 1, nivel + 1);

    for (int i = 0; i < nivel; i++) printf("  ");
    printf("|   -> retorna %lld\n", resultado);
    return resultado;
}
