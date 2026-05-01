/*
 * ============================================================
 * Modulo 10 -- Manejo de Archivos
 * Archivo: 03_archivos_binarios.c
 * ============================================================
 *
 * Este archivo explica como trabajar con archivos binarios en C.
 *
 * Un archivo de texto guarda informacion legible para humanos. Un archivo
 * binario guarda bytes directamente, tal como estan en memoria.
 *
 * Los archivos binarios son utiles para guardar estructuras completas,
 * datos compactos o informacion que no necesita editarse manualmente.
 *
 * Conceptos importantes:
 *
 *   "wb"    abre un archivo para escritura binaria.
 *   "rb"    abre un archivo para lectura binaria.
 *   fwrite  escribe bloques de bytes.
 *   fread   lee bloques de bytes.
 *   fseek   mueve la posicion dentro del archivo.
 *   ftell   indica la posicion actual dentro del archivo.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o binarios 03_archivos_binarios.c
 *
 * Ejecutar:
 *   Windows: binarios.exe
 *   Linux/macOS: ./binarios
 */

#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO "estudiantes.dat"

/*
 * Estructura que representa un estudiante.
 *
 * Guardaremos varios registros de este tipo en un archivo binario.
 */
typedef struct {
    char nombre[50];
    int edad;
    double promedio;
} Estudiante;

/*
 * Escribe un arreglo de estudiantes en formato binario.
 */
void escribirBinario(const Estudiante estudiantes[], int cantidad) {
    FILE *archivo = fopen(ARCHIVO, "wb");

    if (archivo == NULL) {
        perror("Error al crear archivo binario");
        return;
    }

    /*
     * fwrite recibe:
     * - direccion de los datos
     * - tamano de cada elemento
     * - cantidad de elementos
     * - archivo destino
     */
    size_t escritos = fwrite(estudiantes, sizeof(Estudiante), cantidad, archivo);

    printf("Estructuras escritas: %zu de %d\n", escritos, cantidad);

    if (fclose(archivo) != 0) {
        perror("Error al cerrar archivo binario");
    }
}

/*
 * Lee estructuras desde el archivo binario y las muestra.
 */
void leerBinario(void) {
    FILE *archivo = fopen(ARCHIVO, "rb");

    if (archivo == NULL) {
        perror("Error al abrir archivo binario");
        return;
    }

    /*
     * Para saber cuantos registros hay, primero vamos al final del archivo
     * y usamos ftell para conocer su tamano en bytes.
     */
    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    fseek(archivo, 0, SEEK_SET);

    int cantidad = (int)(tamano / sizeof(Estudiante));

    printf("\nTamano del archivo: %ld bytes (%d registros)\n", tamano, cantidad);

    printf("\n=== Contenido del archivo binario ===\n");

    Estudiante est;

    /*
     * fread devuelve la cantidad de elementos leidos correctamente.
     * Mientras devuelva 1, significa que se leyo un estudiante completo.
     */
    while (fread(&est, sizeof(Estudiante), 1, archivo) == 1) {
        printf("  %-20s | Edad: %2d | Promedio: %.1f\n",
               est.nombre, est.edad, est.promedio);
    }

    if (fclose(archivo) != 0) {
        perror("Error al cerrar archivo binario");
    }
}

int main(void) {
    printf("Modulo 10 - Archivos binarios\n");
    printf("==============================\n\n");

    Estudiante estudiantes[] = {
        {"Ana Garcia", 20, 9.5},
        {"Carlos Lopez", 22, 8.7},
        {"Maria Torres", 19, 9.2},
        {"Pedro Ruiz", 21, 7.8}
    };

    int cantidad = sizeof(estudiantes) / sizeof(estudiantes[0]);

    printf("Escribiendo %d registros en formato binario...\n", cantidad);
    escribirBinario(estudiantes, cantidad);

    leerBinario();

    return EXIT_SUCCESS;
}
