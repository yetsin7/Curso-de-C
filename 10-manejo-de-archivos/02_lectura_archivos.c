/*
 * Modulo 10 -- Lectura de Archivos
 * Compilar: gcc -Wall -Wextra -std=c11 -o lectura 02_lectura_archivos.c
 *
 * Demuestra como leer archivos de texto:
 *   - fopen con modo "r" (solo lectura)
 *   - fgets para leer linea por linea
 *   - fscanf para lectura con formato
 *   - Manejo correcto de EOF (fin de archivo)
 *   - Verificacion de errores con NULL
 */

#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO "notas.txt"
#define MAX_LINEA 256

/* Lee el archivo completo linea por linea con fgets */
void leerLineaPorLinea(const char *ruta) {
    FILE *archivo = fopen(ruta, "r");

    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        return;
    }

    char linea[MAX_LINEA];
    int numLinea = 1;

    printf("=== Contenido linea por linea ===\n");
    /* fgets devuelve NULL al llegar a EOF */
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("  Linea %2d: %s", numLinea, linea);
        numLinea++;
    }

    fclose(archivo);
    printf("\nTotal de lineas leidas: %d\n", numLinea - 1);
}

/* Lee datos con formato usando fscanf */
void leerConFormato(const char *ruta) {
    FILE *archivo = fopen(ruta, "r");

    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        return;
    }

    char nombre[100];
    double nota;
    int encontrados = 0;

    printf("\n=== Lectura con formato (fscanf) ===\n");
    /* Buscar patrones "Nombre: X" y "Nota: X" en el archivo */
    while (fscanf(archivo, "Nombre: %99[^\n]\nNota: %lf\n", nombre, &nota) == 2) {
        printf("  Estudiante: %-20s Nota: %.1f\n", nombre, nota);
        encontrados++;
    }

    fclose(archivo);
    printf("\nRegistros encontrados con formato: %d\n", encontrados);
}

int main(void) {
    printf("Modulo 10 - Lectura de archivos\n");
    printf("================================\n\n");

    /* Primero leer linea por linea */
    leerLineaPorLinea(ARCHIVO);

    /* Luego leer con formato especifico */
    leerConFormato(ARCHIVO);

    return EXIT_SUCCESS;
}
