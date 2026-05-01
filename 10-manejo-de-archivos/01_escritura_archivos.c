/*
 * ============================================================
 * Modulo 10 -- Manejo de Archivos
 * Archivo: 01_escritura_archivos.c
 * ============================================================
 *
 * Este archivo explica como crear y escribir archivos de texto en C.
 *
 * Hasta ahora los programas imprimian informacion en la consola. Pero
 * muchas veces necesitamos guardar datos para usarlos despues. Para eso
 * usamos archivos.
 *
 * Conceptos importantes:
 *
 *   FILE*    representa un archivo abierto.
 *   fopen    abre un archivo.
 *   fprintf  escribe texto con formato en un archivo.
 *   fputs    escribe una cadena de texto en un archivo.
 *   fclose   cierra el archivo.
 *
 * Modo "w":
 *   Abre el archivo para escritura. Si no existe, lo crea. Si ya existe,
 *   borra su contenido anterior y lo sobrescribe.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o escritura 01_escritura_archivos.c
 *
 * Ejecutar:
 *   Windows: escritura.exe
 *   Linux/macOS: ./escritura
 */

#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO "notas.txt"

/*
 * Escribe datos con formato usando fprintf.
 *
 * fprintf funciona parecido a printf, pero en vez de imprimir en pantalla,
 * escribe dentro de un archivo.
 */
void escribirConFormato(FILE *archivo) {
    fprintf(archivo, "=== Registro de Estudiantes ===\n");
    fprintf(archivo, "Nombre: Ana Garcia\n");
    fprintf(archivo, "Nota: 9.5\n");
    fprintf(archivo, "Materia: Programacion en C\n");
}

/*
 * Escribe texto plano usando fputs.
 *
 * fputs es util cuando ya tienes una cadena completa y solo quieres
 * guardarla en el archivo.
 */
void escribirTextoPlano(FILE *archivo) {
    fputs("\n--- Segunda seccion ---\n", archivo);
    fputs("Carlos Lopez - Nota: 8.7\n", archivo);
    fputs("Maria Torres - Nota: 9.2\n", archivo);
    fputs("Pedro Ruiz - Nota: 7.8\n", archivo);
}

int main(void) {
    /*
     * Abrimos el archivo en modo escritura.
     */
    FILE *archivo = fopen(ARCHIVO, "w");

    /*
     * Siempre debemos verificar si fopen devolvio NULL.
     * NULL significa que el archivo no pudo abrirse.
     */
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }

    printf("Archivo '%s' abierto para escritura.\n", ARCHIVO);

    escribirConFormato(archivo);
    printf("Datos con formato escritos correctamente.\n");

    escribirTextoPlano(archivo);
    printf("Texto plano escrito correctamente.\n");

    /*
     * Cerrar el archivo es obligatorio.
     *
     * fclose guarda lo pendiente, libera recursos y termina la relacion
     * entre el programa y el archivo.
     */
    if (fclose(archivo) != 0) {
        perror("Error al cerrar el archivo");
        return EXIT_FAILURE;
    }

    printf("Archivo cerrado exitosamente.\n");
    printf("Abre el archivo '%s' para ver el contenido guardado.\n", ARCHIVO);

    return EXIT_SUCCESS;
}
