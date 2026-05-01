/*
 * Modulo 06 -- Arreglos y Strings
 * Archivo: 01_arreglos_unidimensionales.c
 *
 * Demuestra arreglos de una dimension:
 *   - Declaracion e inicializacion
 *   - Acceso por indice
 *   - Recorrido con bucles
 *   - Arreglos como parametros de funcion
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 01_arreglos_unidimensionales 01_arreglos_unidimensionales.c
 */

#include <stdio.h>

/* Imprime todos los elementos de un arreglo entero */
void imprimirArreglo(const int arr[], int tamano) {
    printf("[");
    for (int i = 0; i < tamano; i++) {
        printf("%d", arr[i]);
        if (i < tamano - 1) printf(", ");
    }
    printf("]\n");
}

/* Calcula y retorna el promedio de los elementos */
double calcularPromedio(const int arr[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++) {
        suma += arr[i];
    }
    return (double)suma / tamano;
}

/* Busca un valor y retorna su indice, o -1 si no existe */
int buscarValor(const int arr[], int tamano, int objetivo) {
    for (int i = 0; i < tamano; i++) {
        if (arr[i] == objetivo) {
            return i;
        }
    }
    return -1;
}

int main(void) {

    /* --- Declaracion e inicializacion --- */
    printf("=== DECLARACION E INICIALIZACION ===\n");

    /* Forma 1: con valores iniciales */
    int notas[5] = {85, 92, 78, 95, 88};
    printf("Notas inicializadas: ");
    imprimirArreglo(notas, 5);

    /* Forma 2: el compilador infiere el tamaño */
    int edades[] = {20, 25, 30, 35, 40};
    int tamEdades = sizeof(edades) / sizeof(edades[0]);
    printf("Edades: ");
    imprimirArreglo(edades, tamEdades);

    /* Forma 3: inicializar todo en cero */
    int ceros[5] = {0};
    printf("Ceros: ");
    imprimirArreglo(ceros, 5);

    /* --- Acceso por indice --- */
    printf("\n=== ACCESO POR INDICE ===\n");

    printf("Primera nota: %d\n", notas[0]);
    printf("Ultima nota: %d\n", notas[4]);

    /* Modificar un elemento */
    notas[2] = 82;
    printf("Notas tras modificar indice 2: ");
    imprimirArreglo(notas, 5);

    /* --- Recorrer con bucle --- */
    printf("\n=== RECORRIDO CON BUCLE ===\n");

    for (int i = 0; i < 5; i++) {
        printf("  Elemento [%d] = %d\n", i, notas[i]);
    }

    /* --- Arreglos como parametros de funcion --- */
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
