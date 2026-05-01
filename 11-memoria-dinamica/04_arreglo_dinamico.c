/*
 * Modulo 11 -- Memoria Dinamica
 * Archivo: 04_arreglo_dinamico.c
 *
 * Mini-proyecto: implementacion de un arreglo dinamico reutilizable.
 *   - Estructura con capacidad, tamaño y puntero a datos
 *   - Funciones: init, push, get, size, free
 *   - Crecimiento automatico al superar la capacidad
 *   - Demuestra todos los conceptos de memoria dinamica
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 04_arreglo_dinamico 04_arreglo_dinamico.c
 */

#include <stdio.h>
#include <stdlib.h>

/* Estructura del arreglo dinamico reutilizable */
typedef struct {
    int *datos;       /* puntero al bloque de memoria dinamica */
    int tamano;       /* cantidad de elementos actuales */
    int capacidad;    /* capacidad total reservada */
} ArregloDinamico;

/* Prototipos */
ArregloDinamico *arr_init(int capacidad_inicial);
int arr_push(ArregloDinamico *arr, int valor);
int arr_get(const ArregloDinamico *arr, int indice);
void arr_set(ArregloDinamico *arr, int indice, int valor);
int arr_size(const ArregloDinamico *arr);
void arr_print(const ArregloDinamico *arr);
void arr_free(ArregloDinamico *arr);

int main(void) {

    /* --- Crear arreglo con capacidad inicial de 3 --- */
    printf("=== Crear arreglo dinamico ===\n");

    ArregloDinamico *arr = arr_init(3);

    if (arr == NULL) {
        fprintf(stderr, "Error: no se pudo crear el arreglo\n");
        return 1;
    }

    printf("Arreglo creado: capacidad=%d, tamaño=%d\n",
           arr->capacidad, arr->tamano);

    /* --- Agregar elementos (push) --- */
    printf("\n=== Agregar elementos ===\n");

    for (int i = 1; i <= 7; i++) {
        if (arr_push(arr, i * 10) == 0) {
            printf("  Push %2d -> tamaño=%d, capacidad=%d\n",
                   i * 10, arr->tamano, arr->capacidad);
        }
    }

    printf("\nEstado actual: ");
    arr_print(arr);

    /* --- Acceder por indice (get) --- */
    printf("\n=== Acceso por indice ===\n");

    for (int i = 0; i < arr_size(arr); i++) {
        printf("  arr[%d] = %d\n", i, arr_get(arr, i));
    }

    /* --- Modificar un elemento (set) --- */
    printf("\n=== Modificar elemento ===\n");

    arr_set(arr, 2, 999);
    printf("Despues de arr[2] = 999: ");
    arr_print(arr);

    /* --- Acceso fuera de limites (seguro) --- */
    printf("\n=== Acceso seguro ===\n");

    int valor = arr_get(arr, 100);  /* indice invalido */
    printf("arr[100] (fuera de limites) = %d\n", valor);

    /* --- Liberar memoria --- */
    printf("\n=== Liberar arreglo ===\n");
    arr_free(arr);
    arr = NULL;
    printf("Arreglo liberado correctamente.\n");

    return 0;
}

/*
 * arr_init -- Inicializa un arreglo dinamico vacio.
 * Recibe: capacidad_inicial -- cantidad de elementos a reservar
 * Retorna: puntero al arreglo, o NULL si falla
 */
ArregloDinamico *arr_init(int capacidad_inicial) {
    ArregloDinamico *arr = malloc(sizeof(ArregloDinamico));

    if (arr == NULL) return NULL;

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
 * arr_push -- Agrega un elemento al final del arreglo.
 * Si no hay capacidad, duplica el tamaño automaticamente.
 * Recibe: arr -- puntero al arreglo, valor -- dato a agregar
 * Retorna: 0 si exito, -1 si error
 */
int arr_push(ArregloDinamico *arr, int valor) {
    /* Expandir si es necesario */
    if (arr->tamano >= arr->capacidad) {
        int nueva_cap = arr->capacidad * 2;
        int *temp = realloc(arr->datos, nueva_cap * sizeof(int));

        if (temp == NULL) return -1;

        arr->datos = temp;
        arr->capacidad = nueva_cap;
    }

    arr->datos[arr->tamano] = valor;
    arr->tamano++;
    return 0;
}

/*
 * arr_get -- Obtiene el valor en un indice dado.
 * Retorna: el valor si el indice es valido, -1 si esta fuera de limites
 */
int arr_get(const ArregloDinamico *arr, int indice) {
    if (indice < 0 || indice >= arr->tamano) {
        fprintf(stderr, "Error: indice %d fuera de limites\n", indice);
        return -1;
    }
    return arr->datos[indice];
}

/*
 * arr_set -- Modifica el valor en un indice dado.
 * Recibe: arr -- puntero al arreglo, indice -- posicion, valor -- nuevo dato
 */
void arr_set(ArregloDinamico *arr, int indice, int valor) {
    if (indice < 0 || indice >= arr->tamano) {
        fprintf(stderr, "Error: indice %d fuera de limites\n", indice);
        return;
    }
    arr->datos[indice] = valor;
}

/*
 * arr_size -- Retorna la cantidad de elementos actuales.
 */
int arr_size(const ArregloDinamico *arr) {
    return arr->tamano;
}

/*
 * arr_print -- Imprime todos los elementos del arreglo.
 */
void arr_print(const ArregloDinamico *arr) {
    printf("[");
    for (int i = 0; i < arr->tamano; i++) {
        printf("%d", arr->datos[i]);
        if (i < arr->tamano - 1) printf(", ");
    }
    printf("]\n");
}

/*
 * arr_free -- Libera toda la memoria del arreglo dinamico.
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
