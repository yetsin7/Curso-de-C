/*
 * ============================================================
 * Modulo 03 -- Operadores
 * Archivo: 01_operadores_aritmeticos.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este programa explica los operadores aritmeticos en C.
 *
 * Un operador es un simbolo que le dice al programa que debe hacer
 * una operacion con uno o mas valores.
 *
 * Ejemplos:
 *
 *   +  suma
 *   -  resta
 *   *  multiplicacion
 *   /  division
 *   %  modulo o residuo
 *
 * ------------------------------------------------------------
 * Idea importante
 * ------------------------------------------------------------
 *
 * En C, el tipo de dato influye en el resultado.
 *
 * Por ejemplo:
 *
 *   5 / 2
 *
 * Si ambos valores son enteros, el resultado tambien sera entero.
 * Por eso 5 / 2 da 2, no 2.5.
 *
 * Para obtener decimales, al menos uno de los valores debe ser decimal
 * o debes usar un cast.
 *
 * ------------------------------------------------------------
 * Compilar
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o 01_aritmeticos 01_operadores_aritmeticos.c
 *
 * Ejecutar en Windows:
 *
 *   01_aritmeticos.exe
 *
 * Ejecutar en Linux/macOS:
 *
 *   ./01_aritmeticos
 *
 */

#include <stdio.h>

int main(void) {
    printf("=== OPERADORES ARITMETICOS ===\n");

    /*
     * a y b son variables enteras.
     *
     * Las usamos para demostrar operaciones basicas.
     */
    int a = 10;
    int b = 3;

    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);

    /*
     * Division entera:
     * Como a y b son int, el resultado de a / b tambien es int.
     * La parte decimal se pierde.
     */
    printf("%d / %d = %d (division entera)\n", a, b, a / b);

    /*
     * Modulo o residuo:
     * El operador % devuelve lo que sobra despues de una division entera.
     *
     * 10 / 3 da 3 y sobra 1. Por eso 10 % 3 es 1.
     */
    printf("%d %% %d = %d (modulo o residuo)\n", a, b, a % b);

    /*
     * Division entera vs division flotante.
     */
    printf("\n--- Division entera vs flotante ---\n");
    printf("5 / 2 usando enteros       = %d\n", 5 / 2);
    printf("5.0 / 2 usando decimal     = %.2f\n", 5.0 / 2);
    printf("(double)5 / 2 usando cast  = %.2f\n", (double)5 / 2);

    /*
     * Asignacion compuesta.
     *
     * Sirve para actualizar una variable usando su valor anterior.
     *
     * x += 5 significa lo mismo que x = x + 5.
     */
    printf("\n=== ASIGNACION COMPUESTA ===\n");

    int x = 10;
    printf("x inicial = %d\n", x);

    x += 5;
    printf("x += 5  equivale a x = x + 5  => %d\n", x);

    x -= 3;
    printf("x -= 3  equivale a x = x - 3  => %d\n", x);

    x *= 2;
    printf("x *= 2  equivale a x = x * 2  => %d\n", x);

    x /= 4;
    printf("x /= 4  equivale a x = x / 4  => %d\n", x);

    /*
     * Incremento y decremento.
     *
     * ++ aumenta una variable en 1.
     * -- disminuye una variable en 1.
     *
     * Hay dos formas:
     *
     * n++ usa el valor actual y despues incrementa.
     * ++n incrementa primero y despues usa el valor nuevo.
     */
    printf("\n=== INCREMENTO Y DECREMENTO ===\n");

    int n = 5;
    printf("n = %d\n", n);

    printf("n++ muestra %d, pero despues n vale %d\n", n, n + 1);
    n++;
    printf("Ahora n realmente vale %d\n", n);

    ++n;
    printf("Despues de ++n, n vale %d\n", n);

    n--;
    printf("Despues de n--, n vale %d\n", n);

    --n;
    printf("Despues de --n, n vale %d\n", n);

    /*
     * Recomendacion:
     * Para principiantes, evita escribir expresiones confusas como:
     *
     *   printf("%d %d", n++, ++n);
     *
     * Es mejor separar las operaciones en varias lineas para que el
     * codigo sea claro y facil de entender.
     */

    return 0;
}
