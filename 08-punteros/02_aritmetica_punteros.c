/*
 * ============================================================
 * Modulo 08 -- Punteros
 * Archivo: 02_aritmetica_punteros.c
 * ============================================================
 *
 * Este archivo explica la aritmetica de punteros.
 *
 * La aritmetica de punteros permite avanzar o retroceder por posiciones
 * de memoria usando un puntero.
 *
 * Idea clave:
 *
 *   puntero + 1 no siempre avanza 1 byte.
 *
 * Avanza el tamano del tipo al que apunta.
 *
 * Ejemplo:
 *
 *   int *p;
 *   p + 1 avanza sizeof(int) bytes.
 *
 *   double *d;
 *   d + 1 avanza sizeof(double) bytes.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 02_aritmetica 02_aritmetica_punteros.c
 *
 * Ejecutar:
 *   Windows: 02_aritmetica.exe
 *   Linux/macOS: ./02_aritmetica
 */

#include <stdio.h>

/*
 * Recorre un arreglo usando punteros.
 *
 * inicio apunta al primer elemento.
 * fin apunta una posicion despues del ultimo elemento.
 */
void imprimirArreglo(const int *inicio, int tamano) {
    const int *fin = inicio + tamano;

    while (inicio < fin) {
        printf("  %d\n", *inicio);
        inicio++;
    }
}

int main(void) {
    printf("=== AVANCE SEGUN TIPO ===\n");

    int arrInt[3] = {1, 2, 3};
    char arrChar[3] = {'A', 'B', 'C'};
    double arrDbl[3] = {1.1, 2.2, 3.3};

    printf("int:    %p -> %p (diferencia: %ld bytes)\n",
           (void *)&arrInt[0], (void *)&arrInt[1],
           (long)((char *)&arrInt[1] - (char *)&arrInt[0]));

    printf("char:   %p -> %p (diferencia: %ld bytes)\n",
           (void *)&arrChar[0], (void *)&arrChar[1],
           (long)((char *)&arrChar[1] - (char *)&arrChar[0]));

    printf("double: %p -> %p (diferencia: %ld bytes)\n",
           (void *)&arrDbl[0], (void *)&arrDbl[1],
           (long)((char *)&arrDbl[1] - (char *)&arrDbl[0]));

    printf("\n=== RECORRIDO DE ARREGLO ===\n");

    /*
     * En C, el nombre de un arreglo suele comportarse como un puntero
     * al primer elemento del arreglo.
     */
    int notas[] = {85, 92, 78, 95, 88};
    int tamanio = sizeof(notas) / sizeof(notas[0]);
    int *ptr = notas;

    printf("Con notacion de puntero:\n");

    for (int i = 0; i < tamanio; i++) {
        printf("  *(ptr + %d) = %d\n", i, *(ptr + i));
    }

    printf("\nCon funcion auxiliar:\n");
    imprimirArreglo(notas, tamanio);

    printf("\n=== DIFERENCIA ENTRE PUNTEROS ===\n");

    /*
     * La resta de dos punteros del mismo arreglo indica cuantos elementos
     * hay entre ellos, no cuantos bytes.
     */
    int datos[] = {10, 20, 30, 40, 50};
    int *inicio = datos;
    int *final = datos + 4;

    printf("Inicio: %p, Final: %p\n", (void *)inicio, (void *)final);
    printf("Diferencia en elementos: %ld\n", (long)(final - inicio));

    int *medio = datos + 2;

    printf("Elementos entre inicio y medio: %ld\n", (long)(medio - inicio));
    printf("Elementos entre medio y final:  %ld\n", (long)(final - medio));

    printf("\n=== PUNTEROS CONST ===\n");

    int valor = 42;
    int otro = 99;

    /*
     * Puntero a dato constante.
     *
     * No permite modificar el valor usando el puntero, pero si permite
     * cambiar a que direccion apunta.
     */
    const int *pConst = &valor;
    printf("pConst apunta a: %d\n", *pConst);

    pConst = &otro;
    printf("Ahora pConst apunta a: %d\n", *pConst);

    /*
     * Puntero constante.
     *
     * No permite cambiar la direccion del puntero, pero si permite
     * modificar el valor apuntado.
     */
    int *const ptrFijo = &valor;

    printf("ptrFijo apunta a: %d\n", *ptrFijo);

    *ptrFijo = 77;
    printf("Despues de *ptrFijo = 77: valor = %d\n", valor);

    return 0;
}
