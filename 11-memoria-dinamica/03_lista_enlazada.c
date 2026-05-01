/*
 * Modulo 11 -- Memoria Dinamica
 * Archivo: 03_lista_enlazada.c
 *
 * Implementacion de una lista enlazada simple:
 *   - Estructura Nodo con dato y puntero al siguiente
 *   - Operaciones: insertar al inicio, eliminar, recorrer
 *   - Gestion de memoria para cada nodo
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 03_lista_enlazada 03_lista_enlazada.c
 */

#include <stdio.h>
#include <stdlib.h>

/* Estructura de un nodo de la lista enlazada */
typedef struct Nodo {
    int dato;           /* valor almacenado en el nodo */
    struct Nodo *sig;   /* puntero al siguiente nodo */
} Nodo;

/* Prototipos de funciones */
Nodo *crear_nodo(int valor);
void insertar_inicio(Nodo **cabeza, int valor);
void eliminar_valor(Nodo **cabeza, int valor);
void recorrer(const Nodo *cabeza);
void liberar_lista(Nodo *cabeza);
int longitud(const Nodo *cabeza);

int main(void) {

    Nodo *lista = NULL;  /* lista vacia al inicio */

    /* --- Insertar elementos --- */
    printf("=== Insertar elementos ===\n");
    insertar_inicio(&lista, 30);
    insertar_inicio(&lista, 20);
    insertar_inicio(&lista, 10);

    printf("Lista despues de insertar 10, 20, 30: ");
    recorrer(lista);
    printf("Longitud: %d\n", longitud(lista));

    /* --- Eliminar un valor --- */
    printf("\n=== Eliminar valor ===\n");
    eliminar_valor(&lista, 20);
    printf("Lista despues de eliminar 20: ");
    recorrer(lista);
    printf("Longitud: %d\n", longitud(lista));

    /* --- Insertar mas elementos --- */
    printf("\n=== Mas inserciones ===\n");
    insertar_inicio(&lista, 5);
    insertar_inicio(&lista, 1);
    printf("Lista final: ");
    recorrer(lista);
    printf("Longitud: %d\n", longitud(lista));

    /* --- Liberar toda la memoria --- */
    printf("\n=== Liberar lista ===\n");
    liberar_lista(lista);
    lista = NULL;
    printf("Lista liberada correctamente.\n");

    return 0;
}

/*
 * crear_nodo -- Crea un nuevo nodo con el valor dado.
 * Recibe: valor -- el dato a almacenar
 * Retorna: puntero al nodo creado, o NULL si falla malloc
 */
Nodo *crear_nodo(int valor) {
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        fprintf(stderr, "Error: no se pudo crear nodo\n");
        return NULL;
    }

    nuevo->dato = valor;
    nuevo->sig = NULL;
    return nuevo;
}

/*
 * insertar_inicio -- Inserta un nuevo nodo al inicio de la lista.
 * Recibe: cabeza -- puntero al puntero cabeza de la lista
 *         valor -- el dato del nuevo nodo
 */
void insertar_inicio(Nodo **cabeza, int valor) {
    Nodo *nuevo = crear_nodo(valor);

    if (nuevo == NULL) return;

    nuevo->sig = *cabeza;  /* el nuevo apunta al antiguo primero */
    *cabeza = nuevo;       /* la cabeza ahora es el nuevo nodo */
}

/*
 * eliminar_valor -- Elimina el primer nodo que contenga el valor dado.
 * Recibe: cabeza -- puntero al puntero cabeza de la lista
 *         valor -- el dato a buscar y eliminar
 */
void eliminar_valor(Nodo **cabeza, int valor) {
    if (*cabeza == NULL) return;

    /* Caso especial: el nodo a eliminar es la cabeza */
    if ((*cabeza)->dato == valor) {
        Nodo *temp = *cabeza;
        *cabeza = (*cabeza)->sig;
        free(temp);
        temp = NULL;
        return;
    }

    /* Buscar el nodo en el resto de la lista */
    Nodo *actual = *cabeza;
    while (actual->sig != NULL && actual->sig->dato != valor) {
        actual = actual->sig;
    }

    /* Si encontro el nodo, eliminarlo */
    if (actual->sig != NULL) {
        Nodo *temp = actual->sig;
        actual->sig = temp->sig;  /* saltar el nodo eliminado */
        free(temp);
        temp = NULL;
    }
}

/*
 * recorrer -- Imprime todos los valores de la lista.
 * Recibe: cabeza -- puntero al primer nodo de la lista
 */
void recorrer(const Nodo *cabeza) {
    printf("[");
    const Nodo *actual = cabeza;

    while (actual != NULL) {
        printf("%d", actual->dato);
        if (actual->sig != NULL) {
            printf(" -> ");
        }
        actual = actual->sig;
    }
    printf("]\n");
}

/*
 * liberar_lista -- Libera todos los nodos de la lista.
 * Recibe: cabeza -- puntero al primer nodo de la lista
 */
void liberar_lista(Nodo *cabeza) {
    Nodo *actual = cabeza;

    while (actual != NULL) {
        Nodo *siguiente = actual->sig;  /* guardar referencia al siguiente */
        free(actual);
        actual = siguiente;
    }
}

/*
 * longitud -- Cuenta cuantos nodos tiene la lista.
 * Recibe: cabeza -- puntero al primer nodo
 * Retorna: numero de nodos en la lista
 */
int longitud(const Nodo *cabeza) {
    int count = 0;
    const Nodo *actual = cabeza;

    while (actual != NULL) {
        count++;
        actual = actual->sig;
    }
    return count;
}
