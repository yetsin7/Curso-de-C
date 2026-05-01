/*
 * ============================================================
 * Modulo 11 -- Memoria Dinamica
 * Archivo: 03_lista_enlazada.c
 * ============================================================
 *
 * Este archivo explica una lista enlazada simple.
 *
 * Una lista enlazada es una estructura de datos formada por nodos.
 * Cada nodo guarda:
 *
 *   - un dato
 *   - un puntero al siguiente nodo
 *
 * A diferencia de un arreglo, una lista enlazada no necesita estar
 * guardada en memoria continua. Cada nodo puede estar en una posicion
 * diferente del heap.
 *
 * Este ejemplo muestra:
 *
 *   - crear nodos con malloc
 *   - insertar nodos al inicio
 *   - eliminar nodos
 *   - recorrer la lista
 *   - liberar toda la memoria
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 03_lista_enlazada 03_lista_enlazada.c
 *
 * Ejecutar:
 *   Windows: 03_lista_enlazada.exe
 *   Linux/macOS: ./03_lista_enlazada
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Un nodo contiene un dato y un puntero al siguiente nodo.
 */
typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

Nodo *crear_nodo(int valor);
void insertar_inicio(Nodo **cabeza, int valor);
void eliminar_valor(Nodo **cabeza, int valor);
void recorrer(const Nodo *cabeza);
void liberar_lista(Nodo *cabeza);
int longitud(const Nodo *cabeza);

int main(void) {
    Nodo *lista = NULL;

    printf("=== LISTA ENLAZADA SIMPLE ===\n\n");

    printf("Insertar elementos:\n");
    insertar_inicio(&lista, 30);
    insertar_inicio(&lista, 20);
    insertar_inicio(&lista, 10);

    printf("Lista despues de insertar 10, 20, 30: ");
    recorrer(lista);
    printf("Longitud: %d\n", longitud(lista));

    printf("\nEliminar valor 20:\n");
    eliminar_valor(&lista, 20);

    printf("Lista despues de eliminar 20: ");
    recorrer(lista);
    printf("Longitud: %d\n", longitud(lista));

    printf("\nMas inserciones:\n");
    insertar_inicio(&lista, 5);
    insertar_inicio(&lista, 1);

    printf("Lista final: ");
    recorrer(lista);
    printf("Longitud: %d\n", longitud(lista));

    printf("\nLiberar lista:\n");
    liberar_lista(lista);
    lista = NULL;

    printf("Lista liberada correctamente.\n");

    return 0;
}

/*
 * Crea un nodo nuevo usando malloc.
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
 * Inserta un nodo al inicio de la lista.
 *
 * Usamos Nodo ** porque necesitamos modificar la cabeza original.
 */
void insertar_inicio(Nodo **cabeza, int valor) {
    Nodo *nuevo = crear_nodo(valor);

    if (nuevo == NULL) {
        return;
    }

    nuevo->sig = *cabeza;
    *cabeza = nuevo;
}

/*
 * Elimina el primer nodo que contenga el valor indicado.
 */
void eliminar_valor(Nodo **cabeza, int valor) {
    if (*cabeza == NULL) {
        return;
    }

    if ((*cabeza)->dato == valor) {
        Nodo *temp = *cabeza;
        *cabeza = (*cabeza)->sig;
        free(temp);
        return;
    }

    Nodo *actual = *cabeza;

    while (actual->sig != NULL && actual->sig->dato != valor) {
        actual = actual->sig;
    }

    if (actual->sig != NULL) {
        Nodo *temp = actual->sig;
        actual->sig = temp->sig;
        free(temp);
    }
}

/*
 * Recorre la lista e imprime sus valores.
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
 * Libera todos los nodos de la lista.
 */
void liberar_lista(Nodo *cabeza) {
    Nodo *actual = cabeza;

    while (actual != NULL) {
        Nodo *siguiente = actual->sig;
        free(actual);
        actual = siguiente;
    }
}

/*
 * Cuenta cuantos nodos tiene la lista.
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
