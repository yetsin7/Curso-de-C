/*
 * Modulo 01 -- Introduccion a C
 * Archivo: 02_compilar_y_ejecutar.c
 *
 * Este archivo explica como compilar y ejecutar programas en C
 * usando el compilador GCC con diferentes banderas (flags).
 *
 * Compilar (basico):      gcc -o programa 02_compilar_y_ejecutar.c
 * Compilar (recomendado): gcc -Wall -Wextra -std=c11 -o programa 02_compilar_y_ejecutar.c
 * Compilar (estricto):    gcc -Wall -Wextra -pedantic -std=c11 -o programa 02_compilar_y_ejecutar.c
 *
 * Ejecutar: programa.exe   (Windows)
 *           ./programa     (Linux/macOS)
 */

#include <stdio.h>

int main(void) {
    printf("=== Compilacion y ejecucion en C ===\n");

    /*
     * Pasos para compilar y ejecutar:
     *
     * 1. Abre una terminal en la carpeta donde esta este archivo .c
     *
     * 2. Compila con gcc:
     *    gcc -Wall -Wextra -std=c11 -o programa 02_compilar_y_ejecutar.c
     *
     * 3. Si no hay errores, se genera un archivo ejecutable llamado "programa"
     *    (en Windows sera "programa.exe")
     *
     * 4. Ejecuta el programa:
     *    Windows: programa.exe
     *    Linux/macOS: ./programa
     */

    printf("\nFlags utiles de GCC:\n");
    printf("-Wall          : Activa la mayoria de advertencias (warnings)\n");
    printf("-Wextra        : Activa advertencias adicionales\n");
    printf("-std=c11       : Usa el estandar C del ano 2011\n");
    printf("-pedantic      : Rechaza extensiones no estandar del compilador\n");
    printf("-o nombre      : Define el nombre del archivo de salida\n");
    printf("-g             : Incluye informacion de depuracion (para gdb)\n");
    printf("-O2            : Optimiza el codigo para mejor rendimiento\n");

    printf("\nSiempre compila con -Wall -Wextra para detectar errores pronto.\n");

    return 0;
}
