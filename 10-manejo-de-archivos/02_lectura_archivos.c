/*
 * ============================================================
 * Modulo 10 -- Manejo de Archivos
 * Archivo: 02_lectura_archivos.c
 * ============================================================
 *
 * Este archivo explica como leer archivos de texto en C.
 *
 * Leer un archivo significa abrirlo y traer su contenido al programa.
 * Despues podemos imprimirlo, analizarlo o extraer datos especificos.
 *
 * Conceptos importantes:
 *
 *   fopen   abre un archivo.
 *   fgets   lee una linea completa o parte de una linea.
 *   fscanf  lee datos con un formato esperado.
 *   EOF     significa fin de archivo.
 *   fclose  cierra el archivo.
 *
 * Modo "r":
 *   Abre el archivo solo para lectura. El archivo debe existir.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o lectura 02_lectura_archivos.c
 *
 * Ejecutar:
 *   Windows: lectura.exe
 *   Linux/macOS: ./lectura
 */

#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO "notas.txt"
#define MAX_LINEA 256

/*
 * Lee un archivo linea por linea usando fgets.
 *
 * Esta es una forma segura y comun de leer archivos de texto.
 */
void leerLineaPorLinea(const char *ruta) {
    FILE *archivo = fopen(ruta, "r");

    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        return;
    }

    char linea[MAX_LINEA];
    int numLinea = 1;

    printf("=== Contenido linea por linea ===\n");

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("Linea %2d: %s", numLinea, linea);
        numLinea++;
    }

    fclose(archivo);

    printf("\nTotal de lineas leidas: %d\n", numLinea - 1);
}

/*
 * Lee datos con formato usando fscanf.
 *
 * fscanf sirve cuando el archivo tiene una estructura conocida.
 */
void leerConFormato(const char *ruta) {
    FILE *archivo = fopen(ruta, "r");

    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        return;
    }

    char nombre[100];
    double nota;
    int encontrados = 0;

    printf("\n=== Lectura con formato usando fscanf ===\n");

    while (fscanf(archivo, "Nombre: %99[^\n]\nNota: %lf\n", nombre, &nota) == 2) {
        printf("Estudiante: %-20s Nota: %.1f\n", nombre, nota);
        encontrados++;
    }

    fclose(archivo);

    printf("\nRegistros encontrados con formato: %d\n", encontrados);
}

int main(void) {
    printf("Modulo 10 - Lectura de archivos\n");
    printf("================================\n\n");

    /*
     * Este programa espera que exista el archivo notas.txt.
     * Puedes crearlo ejecutando primero 01_escritura_archivos.c.
     */
    leerLineaPorLinea(ARCHIVO);
    leerConFormato(ARCHIVO);

    return EXIT_SUCCESS;
}
