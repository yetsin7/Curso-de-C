/*
 * ============================================================
 * Modulo 05 -- Funciones
 * Archivo: 02_paso_por_valor.c
 * ============================================================
 *
 * Este archivo explica una idea muy importante en C:
 * la diferencia entre paso por valor y paso por referencia.
 *
 * Paso por valor:
 *   La funcion recibe una copia del dato. Si modifica esa copia,
 *   la variable original no cambia.
 *
 * Paso por referencia usando punteros:
 *   La funcion recibe la direccion de memoria de la variable original.
 *   Entonces puede modificar directamente el valor original.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 02_valor 02_paso_por_valor.c
 *
 * Ejecutar:
 *   Windows: 02_valor.exe
 *   Linux/macOS: ./02_valor
 */

#include <stdio.h>

void intentar_cambiar(int numero);
void cambiar_real(int *numero);
void intercambiar(int *a, int *b);

int main(void) {
    printf("=== PASO POR VALOR ===\n");

    /*
     * x tiene valor 10.
     * Cuando llamamos intentar_cambiar(x), la funcion recibe una copia.
     */
    int x = 10;

    printf("x antes de intentar_cambiar: %d\n", x);
    intentar_cambiar(x);
    printf("x despues de intentar_cambiar: %d\n", x);
    printf("No cambio porque la funcion modifico solo una copia.\n\n");

    printf("=== PASO POR REFERENCIA CON PUNTEROS ===\n");

    /*
     * y tambien empieza con valor 10.
     *
     * Al llamar cambiar_real(&y), enviamos la direccion de y.
     * El operador & obtiene la direccion de memoria de una variable.
     */
    int y = 10;

    printf("y antes de cambiar_real: %d\n", y);
    cambiar_real(&y);
    printf("y despues de cambiar_real: %d\n", y);
    printf("Si cambio porque la funcion recibio la direccion de y.\n\n");

    printf("=== INTERCAMBIAR VALORES ===\n");

    /*
     * Para intercambiar dos variables reales, necesitamos modificar ambas.
     * Por eso enviamos sus direcciones usando &.
     */
    int a = 100;
    int b = 200;

    printf("Antes:   a = %d, b = %d\n", a, b);
    intercambiar(&a, &b);
    printf("Despues: a = %d, b = %d\n", a, b);

    return 0;
}

/*
 * Esta funcion recibe una copia.
 *
 * Aunque numero cambie a 99, la variable original de main no cambia.
 */
void intentar_cambiar(int numero) {
    numero = 99;
}

/*
 * Esta funcion recibe un puntero a entero.
 *
 * numero contiene una direccion de memoria.
 * *numero accede al valor que vive en esa direccion.
 */
void cambiar_real(int *numero) {
    *numero = 99;
}

/*
 * Esta funcion intercambia dos valores reales.
 *
 * temporal guarda temporalmente el primer valor para no perderlo.
 */
void intercambiar(int *a, int *b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}
