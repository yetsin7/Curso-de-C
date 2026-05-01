/*
 * Modulo 05 — Libreria Matematica (Mini-Proyecto)
 * Compilar: gcc -Wall -Wextra -std=c11 -o 04_libreria 04_libreria_matematica.c
 *
 * Mini-proyecto: libreria con funciones de utilidad matematica.
 * Demuestra definicion, prototipos, void, retorno y paso por valor.
 */

#include <stdio.h>

/* --- Prototipos de la libreria --- */

/* Devuelve el menor de dos enteros */
int min(int a, int b);

/* Devuelve el mayor de dos enteros */
int max(int a, int b);

/* Calcula el promedio de un arreglo de double */
double promedio(const double *datos, int cantidad);

/* Eleva base a la potencia exp (entero no negativo) */
double potencia(double base, int exp);

/* Valor absoluto de un entero */
int valor_absoluto(int n);

/* Imprime una tabla de multiplicar (void) */
void tabla_multiplicar(int numero, int hasta);

/* --- Funcion principal (demo de la libreria) --- */

int main(void) {
    printf("=== LIBRERIA MATEMATICA ===\n\n");

    /* min y max */
    printf("min(10, 25) = %d\n", min(10, 25));
    printf("max(10, 25) = %d\n\n", max(10, 25));

    /* promedio */
    double notas[] = {8.5, 9.0, 7.5, 10.0, 6.5};
    int cantidad = 5;
    printf("Notas: ");
    for (int i = 0; i < cantidad; i++) printf("%.1f ", notas[i]);
    printf("\n");
    printf("Promedio = %.2f\n\n", promedio(notas, cantidad));

    /* potencia */
    printf("2^10 = %.0f\n", potencia(2.0, 10));
    printf("3^5  = %.0f\n\n", potencia(3.0, 5));

    /* valor absoluto */
    printf("valor_absoluto(-42) = %d\n", valor_absoluto(-42));
    printf("valor_absoluto(15)  = %d\n\n", valor_absoluto(15));

    /* tabla de multiplicar */
    printf("Tabla del 7 (hasta 10):\n");
    tabla_multiplicar(7, 10);

    return 0;
}

/* --- Implementaciones --- */

/*
 * min — Retorna el menor de dos enteros.
 * Recibe: a y b como parametros.
 * Retorna: el valor mas pequeno.
 */
int min(int a, int b) {
    return a < b ? a : b;
}

/*
 * max — Retorna el mayor de dos enteros.
 * Recibe: a y b como parametros.
 * Retorna: el valor mas grande.
 */
int max(int a, int b) {
    return a > b ? a : b;
}

/*
 * promedio — Calcula el promedio de un arreglo de numeros.
 * Recibe: puntero al arreglo y cantidad de elementos.
 * Retorna: el promedio como double.
 */
double promedio(const double *datos, int cantidad) {
    if (cantidad <= 0) return 0.0;
    double suma = 0.0;
    for (int i = 0; i < cantidad; i++) {
        suma += datos[i];
    }
    return suma / cantidad;
}

/*
 * potencia — Calcula base elevado a exp (iterativo).
 * Recibe: base (double) y exp (entero no negativo).
 * Retorna: base^exp.
 */
double potencia(double base, int exp) {
    double resultado = 1.0;
    for (int i = 0; i < exp; i++) {
        resultado *= base;
    }
    return resultado;
}

/*
 * valor_absoluto — Retorna el valor absoluto de un entero.
 * Recibe: n como entero.
 * Retorna: n si es positivo, -n si es negativo.
 */
int valor_absoluto(int n) {
    return n < 0 ? -n : n;
}

/*
 * tabla_multiplicar — Imprime la tabla de multiplicar de un numero.
 * Recibe: numero base y hasta que multiplicador imprimir.
 * Retorna: nada (void).
 */
void tabla_multiplicar(int numero, int hasta) {
    for (int i = 1; i <= hasta; i++) {
        printf("  %d x %d = %d\n", numero, i, numero * i);
    }
}
