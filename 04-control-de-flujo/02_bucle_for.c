/*
 * ============================================================
 * Modulo 04 -- Control de Flujo
 * Archivo: 02_bucle_for.c
 * ============================================================
 *
 * Este archivo explica el bucle for en C.
 *
 * Un bucle sirve para repetir instrucciones varias veces sin tener
 * que escribir el mismo codigo una y otra vez.
 *
 * El bucle for se usa mucho cuando sabemos cuantas veces queremos
 * repetir una accion.
 *
 * Estructura general:
 *
 *   for (inicio; condicion; actualizacion) {
 *       instrucciones;
 *   }
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o bucle_for 02_bucle_for.c
 *
 * Ejecutar:
 *   Windows: bucle_for.exe
 *   Linux/macOS: ./bucle_for
 */

#include <stdio.h>

int main(void) {
    printf("=== BUCLE FOR EN C ===\n\n");

    /*
     * Conteo del 1 al 5.
     *
     * int i = 1  -> valor inicial
     * i <= 5     -> condicion para seguir repitiendo
     * i++        -> aumenta i en 1 despues de cada vuelta
     */
    printf("Conteo del 1 al 5:\n");

    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    /*
     * Tabla de multiplicar.
     *
     * El for evita escribir diez printf manualmente.
     */
    printf("\nTabla del 7:\n");

    for (int i = 1; i <= 10; i++) {
        printf("7 x %2d = %2d\n", i, 7 * i);
    }

    /*
     * Cuenta regresiva.
     *
     * En vez de i++, usamos i-- para disminuir el contador.
     */
    printf("\nCuenta regresiva:\n");

    for (int i = 5; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\nDespegue!\n");

    /*
     * Bucles anidados.
     *
     * Un bucle anidado es un bucle dentro de otro bucle.
     * Se usa mucho para tablas, matrices y patrones.
     */
    printf("\nTabla de multiplicar 3x3:\n");

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("%d*%d=%-4d", i, j, i * j);
        }
        printf("\n");
    }

    /*
     * Patron: triangulo de asteriscos.
     */
    printf("\nTriangulo de asteriscos:\n");

    for (int fila = 1; fila <= 5; fila++) {
        for (int columna = 0; columna < fila; columna++) {
            printf("*");
        }
        printf("\n");
    }

    /*
     * Patron: cuadrado.
     */
    printf("\nCuadrado de asteriscos 5x5:\n");

    int tamano = 5;

    for (int fila = 0; fila < tamano; fila++) {
        for (int columna = 0; columna < tamano; columna++) {
            printf("* ");
        }
        printf("\n");
    }

    /*
     * For con paso de 2.
     *
     * i += 2 significa que i aumenta de dos en dos.
     */
    printf("\nNumeros pares del 0 al 10:\n");

    for (int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
