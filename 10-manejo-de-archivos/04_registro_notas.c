/*
 * Modulo 10 -- Registro de Notas (Mini-Proyecto)
 * Compilar: gcc -Wall -Wextra -std=c11 -o registro 04_registro_notas.c
 *
 * Sistema practico de registro de calificaciones:
 *   - Escribe calificaciones de estudiantes a un archivo
 *   - Lee las calificaciones y calcula el promedio general
 *   - Encuentra la nota mas alta y mas baja
 *   - Manejo de errores en todas las operaciones de archivo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHIVO "calificaciones.txt"
#define MAX_EST 50
#define MAX_NOMBRE 60

/* Estructura para almacenar datos de un estudiante */
typedef struct {
    char nombre[MAX_NOMBRE];
    double nota;
} Estudiante;

/* Registra estudiantes en un archivo de texto */
int escribirCalificaciones(const Estudiante estudiantes[], int cantidad) {
    FILE *archivo = fopen(ARCHIVO, "w");

    if (archivo == NULL) {
        perror("Error al crear archivo de calificaciones");
        return -1;
    }

    fprintf(archivo, "# Registro de Calificaciones\n");
    fprintf(archivo, "# Formato: nombre,nota\n\n");

    for (int i = 0; i < cantidad; i++) {
        fprintf(archivo, "%s,%.1f\n", estudiantes[i].nombre, estudiantes[i].nota);
    }

    if (fclose(archivo) != 0) {
        perror("Error al cerrar archivo");
        return -1;
    }

    printf("Calificaciones guardadas: %d estudiantes registrados.\n", cantidad);
    return 0;
}

/* Lee calificaciones y calcula estadisticas */
int leerYCalcular(void) {
    FILE *archivo = fopen(ARCHIVO, "r");

    if (archivo == NULL) {
        perror("Error al abrir archivo de calificaciones");
        return -1;
    }

    Estudiante lista[MAX_EST];
    int cantidad = 0;
    char linea[MAX_NOMBRE + 20];

    /* Leer linea por linea, saltando comentarios */
    while (fgets(linea, sizeof(linea), archivo) != NULL && cantidad < MAX_EST) {
        if (linea[0] == '#' || linea[0] == '\n') continue;

        /* Parsear nombre y nota separados por coma */
        if (sscanf(linea, "%[^,],%lf", lista[cantidad].nombre, &lista[cantidad].nota) == 2) {
            cantidad++;
        }
    }
    fclose(archivo);

    if (cantidad == 0) {
        printf("No se encontraron calificaciones.\n");
        return 0;
    }

    /* Calcular estadisticas */
    double suma = 0, max = lista[0].nota, min = lista[0].nota;
    int idxMax = 0, idxMin = 0;

    for (int i = 0; i < cantidad; i++) {
        suma += lista[i].nota;
        if (lista[i].nota > max) { max = lista[i].nota; idxMax = i; }
        if (lista[i].nota < min) { min = lista[i].nota; idxMin = i; }
    }

    /* Mostrar resultados */
    printf("\n=== Estadisticas de Calificaciones ===\n");
    for (int i = 0; i < cantidad; i++) {
        printf("  %-20s | Nota: %.1f\n", lista[i].nombre, lista[i].nota);
    }
    printf("\n  Promedio general : %.2f\n", suma / cantidad);
    printf("  Nota mas alta    : %.1f (%s)\n", max, lista[idxMax].nombre);
    printf("  Nota mas baja    : %.1f (%s)\n", min, lista[idxMin].nombre);
    printf("  Total estudiantes: %d\n", cantidad);

    return 0;
}

int main(void) {
    printf("Modulo 10 - Registro de Notas\n");
    printf("==============================\n\n");

    /* Datos de ejemplo */
    Estudiante estudiantes[] = {
        {"Ana Garcia", 9.5},
        {"Carlos Lopez", 8.7},
        {"Maria Torres", 9.2},
        {"Pedro Ruiz", 7.8},
        {"Lucia Mendez", 10.0}
    };
    int cantidad = sizeof(estudiantes) / sizeof(estudiantes[0]);

    /* Fase 1: Escribir calificaciones al archivo */
    if (escribirCalificaciones(estudiantes, cantidad) != 0) {
        return EXIT_FAILURE;
    }

    /* Fase 2: Leer y calcular estadisticas */
    if (leerYCalcular() != 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
