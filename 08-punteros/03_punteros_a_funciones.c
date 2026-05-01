/*
 * ============================================================
 * Modulo 08 -- Punteros
 * Archivo: 03_punteros_a_funciones.c
 * ============================================================
 *
 * Este archivo explica los punteros a funciones.
 *
 * Un puntero a funcion guarda la direccion de una funcion, no la
 * direccion de una variable normal.
 *
 * Esto permite elegir que funcion ejecutar durante la ejecucion del
 * programa.
 *
 * Se usan en patrones como callbacks, tablas de operaciones, menus y
 * sistemas donde una accion puede cambiar dinamicamente.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 03_funciones 03_punteros_a_funciones.c
 *
 * Ejecutar:
 *   Windows: 03_funciones.exe
 *   Linux/macOS: ./03_funciones
 */

#include <stdio.h>

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

/*
 * Esta funcion recibe otra funcion como parametro.
 *
 * operacion es un puntero a una funcion que recibe dos int y devuelve int.
 */
void ejecutarCallback(int a, int b, int (*operacion)(int, int), const char *nombre) {
    int resultado = operacion(a, b);
    printf("%s(%d, %d) = %d\n", nombre, a, b, resultado);
}

int main(void) {
    printf("=== PUNTERO A FUNCION ===\n");

    /*
     * Declaracion:
     *
     * int (*fn)(int, int);
     *
     * Significa:
     * fn es un puntero a una funcion que recibe dos int y devuelve int.
     */
    int (*fn)(int, int);

    fn = sumar;
    printf("5 + 3 = %d\n", fn(5, 3));

    fn = multiplicar;
    printf("5 * 3 = %d\n", fn(5, 3));

    printf("\n=== CALLBACK ===\n");

    /*
     * Un callback es una funcion que se pasa como argumento a otra funcion.
     */
    ejecutarCallback(10, 4, sumar, "sumar");
    ejecutarCallback(10, 4, restar, "restar");
    ejecutarCallback(10, 4, multiplicar, "multiplicar");

    printf("\n=== ARREGLO DE PUNTEROS A FUNCIONES ===\n");

    /*
     * Este arreglo guarda varias funciones con la misma firma.
     */
    int (*operaciones[])(int, int) = {sumar, restar, multiplicar};
    const char *nombres[] = {"Suma", "Resta", "Multiplicacion"};
    int totalOps = sizeof(operaciones) / sizeof(operaciones[0]);

    int x = 8;
    int y = 3;

    for (int i = 0; i < totalOps; i++) {
        printf("%s: %d\n", nombres[i], operaciones[i](x, y));
    }

    printf("\n=== SELECTOR DE OPERACIONES ===\n");

    /*
     * Simulamos una opcion elegida por el usuario.
     *
     * opcion 1 usa sumar.
     * opcion 2 usa restar.
     * opcion 3 usa multiplicar.
     */
    int num1 = 15;
    int num2 = 6;
    int opcion = 2;

    printf("Numeros: %d y %d, opcion: %d\n", num1, num2, opcion);

    if (opcion >= 1 && opcion <= totalOps) {
        int resultado = operaciones[opcion - 1](num1, num2);

        printf("Resultado: %s(%d, %d) = %d\n",
               nombres[opcion - 1], num1, num2, resultado);
    } else {
        printf("Opcion invalida\n");
    }

    return 0;
}
