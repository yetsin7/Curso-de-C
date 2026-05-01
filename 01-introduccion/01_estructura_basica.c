/*
 * Modulo 01 -- Introduccion a C
 * Archivo: 01_estructura_basica.c
 *
 * Este archivo muestra la estructura minima de un programa en C:
 *   - #include: incluye librerias externas para usar funciones ya hechas
 *   - main(): punto de entrada donde el sistema operativo comienza la ejecucion
 *   - printf(): funcion para mostrar texto en la consola
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o estructura_basica 01_estructura_basica.c
 * Ejecutar: estructura_basica.exe   (Windows)
 *           ./estructura_basica     (Linux/macOS)
 */

/* stdio.h = Standard Input/Output. Proporciona printf, scanf, etc. */
#include <stdio.h>

/*
 * main -- Funcion principal de todo programa en C.
 * Recibe void (ningun argumento) y devuelve un entero (int).
 * El valor de retorno indica al sistema operativo si el programa termino bien (0) o con error (distinto de 0).
 */
int main(void) {
    /* printf imprime texto formateado en la salida estandar (consola) */
    printf("=== Estructura basica de un programa en C ===\n");

    /* La funcion printf acepta una cadena de texto entre comillas dobles */
    /* \n es una secuencia de escape que representa un salto de linea */
    printf("Todo programa en C necesita una funcion main().\n");

    /* Los comentarios de una linea comienzan con // o /* */
    /* Los comentarios de bloque se escriben entre /* y */

    /* Puedes llamar a printf varias veces para imprimir en diferentes lineas */
    printf("El compilador traduce este archivo a codigo maquina.\n");
    printf("El archivo ejecutable resultante corre directamente en el procesador.\n");

    /* return 0 indica que el programa termino exitosamente */
    return 0;
}
