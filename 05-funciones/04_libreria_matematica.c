/*
 * ============================================================
 * Modulo 05 -- Funciones
 * Archivo: 04_libreria_matematica.c
 * ============================================================
 *
 * Este archivo muestra un mini-proyecto: una pequena libreria matematica.
 *
 * Una libreria es un conjunto de funciones relacionadas que podemos
 * reutilizar en diferentes partes de un programa.
 *
 * En este ejemplo creamos funciones para:
 *
 *   - obtener el menor de dos numeros
 *   - obtener el mayor de dos numeros
 *   - calcular un promedio
 *   - calcular una potencia
 *   - calcular valor absoluto
 *   - imprimir una tabla de multiplicar
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 04_libreria 04_libreria_matematica.c
 *
 * Ejecutar:
 *   Windows: 04_libreria.exe
 *   Linux/macOS: ./04_libreria
 */

#include <stdio.h>

int min(int a, int b);
int max(int a, int b);
double promedio(const double *datos, int cantidad);
double potencia(double base, int exp);
int valor_absoluto(int n);
void tabla_multiplicar(int numero, int hasta);

int main(void) {
    printf("=== LIBRERIA MATEMATICA ===\n\n");

    printf("min(10, 25) = %d\n", min(10, 25));
    printf("max(10, 25) = %d\n\n", max(10, 25));

    /*
     * Arreglo de notas.
     *
     * Los arreglos se estudian mas adelante, pero aqui lo usamos para
     * demostrar una funcion que recibe varios valores.
     */
    double notas[] = {8.5, 9.0, 7.5, 10.0, 6.5};
    int cantidad = 5;

    printf("Notas: ");
    for (int i = 0; i < cantidad; i++) {
        printf("%.1f ", notas[i]);
    }
    printf("\n");

    printf("Promedio = %.2f\n\n", promedio(notas, cantidad));

    printf("2 elevado a 10 = %.0f\n", potencia(2.0, 10));
    printf("3 elevado a 5  = %.0f\n\n", potencia(3.0, 5));

    printf("valor_absoluto(-42) = %d\n", valor_absoluto(-42));
    printf("valor_absoluto(15)  = %d\n\n", valor_absoluto(15));

    printf("Tabla del 7 hasta 10:\n");
    tabla_multiplicar(7, 10);

    return 0;
}

/*
 * Devuelve el menor de dos enteros.
 */
int min(int a, int b) {
    return (a < b) ? a : b;
}

/*
 * Devuelve el mayor de dos enteros.
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/*
 * Calcula el promedio de un arreglo de numeros.
 *
 * datos apunta al primer elemento del arreglo.
 * cantidad indica cuantos elementos se deben procesar.
 */
double promedio(const double *datos, int cantidad) {
    if (cantidad <= 0) {
        return 0.0;
    }

    double suma = 0.0;

    for (int i = 0; i < cantidad; i++) {
        suma += datos[i];
    }

    return suma / cantidad;
}

/*
 * Calcula base elevado a exp.
 *
 * Esta version usa un bucle en vez de recursividad.
 */
double potencia(double base, int exp) {
    double resultado = 1.0;

    for (int i = 0; i < exp; i++) {
        resultado *= base;
    }

    return resultado;
}

/*
 * Devuelve el valor absoluto.
 *
 * Si n es negativo, devuelve -n.
 * Si n ya es positivo o cero, devuelve n.
 */
int valor_absoluto(int n) {
    return (n < 0) ? -n : n;
}

/*
 * Imprime una tabla de multiplicar.
 *
 * Es void porque no necesita devolver un resultado. Su trabajo es
 * mostrar informacion en pantalla.
 */
void tabla_multiplicar(int numero, int hasta) {
    for (int i = 1; i <= hasta; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
}
