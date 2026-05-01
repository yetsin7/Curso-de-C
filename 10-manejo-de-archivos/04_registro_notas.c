/*
 * ============================================================
 * Modulo 10 -- Manejo de Archivos
 * Archivo: 04_registro_notas.c
 * ============================================================
 *
 * Este archivo muestra un mini-proyecto: registro de calificaciones.
 *
 * El programa hace dos cosas principales:
 *
 *   1. Guarda calificaciones de estudiantes en un archivo de texto.
 *   2. Lee ese archivo y calcula estadisticas del grupo.
 *
 * Este proyecto combina:
 *
 *   - structs
 *   - arreglos
 *   - strings
 *   - escritura de archivos
 *   - lectura de archivos
 *   - fgets
 *   - sscanf
 *   - validacion de errores
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o registro 04_registro_notas.c
 *
 * Ejecutar:
 *   Windows: registro.exe
 *   Linux/macOS: ./registro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHIVO "calificaciones.txt"
#define MAX_EST 50
#define MAX_NOMBRE 60

/*
 * Estructura para guardar los datos de un estudiante.
 */
typedef struct {
    char nombre[MAX_NOMBRE];
    double nota;
} Estudiante;

/*
 * Guarda las calificaciones en un archivo de texto.
 *
 * Cada estudiante se guarda en una linea usando el formato:
 *
 *   nombre,nota
 */
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

/*
 * Lee las calificaciones desde el archivo y calcula estadisticas.
 */
int leerYCalcular(void) {
    FILE *archivo = fopen(ARCHIVO, "r");

    if (archivo == NULL) {
        perror("Error al abrir archivo de calificaciones");
        return -1;
    }

    Estudiante lista[MAX_EST];
    int cantidad = 0;
    char linea[MAX_NOMBRE + 20];

    /*
     * Leemos linea por linea.
     *
     * Las lineas que empiezan con # son comentarios y se ignoran.
     * Las lineas vacias tambien se ignoran.
     */
    while (fgets(linea, sizeof(linea), archivo) != NULL && cantidad < MAX_EST) {
        if (linea[0] == '#' || linea[0] == '\n') {
            continue;
        }

        /*
         * sscanf extrae datos desde una cadena.
         *
         * Aqui lee un nombre hasta encontrar una coma, y luego lee la nota.
         */
        if (sscanf(linea, "%59[^,],%lf", lista[cantidad].nombre, &lista[cantidad].nota) == 2) {
            cantidad++;
        }
    }

    fclose(archivo);

    if (cantidad == 0) {
        printf("No se encontraron calificaciones.\n");
        return 0;
    }

    double suma = 0.0;
    double max = lista[0].nota;
    double min = lista[0].nota;
    int idxMax = 0;
    int idxMin = 0;

    for (int i = 0; i < cantidad; i++) {
        suma += lista[i].nota;

        if (lista[i].nota > max) {
            max = lista[i].nota;
            idxMax = i;
        }

        if (lista[i].nota < min) {
            min = lista[i].nota;
            idxMin = i;
        }
    }

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

    Estudiante estudiantes[] = {
        {"Ana Garcia", 9.5},
        {"Carlos Lopez", 8.7},
        {"Maria Torres", 9.2},
        {"Pedro Ruiz", 7.8},
        {"Lucia Mendez", 10.0}
    };

    int cantidad = sizeof(estudiantes) / sizeof(estudiantes[0]);

    if (escribirCalificaciones(estudiantes, cantidad) != 0) {
        return EXIT_FAILURE;
    }

    if (leerYCalcular() != 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
