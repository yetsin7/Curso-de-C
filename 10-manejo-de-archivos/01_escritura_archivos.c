/*
 * Modulo 10 -- Escritura de Archivos
 * Compilar: gcc -Wall -Wextra -std=c11 -o escritura 01_escritura_archivos.c
 *
 * Demuestra como crear y escribir archivos de texto:
 *   - fopen con modo "w" (escribir, sobrescribe existente)
 *   - fprintf para salida con formato
 *   - fputs para escribir cadenas completas
 *   - fclose para liberar recursos y vaciar buffers
 *   - Verificacion de errores con NULL
 */

#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO "notas.txt"

/* Escribe datos con formato usando fprintf */
void escribirConFormato(FILE *archivo) {
    fprintf(archivo, "=== Registro de Estudiantes ===\n");
    fprintf(archivo, "Nombre: Ana Garcia\n");
    fprintf(archivo, "Nota: 9.5\n");
    fprintf(archivo, "Materia: Programacion en C\n");
}

/* Escribe texto plano usando fputs */
void escribirTextoPlano(FILE *archivo) {
    fputs("\n--- Segunda seccion ---\n", archivo);
    fputs("Carlos Lopez - Nota: 8.7\n", archivo);
    fputs("Maria Torres - Nota: 9.2\n", archivo);
    fputs("Pedro Ruiz - Nota: 7.8\n", archivo);
}

int main(void) {
    /* Abrir archivo en modo escritura (crea o sobrescribe) */
    FILE *archivo = fopen(ARCHIVO, "w");

    /* Verificar que se abrio correctamente */
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }

    printf("Archivo '%s' abierto para escritura.\n", ARCHIVO);

    /* Escribir con formato (como printf pero al archivo) */
    escribirConFormato(archivo);
    printf("Datos con formato escritos correctamente.\n");

    /* Escribir texto plano con fputs (mas rapido para cadenas simples) */
    escribirTextoPlano(archivo);
    printf("Texto plano escrito correctamente.\n");

    /* CERRAR EL ARCHIVO: fundamental para vaciar buffers y liberar recursos */
    if (fclose(archivo) != 0) {
        perror("Error al cerrar el archivo");
        return EXIT_FAILURE;
    }

    printf("Archivo cerrado exitosamente. Datos guardados en disco.\n");
    printf("\nPara ver el contenido, abre el archivo: %s\n", ARCHIVO);

    return EXIT_SUCCESS;
}
