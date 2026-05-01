/*
 * Sistema de Biblioteca - Proyecto Final
 * Compilar: gcc -Wall -Wextra -std=c11 01_sistema_biblioteca.c -o biblioteca
 *
 * Sistema de gestion de biblioteca que utiliza structs, arrays,
 * punteros, funciones y control de flujo para administrar libros.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIBROS 100
#define MAX_TITULO 80
#define MAX_AUTOR 60

/* Estructura que representa un libro en la biblioteca */
typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int anio;
    int disponible;
} Libro;

/* Catalogo global de libros */
static Libro catalogo[MAX_LIBROS];
static int total_libros = 0;

/* Agrega un nuevo libro al catalogo usando punteros */
void agregar_libro(const char *titulo, const char *autor, int anio) {
    if (total_libros >= MAX_LIBROS) {
        printf("Error: catalogo lleno.\n");
        return;
    }

    Libro *libro = &catalogo[total_libros];
    strncpy(libro->titulo, titulo, MAX_TITULO - 1);
    libro->titulo[MAX_TITULO - 1] = '\0';
    strncpy(libro->autor, autor, MAX_AUTOR - 1);
    libro->autor[MAX_AUTOR - 1] = '\0';
    libro->anio = anio;
    libro->disponible = 1;
    total_libros++;

    printf("Libro agregado: %s\n", titulo);
}

/* Lista todos los libros registrados en el catalogo */
void listar_libros(void) {
    if (total_libros == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\n--- Catalogo de Libros ---\n");
    for (int i = 0; i < total_libros; i++) {
        Libro *l = &catalogo[i];
        printf("[%d] %s - %s (%d) [%s]\n",
               i + 1, l->titulo, l->autor, l->anio,
               l->disponible ? "Disponible" : "Prestado");
    }
    printf("Total: %d libros\n\n", total_libros);
}

/* Busca un libro por titulo (case-insensitive parcial) */
void buscar_libro(const char *titulo) {
    int encontrado = 0;
    printf("\n--- Resultados de busqueda ---\n");

    for (int i = 0; i < total_libros; i++) {
        if (strstr(catalogo[i].titulo, titulo)) {
            Libro *l = &catalogo[i];
            printf("[%d] %s - %s (%d) [%s]\n",
                   i + 1, l->titulo, l->autor, l->anio,
                   l->disponible ? "Disponible" : "Prestado");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontraron libros con '%s'.\n", titulo);
    }
    printf("\n");
}

/* Presta un libro por indice (1-based), retorna 0 si exito */
int prestar_libro(int indice) {
    if (indice < 1 || indice > total_libros) {
        printf("Error: indice invalido.\n");
        return -1;
    }

    Libro *libro = &catalogo[indice - 1];
    if (!libro->disponible) {
        printf("Error: '%s' ya esta prestado.\n", libro->titulo);
        return -1;
    }

    libro->disponible = 0;
    printf("Libro prestado: %s\n", libro->titulo);
    return 0;
}

/* Devuelve un libro por indice (1-based), retorna 0 si exito */
int devolver_libro(int indice) {
    if (indice < 1 || indice > total_libros) {
        printf("Error: indice invalido.\n");
        return -1;
    }

    Libro *libro = &catalogo[indice - 1];
    if (libro->disponible) {
        printf("Error: '%s' no estaba prestado.\n", libro->titulo);
        return -1;
    }

    libro->disponible = 1;
    printf("Libro devuelto: %s\n", libro->titulo);
    return 0;
}

/* Muestra el menu principal y retorna la opcion elegida */
int mostrar_menu(void) {
    int opcion;
    printf("\n=== Sistema de Biblioteca ===\n");
    printf("1. Agregar libro\n2. Listar todos\n3. Buscar por titulo\n");
    printf("4. Prestar libro\n5. Devolver libro\n0. Salir\nOpcion: ");
    scanf("%d", &opcion);
    while (getchar() != '\n');
    return opcion;
}

/* Punto de entrada principal del programa */
int main(void) {
    int opcion;
    char buffer[MAX_TITULO], autor_buf[MAX_AUTOR];
    int anio, idx;

    /* Datos iniciales de ejemplo */
    agregar_libro("Cien Anios de Soledad", "Gabriel Garcia Marquez", 1967);
    agregar_libro("El Principito", "Antoine de Saint-Exupery", 1943);
    agregar_libro("Don Quijote", "Miguel de Cervantes", 1605);

    do {
        opcion = mostrar_menu();
        switch (opcion) {
            case 1:
                printf("Titulo: "); fgets(buffer, MAX_TITULO, stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                printf("Autor: "); fgets(autor_buf, MAX_AUTOR, stdin);
                autor_buf[strcspn(autor_buf, "\n")] = 0;
                printf("Anio: "); scanf("%d", &anio); while (getchar() != '\n');
                agregar_libro(buffer, autor_buf, anio);
                break;
            case 2: listar_libros(); break;
            case 3:
                printf("Buscar: "); fgets(buffer, MAX_TITULO, stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                buscar_libro(buffer); break;
            case 4:
                listar_libros(); printf("Numero: ");
                scanf("%d", &idx); while (getchar() != '\n');
                prestar_libro(idx); break;
            case 5:
                listar_libros(); printf("Numero: ");
                scanf("%d", &idx); while (getchar() != '\n');
                devolver_libro(idx); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);
    return 0;
}
