/*
 * Modulo 05 — Funciones Basicas
 * Compilar: gcc -Wall -Wextra -std=c11 -o 01_basicas 01_funciones_basicas.c
 *
 * Temas: definicion de funciones, parametros, retorno, prototipos y void.
 */

#include <stdio.h>

/* --- Prototipos --- */

/* Suma dos enteros y devuelve el resultado */
int sumar(int a, int b);

/* Imprime un saludo (no retorna nada) */
void saludar(const char *nombre);

/* Calcula el area de un rectangulo */
double area_rectangulo(double base, double altura);

/* Determina si un numero es par (1 = si, 0 = no) */
int es_par(int n);

/* --- Funcion principal --- */

int main(void) {
    printf("=== FUNCIONES BASICAS ===\n\n");

    /* Funcion con retorno: sumar */
    int resultado = sumar(15, 27);
    printf("sumar(15, 27) = %d\n", resultado);

    /* Funcion void: saludar */
    saludar("Estudiante");

    /* Funcion con double */
    double area = area_rectangulo(8.0, 5.5);
    printf("Area del rectangulo (base=8, altura=5.5) = %.2f\n", area);

    /* Funcion con retorno booleano */
    printf("10 es par? %d\n", es_par(10));
    printf("7  es par? %d\n", es_par(7));

    return 0;
}

/* --- Implementaciones --- */

/*
 * sumar — Suma dos enteros.
 * Recibe: a y b como parametros.
 * Retorna: la suma de ambos.
 */
int sumar(int a, int b) {
    return a + b;
}

/*
 * saludar — Imprime un saludo personalizado.
 * Recibe: nombre como cadena de texto.
 * Retorna: nada (void).
 */
void saludar(const char *nombre) {
    printf("Hola, %s! Bienvenido al curso de C.\n", nombre);
}

/*
 * area_rectangulo — Calcula el area de un rectangulo.
 * Recibe: base y altura como double.
 * Retorna: el area calculada.
 */
double area_rectangulo(double base, double altura) {
    return base * altura;
}

/*
 * es_par — Determina si un numero es par.
 * Recibe: n como entero.
 * Retorna: 1 si es par, 0 si es impar.
 */
int es_par(int n) {
    return n % 2 == 0;
}
