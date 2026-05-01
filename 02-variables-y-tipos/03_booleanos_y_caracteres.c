/*
 * ============================================================
 * Modulo 02 -- Variables y Tipos de Datos
 * Archivo: 03_booleanos_y_caracteres.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este programa explica dos tipos de datos muy importantes en C:
 *
 *   1. bool
 *      Sirve para representar valores de verdadero o falso.
 *
 *   2. char
 *      Sirve para representar un caracter, como una letra, un numero
 *      escrito como simbolo o un signo especial.
 *
 * Tambien se explica que es una conversion de tipo o cast.
 *
 * ------------------------------------------------------------
 * bool en C
 * ------------------------------------------------------------
 *
 * En C moderno podemos usar bool incluyendo la libreria stdbool.h.
 *
 * Un valor bool puede ser:
 *
 *   true  -> verdadero
 *   false -> falso
 *
 * Internamente, C suele representar false como 0 y true como 1.
 *
 * ------------------------------------------------------------
 * char en C
 * ------------------------------------------------------------
 *
 * Un char guarda un solo caracter.
 *
 * Ejemplos:
 *
 *   'A', 'z', '$', '7'
 *
 * Los caracteres se escriben entre comillas simples.
 *
 * Aunque char se usa para letras, internamente tambien es un numero.
 * Ese numero corresponde a un codigo de caracteres, comunmente ASCII.
 *
 * ------------------------------------------------------------
 * Compilar
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o 03_booleanos 03_booleanos_y_caracteres.c
 *
 * Ejecutar en Windows:
 *
 *   03_booleanos.exe
 *
 * Ejecutar en Linux/macOS:
 *
 *   ./03_booleanos
 *
 */

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    printf("=== MODULO 02 - BOOLEANOS Y CARACTERES ===\n\n");

    /*
     * bool representa valores logicos.
     *
     * true significa verdadero.
     * false significa falso.
     */
    printf("--- Tipo bool ---\n");

    bool activo = true;
    bool visible = false;
    bool completado = 1;
    bool pendiente = 0;

    /*
     * printf() no tiene un especificador especial para bool.
     * Por eso se imprime con %d, mostrando 1 para true y 0 para false.
     */
    printf("activo:     %d\n", activo);
    printf("visible:    %d\n", visible);
    printf("completado: %d\n", completado);
    printf("pendiente:  %d\n", pendiente);

    /*
     * El operador ! significa negacion logica.
     *
     * Si activo es true, !activo es false.
     */
    printf("!activo:    %d\n", !activo);

    /*
     * char puede imprimirse como caracter usando %c.
     * Tambien puede imprimirse como numero usando %d.
     */
    printf("\n--- char como letra y como numero ---\n");

    char letra1 = 'A';
    char letra2 = 'z';
    char simbolo = '$';

    printf("Letra '%c' tiene codigo numerico: %d\n", letra1, letra1);
    printf("Letra '%c' tiene codigo numerico: %d\n", letra2, letra2);
    printf("Simbolo '%c' tiene codigo numerico: %d\n", simbolo, simbolo);

    /*
     * Tambien podemos crear un char usando su codigo numerico.
     *
     * En ASCII:
     * 65 representa 'A'.
     * 97 representa 'a'.
     * 33 representa '!'.
     */
    printf("\n--- Crear char desde codigo numerico ---\n");

    char c1 = 65;
    char c2 = 97;
    char c3 = 33;

    printf("Codigo 65 es: %c\n", c1);
    printf("Codigo 97 es: %c\n", c2);
    printf("Codigo 33 es: %c\n", c3);

    /*
     * Conversion de tipos o cast.
     *
     * Un cast le dice al compilador que trate un valor como si fuera
     * de otro tipo.
     *
     * Sintaxis:
     *
     *   (tipo)valor
     */
    printf("\n--- Conversion de tipos (cast) ---\n");

    int entero = 7;
    double decimal = 2.5;

    /*
     * Division entera:
     * Si ambos valores son enteros, C produce un resultado entero.
     */
    int resultado_ent = entero / 2;
    printf("7 / 2 como entero       = %d\n", resultado_ent);

    /*
     * Division con cast:
     * Convertimos entero a double para conservar la parte decimal.
     */
    double resultado_dec = (double)entero / 2;
    printf("7 / 2 con cast a double = %.1f\n", resultado_dec);

    /*
     * Al convertir double a int, la parte decimal se pierde.
     * No se redondea: se trunca.
     */
    int truncado = (int)decimal;
    printf("2.5 casteado a int      = %d\n", truncado);

    /*
     * Conversion entre char e int.
     */
    char letra = 'M';
    int codigo = (int)letra;
    char desde_num = (char)77;

    printf("'%c' como entero        = %d\n", letra, codigo);
    printf("77 como char            = %c\n", desde_num);

    /*
     * sizeof permite ver cuantos bytes ocupa cada tipo.
     */
    printf("\n--- Tamano en bytes ---\n");

    printf("sizeof(bool): %zu bytes\n", sizeof(bool));
    printf("sizeof(char): %zu bytes\n", sizeof(char));

    /*
     * Nota:
     * El rango exacto de char puede depender de si el compilador lo trata
     * como signed char o unsigned char por defecto.
     */
    printf("\n--- Nota sobre char ---\n");
    printf("char ocupa 1 byte, pero su interpretacion puede variar.\n");
    printf("signed char suele ir de -128 a 127.\n");
    printf("unsigned char suele ir de 0 a 255.\n");

    return 0;
}
