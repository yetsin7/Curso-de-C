/*
 * ============================================================
 * Modulo 11 -- Memoria Dinamica
 * Archivo: 04_arreglo_dinamico.c
 * ============================================================
 *
 * Este archivo muestra un mini-proyecto: un arreglo dinamico reutilizable.
 *
 * Un arreglo dinamico es parecido a un arreglo normal, pero puede crecer
 * durante la ejecucion del programa.
 *
 * Para lograrlo, guardamos tres datos:
 *
 *   datos      puntero al bloque de memoria dinamica
 *   tamano     cantidad de elementos usados actualmente
 *   capacidad  cantidad de elementos que caben sin volver a reservar memoria
 *
 * Cuando el arreglo se llena, usamos realloc para aumentar su capacidad.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 04_arreglo_dinamico 04_arreglo_dinamico.c
 *
 * Ejecutar:
 *   Windows: 04_arreglo_dinamico.exe
 *   Linux/macOS: ./04_arreglo_dinamico
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Estructura principal del arreglo dinamico.
 */
typedef struct {
    int *datos;
    int tamano;
    int capacidad;
} ArregloDinamico;

ArregloDinamico *arr_init(int capacidad_inicial);
int arr_push(ArregloDinamico *arr, int valor);
int arr_get(const ArregloDinamico *arr, int indice);
void arr_set(ArregloDinamico *arr, int indice, int valor);
int arr_size(const ArregloDinamico *arr);
void arr_print(const ArregloDinamico *arr);
void arr_free(ArregloDinamico *arr);

int main(void) {
    printf("=== ARREGLO DINAMICO REUTILIZABLE ===\n\n");

    ArregloDinamico *arr = arr_init(3);

    if (arr == NULL) {
        fprintf(stderr, "Error: no se pudo crear el arreglo\n");
        return 1;
    }

    printf("Arreglo creado: capacidad=%d, tamano=%d\n",
           arr->capacidad, arr->tamano);

    printf("\nAgregar elementos:\n");

    for (int i = 1; i <= 7; i++) {
        if (arr_push(arr, i * 10) == 0) {
            printf("Push %2d -> tamano=%d, capacidad=%d\n",
                   i * 10, arr->tamano, arr->capacidad);
        } else {
            printf("No se pudo agregar %d\n", i * 10);
        }
    }

    printf("\nEstado actual: ");
    arr_print(arr);

    printf("\nAcceso por indice:\n");

    for (int i = 0; i < arr_size(arr); i++) {
        printf("arr[%d] = %d\n", i, arr_get(arr, i));
    }

    printf("\nModificar elemento:\n");

    arr_set(arr, 2, 999);
    printf("Despues de arr[2] = 999: ");
    arr_print(arr);

    printf("\nAcceso seguro fuera de limites:\n");

    int valor = arr_get(arr, 100);
    printf("arr[100] devuelve: %d\n", valor);

    printf("\nLiberar arreglo:\n");

    arr_free(arr);
    arr = NULL;

    printf("Arreglo liberado correctamente.\n");

    return 0;
}

/*
 * Crea un arreglo dinamico vacio.
 */
ArregloDinamico *arr_init(int capacidad_inicial) {
    if (capacidad_inicial <= 0) {
        capacidad_inicial = 1;
    }

    ArregloDinamico *arr = malloc(sizeof(ArregloDinamico));

    if (arr == NULL) {
        return NULL;
    }

    arr->datos = calloc(capacidad_inicial, sizeof(int));

    if (arr->datos == NULL) {
        free(arr);
        return NULL;
    }

    arr->tamano = 0;
    arr->capacidad = capacidad_inicial;

    return arr;
}

/*
 * Agrega un valor al final del arreglo.
 *
 * Si no hay espacio, duplica la capacidad usando realloc.
 */
int arr_push(ArregloDinamico *arr, int valor) {
    if (arr == NULL) {
        return -1;
    }

    if (arr->tamano >= arr->capacidad) {
        int nueva_capacidad = arr->capacidad * 2;
        int *temp = realloc(arr->datos, nueva_capacidad * sizeof(int));

        if (temp == NULL) {
            return -1;
        }

        arr->datos = temp;
        arr->capacidad = nueva_capacidad;
    }

    arr->datos[arr->tamano] = valor;
    arr->tamano++;

    return 0;
}

/*
 * Obtiene un valor por indice.
 */
int arr_get(const ArregloDinamico *arr, int indice) {
    if (arr == NULL || indice < 0 || indice >= arr->tamano) {
        fprintf(stderr, "Error: indice %d fuera de limites\n", indice);
        return -1;
    }

    return arr->datos[indice];
}

/*
 * Modifica un valor existente.
 */
void arr_set(ArregloDinamico *arr, int indice, int valor) {
    if (arr == NULL || indice < 0 || indice >= arr->tamano) {
        fprintf(stderr, "Error: indice %d fuera de limites\n", indice);
        return;
    }

    arr->datos[indice] = valor;
}

/*
 * Devuelve la cantidad de elementos usados.
 */
int arr_size(const ArregloDinamico *arr) {
    if (arr == NULL) {
        return 0;
    }

    return arr->tamano;
}

/*
 * Imprime el contenido del arreglo.
 */
void arr_print(const ArregloDinamico *arr) {
    if (arr == NULL) {
        printf("[]\n");
        return;
    }

    printf("[");

    for (int i = 0; i < arr->tamano; i++) {
        printf("%d", arr->datos[i]);

        if (i < arr->tamano - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}

/*
 * Libera toda la memoria usada por el arreglo dinamico.
 */
void arr_free(ArregloDinamico *arr) {
    if (arr != NULL) {
        free(arr->datos);
        arr->datos = NULL;
        arr->tamano = 0;
        arr->capacidad = 0;
        free(arr);
    }
}
