/*
 * ============================================================
 * Modulo 05 -- Funciones
 * Archivo: 01_funciones_basicas.c
 * ============================================================
 *
 * Este archivo explica que son las funciones en C.
 *
 * Una funcion es un bloque de codigo con nombre que realiza una tarea.
 * Sirve para organizar el programa, evitar repetir codigo y hacer que
 * cada parte tenga una responsabilidad clara.
 *
 * Una funcion puede:
 *
 *   - Recibir datos de entrada, llamados parametros.
 *   - Hacer un calculo o una accion.
 *   - Devolver un resultado con return.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 01_basicas 01_funciones_basicas.c
 *
 * Ejecutar:
 *   Windows: 01_basicas.exe
 *   Linux/macOS: ./01_basicas
 */

#include <stdio.h>

/*
 * Prototipos de funciones.
 *
 * Un prototipo le avisa al compilador que una funcion existe, aunque
 * su codigo completo aparezca mas abajo en el archivo.
 */
int sumar(int a, int b);
void saludar(const char *nombre);
double area_rectangulo(double base, double altura);
int es_par(int n);

int main(void) {
    printf("=== FUNCIONES BASICAS ===\n\n");

    /*
     * sumar recibe dos enteros y devuelve otro entero.
     */
    int resultado = sumar(15, 27);
    printf("sumar(15, 27) = %d\n", resultado);

    /*
     * saludar no devuelve nada. Solo muestra un mensaje.
     */
    saludar("Estudiante");

    /*
     * area_rectangulo recibe dos double y devuelve un double.
     */
    double area = area_rectangulo(8.0, 5.5);
    printf("Area del rectangulo = %.2f\n", area);

    /*
     * es_par devuelve 1 si el numero es par y 0 si no lo es.
     */
    printf("10 es par? %d\n", es_par(10));
    printf("7 es par?  %d\n", es_par(7));

    return 0;
}

/*
 * Esta funcion suma dos enteros.
 *
 * Parametros:
 *   a: primer numero
 *   b: segundo numero
 *
 * Retorno:
 *   la suma de a y b
 */
int sumar(int a, int b) {
    return a + b;
}

/*
 * Esta funcion imprime un saludo.
 *
 * void significa que la funcion no devuelve ningun valor.
 */
void saludar(const char *nombre) {
    printf("Hola, %s! Bienvenido al curso de C.\n", nombre);
}

/*
 * Esta funcion calcula el area de un rectangulo.
 *
 * Formula:
 *   area = base * altura
 */
double area_rectangulo(double base, double altura) {
    return base * altura;
}

/*
 * Esta funcion revisa si un numero es par.
 *
 * Un numero es par si el residuo de dividirlo entre 2 es 0.
 */
int es_par(int n) {
    return n % 2 == 0;
}
