/*
 * ============================================================
 * Modulo 01 -- Introduccion a C
 * Archivo: 02_compilar_y_ejecutar.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este programa explica, con palabras sencillas, que significa
 * compilar y ejecutar un programa escrito en C.
 *
 * Cuando escribes codigo en C, la computadora no lo ejecuta
 * directamente como texto. Primero necesitas convertir ese archivo
 * de codigo fuente en un archivo ejecutable. Ese proceso se llama
 * compilacion.
 *
 * ------------------------------------------------------------
 * Conceptos importantes
 * ------------------------------------------------------------
 *
 * Codigo fuente:
 *   Es el archivo que escribe el programador. Normalmente termina
 *   con extension .c. Este archivo contiene instrucciones en C.
 *
 * Compilador:
 *   Es un programa que traduce el codigo fuente a codigo que la
 *   computadora puede ejecutar. En este curso usamos GCC.
 *
 * Ejecutable:
 *   Es el resultado de compilar. Es el programa final que puedes
 *   abrir desde la terminal.
 *
 * Terminal:
 *   Es una ventana donde escribes comandos. En Windows puede ser
 *   PowerShell, CMD o Windows Terminal. En Linux/macOS suele llamarse
 *   Terminal.
 *
 * ------------------------------------------------------------
 * Comandos de compilacion
 * ------------------------------------------------------------
 *
 * Compilacion basica:
 *
 *   gcc -o programa 02_compilar_y_ejecutar.c
 *
 * Compilacion recomendada durante este curso:
 *
 *   gcc -Wall -Wextra -std=c11 -o programa 02_compilar_y_ejecutar.c
 *
 * Compilacion mas estricta:
 *
 *   gcc -Wall -Wextra -pedantic -std=c11 -o programa 02_compilar_y_ejecutar.c
 *
 * ------------------------------------------------------------
 * Como ejecutar despues de compilar
 * ------------------------------------------------------------
 *
 * En Windows:
 *
 *   programa.exe
 *
 * En Linux o macOS:
 *
 *   ./programa
 *
 */

#include <stdio.h>

int main(void) {
    printf("=== Compilacion y ejecucion en C ===\n");

    /*
     * Paso 1:
     * Abre una terminal en la carpeta donde esta este archivo.
     *
     * La terminal debe estar ubicada en la misma carpeta del archivo .c,
     * porque asi el compilador puede encontrarlo facilmente.
     */
    printf("\nPaso 1: Abre una terminal en la carpeta del archivo .c.\n");

    /*
     * Paso 2:
     * Escribe un comando de compilacion.
     *
     * Este comando le dice a GCC que tome el archivo .c y cree un
     * ejecutable llamado programa.
     */
    printf("Paso 2: Compila con gcc.\n");
    printf("Comando recomendado:\n");
    printf("gcc -Wall -Wextra -std=c11 -o programa 02_compilar_y_ejecutar.c\n");

    /*
     * Paso 3:
     * Si el codigo no tiene errores graves, GCC genera un ejecutable.
     *
     * En Windows normalmente sera programa.exe.
     * En Linux/macOS normalmente sera programa.
     */
    printf("\nPaso 3: Si no hay errores, se crea el ejecutable.\n");

    /*
     * Paso 4:
     * Ejecuta el programa generado.
     */
    printf("Paso 4: Ejecuta el programa.\n");
    printf("Windows: programa.exe\n");
    printf("Linux/macOS: ./programa\n");

    /*
     * Las banderas o flags son opciones que modifican el comportamiento
     * del compilador.
     *
     * En este curso conviene usarlas porque ayudan a detectar errores
     * desde el inicio.
     */
    printf("\nFlags utiles de GCC:\n");
    printf("-Wall     : Activa muchas advertencias comunes.\n");
    printf("-Wextra   : Activa advertencias adicionales.\n");
    printf("-std=c11  : Usa el estandar C11 del lenguaje C.\n");
    printf("-pedantic : Avisa cuando usas cosas fuera del estandar.\n");
    printf("-o nombre : Define el nombre del archivo ejecutable.\n");
    printf("-g        : Agrega informacion para depurar con herramientas como gdb.\n");
    printf("-O2       : Optimiza el programa para que pueda correr mas rapido.\n");

    /*
     * Recomendacion:
     * Para aprender, no ignores las advertencias del compilador.
     * Muchas veces una advertencia indica un error que todavia no ha
     * roto el programa, pero podria hacerlo despues.
     */
    printf("\nRecomendacion: usa siempre -Wall -Wextra mientras aprendes.\n");

    return 0;
}
