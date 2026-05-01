/*
 * ============================================================
 * Modulo 06 -- Arreglos y Strings
 * Archivo: 01_arreglos_unidimensionales.c
 * ============================================================
 *
 * Este archivo explica los arreglos de una dimension en C.
 *
 * Un arreglo es una coleccion de varios valores del mismo tipo guardados
 * bajo un mismo nombre.
 *
 * Ejemplo:
 *
 *   int notas[5] = {85, 92, 78, 95, 88};
 *
 * Eso significa que notas guarda 5 numeros enteros.
 *
 * Cada elemento se accede usando un indice. En C, los indices empiezan
 * en 0, no en 1.
 *
 *   notas[0] es el primer elemento.
 *   notas[4] es el quinto elemento.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 01_arreglos_unidimensionales 01_arreglos_unidimensionales.c
 *
 * Ejecutar:
 *   Windows: 01_arreglos_unidimensionales.exe
 *   Linux/macOS: ./01_arreglos_unidimensionales
 */

#include <stdio.h>

/*
 * Imprime todos los elementos de un arreglo entero.
 *
 * arr[] representa el arreglo.
 * tamano indica cuantos elementos tiene el arreglo.
 */
void imprimirArreglo(const int arr[], int tamano) {
    printf("[");

    for (int i = 0; i < tamano; i++) {
        printf("%d", arr[i]);

        if (i < tamano - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}

/*
 * Calcula el promedio de los elementos de un arreglo.
 */
double calcularPromedio(const int arr[], int tamano) {
    int suma = 0;

    for (int i = 0; i < tamano; i++) {
        suma += arr[i];
    }

    return (double)suma / tamano;
}

/*
 * Busca un valor dentro del arreglo.
 *
 * Si lo encuentra, devuelve el indice donde esta.
 * Si no lo encuentra, devuelve -1.
 */
int buscarValor(const int arr[], int tamano, int objetivo) {
    for (int i = 0; i < tamano; i++) {
        if (arr[i] == objetivo) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    printf("=== ARREGLOS UNIDIMENSIONALES ===\n\n");

    /*
     * Forma 1:
     * Declarar un arreglo indicando su tamano y sus valores iniciales.
     */
    int notas[5] = {85, 92, 78, 95, 88};

    printf("Notas inicializadas: ");
    imprimirArreglo(notas, 5);

    /*
     * Forma 2:
     * El compilador puede calcular el tamano si le damos los valores.
     */
    int edades[] = {20, 25, 30, 35, 40};
    int tamEdades = sizeof(edades) / sizeof(edades[0]);

    printf("Edades: ");
    imprimirArreglo(edades, tamEdades);

    /*
     * Forma 3:
     * Inicializar todo en cero.
     */
    int ceros[5] = {0};

    printf("Ceros: ");
    imprimirArreglo(ceros, 5);

    /*
     * Acceso por indice.
     *
     * Recuerda: el primer elemento esta en el indice 0.
     */
    printf("\n=== ACCESO POR INDICE ===\n");

    printf("Primera nota: %d\n", notas[0]);
    printf("Ultima nota: %d\n", notas[4]);

    /*
     * Modificar un elemento del arreglo.
     */
    notas[2] = 82;

    printf("Notas tras modificar indice 2: ");
    imprimirArreglo(notas, 5);

    /*
     * Recorrer un arreglo con for.
     */
    printf("\n=== RECORRIDO CON BUCLE ===\n");

    for (int i = 0; i < 5; i++) {
        printf("Elemento [%d] = %d\n", i, notas[i]);
    }

    /*
     * Usar arreglos como parametros de funciones.
     */
    printf("\n=== FUNCIONES CON ARREGLOS ===\n");

    double promedio = calcularPromedio(notas, 5);
    printf("Promedio de notas: %.2f\n", promedio);

    int objetivo = 92;
    int pos = buscarValor(notas, 5, objetivo);

    if (pos >= 0) {
        printf("Valor %d encontrado en la posicion %d\n", objetivo, pos);
    } else {
        printf("Valor %d no encontrado\n", objetivo);
    }

    return 0;
}
