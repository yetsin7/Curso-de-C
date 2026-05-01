/*
 * Modulo 08 -- Aritmetica de punteros
 * Compilar: gcc -Wall -Wextra -std=c11 -o 02_aritmetica 02_aritmetica_punteros.c
 *
 * Demuestra:
 *   - Pointer + 1 avanza sizeof(tipo) bytes
 *   - Recorrido de arreglos con punteros
 *   - Diferencia entre punteros
 *   - Punteros const
 */

#include <stdio.h>

/* Recorre un arreglo usando aritmetica de punteros */
void imprimirArreglo(const int *inicio, int tamano) {
    const int *fin = inicio + tamano;
    while (inicio < fin) {
        printf("  %d\n", *inicio);
        inicio++;  /* Avanza sizeof(int) bytes */
    }
}

int main(void) {
    /* -----------------------------------------------
     * 1. Pointer + 1 avanza por sizeof(tipo)
     * ----------------------------------------------- */
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

    /* -----------------------------------------------
     * 2. Recorrido de arreglos con punteros
     * ----------------------------------------------- */
    printf("\n=== RECORRIDO DE ARREGLO ===\n");

    int notas[] = {85, 92, 78, 95, 88};
    int tamanio = sizeof(notas) / sizeof(notas[0]);
    int *ptr = notas;  /* Equivale a &notas[0] */

    printf("Con notacion de puntero:\n");
    for (int i = 0; i < tamanio; i++) {
        printf("  *(ptr + %d) = %d\n", i, *(ptr + i));
    }

    printf("\nCon funcion auxiliar:\n");
    imprimirArreglo(notas, tamanio);

    /* -----------------------------------------------
     * 3. Diferencia entre punteros
     * ----------------------------------------------- */
    printf("\n=== DIFERENCIA ENTRE PUNTEROS ===\n");

    int datos[] = {10, 20, 30, 40, 50};
    int *inicio = datos;
    int *final = datos + 4;

    printf("Inicio: %p, Final: %p\n", (void *)inicio, (void *)final);
    printf("Diferencia en elementos: %ld\n", (long)(final - inicio));

    /* Distancia entre dos elementos cualesquiera */
    int *medio = datos + 2;
    printf("Elementos entre inicio y medio: %ld\n", (long)(medio - inicio));
    printf("Elementos entre medio y final:  %ld\n", (long)(final - medio));

    /* -----------------------------------------------
     * 4. Punteros const
     * ----------------------------------------------- */
    printf("\n=== PUNTEROS CONST ===\n");

    int valor = 42;
    int otro = 99;

    /* Puntero a dato constante: no puede modificar el valor */
    const int *pConst = &valor;
    printf("pConst apunta a: %d\n", *pConst);
    /* *pConst = 10;  ERROR: no se puede modificar */

    pConst = &otro;  /* Si se puede cambiar la direccion */
    printf("Ahora pConst apunta a: %d\n", *pConst);

    /* Puntero constante: no puede cambiar de direccion */
    int *const ptrFijo = &valor;
    printf("ptrFijo apunta a: %d\n", *ptrFijo);
    *ptrFijo = 77;  /* Si se puede modificar el valor */
    printf("Despues de *ptrFijo = 77: valor = %d\n", valor);
    /* ptrFijo = &otro;  ERROR: no se puede cambiar la direccion */

    return 0;
}
