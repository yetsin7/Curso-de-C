/*
 * ============================================================
 * Modulo 14 -- Proyecto Final PRO
 * Archivo: 01_sistema_biblioteca.c
 * ============================================================
 *
 * Este archivo implementa un sistema de biblioteca como proyecto final.
 *
 * El objetivo es integrar varios conceptos del curso en un solo programa:
 *
 *   - structs para representar libros
 *   - arreglos para guardar el catalogo
 *   - punteros para modificar registros
 *   - strings para titulo y autor
 *   - funciones para separar responsabilidades
 *   - menus interactivos con switch
 *   - validacion basica de entradas
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 01_sistema_biblioteca.c -o biblioteca
 *
 * Ejecutar:
 *   Windows: biblioteca.exe
 *   Linux/macOS: ./biblioteca
 */

#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 100
#define MAX_TITULO 80
#define MAX_AUTOR 60

/*
 * Libro representa un registro dentro de la biblioteca.
 */
typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int anio;
    int disponible;
} Libro;

/*
 * Catalogo global del ejemplo.
 *
 * En proyectos mas grandes, se podria encapsular en una estructura propia.
 */
static Libro catalogo[MAX_LIBROS];
static int total_libros = 0;

/*
 * Limpia caracteres restantes del buffer de entrada.
 */
void limpiar_entrada(void) {
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

/*
 * Agrega un libro al catalogo.
 */
void agregar_libro(const char *titulo, const char *autor, int anio) {
    if (titulo == NULL || autor == NULL) {
        printf("Error: datos invalidos.\n");
        return;
    }

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

/*
 * Lista todos los libros registrados.
 */
void listar_libros(void) {
    if (total_libros == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\n--- Catalogo de Libros ---\n");

    for (int i = 0; i < total_libros; i++) {
        const Libro *l = &catalogo[i];

        printf("[%d] %s - %s (%d) [%s]\n",
               i + 1,
               l->titulo,
               l->autor,
               l->anio,
               l->disponible ? "Disponible" : "Prestado");
    }

    printf("Total: %d libros\n\n", total_libros);
}

/*
 * Busca libros cuyo titulo contenga el texto indicado.
 */
void buscar_libro(const char *titulo) {
    int encontrado = 0;

    if (titulo == NULL || titulo[0] == '\0') {
        printf("Busqueda vacia.\n");
        return;
    }

    printf("\n--- Resultados de busqueda ---\n");

    for (int i = 0; i < total_libros; i++) {
        if (strstr(catalogo[i].titulo, titulo) != NULL) {
            const Libro *l = &catalogo[i];

            printf("[%d] %s - %s (%d) [%s]\n",
                   i + 1,
                   l->titulo,
                   l->autor,
                   l->anio,
                   l->disponible ? "Disponible" : "Prestado");

            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontraron libros con '%s'.\n", titulo);
    }

    printf("\n");
}

/*
 * Marca un libro como prestado usando su indice visible para el usuario.
 */
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

/*
 * Marca un libro prestado como disponible nuevamente.
 */
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

/*
 * Muestra el menu principal y devuelve la opcion elegida.
 */
int mostrar_menu(void) {
    int opcion = -1;

    printf("\n=== Sistema de Biblioteca ===\n");
    printf("1. Agregar libro\n");
    printf("2. Listar todos\n");
    printf("3. Buscar por titulo\n");
    printf("4. Prestar libro\n");
    printf("5. Devolver libro\n");
    printf("0. Salir\n");
    printf("Opcion: ");

    if (scanf("%d", &opcion) != 1) {
        limpiar_entrada();
        return -1;
    }

    limpiar_entrada();
    return opcion;
}

int main(void) {
    int opcion;
    char buffer[MAX_TITULO];
    char autor_buf[MAX_AUTOR];
    int anio;
    int idx;

    agregar_libro("Cien Anios de Soledad", "Gabriel Garcia Marquez", 1967);
    agregar_libro("El Principito", "Antoine de Saint-Exupery", 1943);
    agregar_libro("Don Quijote", "Miguel de Cervantes", 1605);

    do {
        opcion = mostrar_menu();

        switch (opcion) {
            case 1:
                printf("Titulo: ");
                fgets(buffer, MAX_TITULO, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';

                printf("Autor: ");
                fgets(autor_buf, MAX_AUTOR, stdin);
                autor_buf[strcspn(autor_buf, "\n")] = '\0';

                printf("Anio: ");
                if (scanf("%d", &anio) != 1) {
                    printf("Anio invalido.\n");
                    limpiar_entrada();
                    break;
                }
                limpiar_entrada();

                agregar_libro(buffer, autor_buf, anio);
                break;

            case 2:
                listar_libros();
                break;

            case 3:
                printf("Buscar: ");
                fgets(buffer, MAX_TITULO, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                buscar_libro(buffer);
                break;

            case 4:
                listar_libros();
                printf("Numero: ");
                if (scanf("%d", &idx) == 1) {
                    prestar_libro(idx);
                } else {
                    printf("Numero invalido.\n");
                }
                limpiar_entrada();
                break;

            case 5:
                listar_libros();
                printf("Numero: ");
                if (scanf("%d", &idx) == 1) {
                    devolver_libro(idx);
                } else {
                    printf("Numero invalido.\n");
                }
                limpiar_entrada();
                break;

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}
