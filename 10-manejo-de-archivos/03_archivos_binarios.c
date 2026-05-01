/*
 * Modulo 10 -- Archivos Binarios
 * Compilar: gcc -Wall -Wextra -std=c11 -o binarios 03_archivos_binarios.c
 *
 * Demuestra operaciones con archivos binarios:
 *   - Modos "wb" (escritura binaria) y "rb" (lectura binaria)
 *   - fwrite para escribir bloques de bytes
 *   - fread para leer bloques de bytes
 *   - Escritura y lectura de estructuras completas
 *   - fseek y ftell para posicionamiento en el archivo
 */

#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO "estudiantes.dat"

/* Estructura que representa un estudiante */
typedef struct {
    char nombre[50];
    int edad;
    double promedio;
} Estudiante;

/* Escribe un arreglo de estructuras en formato binario */
void escribirBinario(const Estudiante estudiantes[], int cantidad) {
    FILE *archivo = fopen(ARCHIVO, "wb");

    if (archivo == NULL) {
        perror("Error al crear archivo binario");
        return;
    }

    /* fwrite: puntero, tamano de cada elemento, cantidad, archivo */
    size_t escritos = fwrite(estudiantes, sizeof(Estudiante), cantidad, archivo);
    printf("Estructuras escritas: %zu de %d\n", escritos, cantidad);

    fclose(archivo);
}

/* Lee estructuras del archivo binario y las muestra */
void leerBinario(void) {
    FILE *archivo = fopen(ARCHIVO, "rb");

    if (archivo == NULL) {
        perror("Error al abrir archivo binario");
        return;
    }

    /* Obtener tamano del archivo con fseek + ftell */
    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    fseek(archivo, 0, SEEK_SET);  /* Volver al inicio */

    int cantidad = tamano / sizeof(Estudiante);
    printf("\nTamano del archivo: %ld bytes (%d registros)\n", tamano, cantidad);

    /* Leer y mostrar cada registro */
    Estudiante est;
    printf("\n=== Contenido del archivo binario ===\n");
    while (fread(&est, sizeof(Estudiante), 1, archivo) == 1) {
        printf("  %-20s | Edad: %2d | Promedio: %.1f\n", est.nombre, est.edad, est.promedio);
    }

    fclose(archivo);
}

int main(void) {
    printf("Modulo 10 - Archivos binarios\n");
    printf("==============================\n\n");

    /* Crear datos de ejemplo */
    Estudiante estudiantes[] = {
        {"Ana Garcia", 20, 9.5},
        {"Carlos Lopez", 22, 8.7},
        {"Maria Torres", 19, 9.2},
        {"Pedro Ruiz", 21, 7.8}
    };
    int cantidad = sizeof(estudiantes) / sizeof(estudiantes[0]);

    /* Escribir en formato binario */
    printf("Escribiendo %d registros en formato binario...\n", cantidad);
    escribirBinario(estudiantes, cantidad);

    /* Leer y verificar el contenido */
    leerBinario();

    return EXIT_SUCCESS;
}
