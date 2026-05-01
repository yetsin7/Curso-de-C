/*
 * Modulo 06 -- Arreglos y Strings
 * Archivo: 03_strings.c
 *
 * Demuestra el manejo de cadenas de texto (strings):
 *   - Declaracion de strings
 *   - Funciones de string.h: strlen, strcpy, strncpy, strcat, strcmp
 *   - Manejo seguro con snprintf
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 03_strings 03_strings.c
 */

#include <stdio.h>
#include <string.h>

int main(void) {

    /* --- Declaracion de strings --- */
    printf("=== DECLARACION DE STRINGS ===\n");

    /* El compilador agrega '\0' automaticamente */
    char saludo[] = "Hola, mundo!";

    /* Buffer con espacio reservado */
    char nombre[50] = "Carlos";

    /* String vacio */
    char vacio[100] = "";

    printf("saludo: \"%s\"\n", saludo);
    printf("nombre: \"%s\"\n", nombre);
    printf("vacio:  \"%s\"\n", vacio);

    /* --- strlen: longitud sin contar el '\0' --- */
    printf("\n=== STRLEN ===\n");

    printf("strlen(\"%s\") = %zu\n", saludo, strlen(saludo));
    printf("sizeof(nombre) = %zu (incluye el nulo)\n", sizeof(nombre));

    /* --- strcpy y strncpy: copiar strings --- */
    printf("\n=== STRCPY / STRNCPY ===\n");

    char destino[50];
    strcpy(destino, "Curso de C");
    printf("strcpy: \"%s\"\n", destino);

    /* strncpy es mas seguro: limita la cantidad de caracteres */
    strncpy(destino, "Programacion en C", sizeof(destino) - 1);
    destino[sizeof(destino) - 1] = '\0'; /* garantizar terminacion */
    printf("strncpy: \"%s\"\n", destino);

    /* --- strcat: concatenar strings --- */
    printf("\n=== STRCAT ===\n");

    char frase[100] = "Hola";
    strcat(frase, ", ");
    strcat(frase, "mundo");
    strcat(frase, "!");
    printf("Concatenado: \"%s\"\n", frase);

    /* --- strcmp: comparar strings --- */
    printf("\n=== STRCMP ===\n");

    const char *s1 = "manzana";
    const char *s2 = "naranja";
    const char *s3 = "manzana";

    /* Retorna 0 si son iguales, negativo si s1 < s2, positivo si s1 > s2 */
    printf("strcmp(\"%s\", \"%s\") = %d\n", s1, s2, strcmp(s1, s2));
    printf("strcmp(\"%s\", \"%s\") = %d (iguales)\n", s1, s3, strcmp(s1, s3));

    if (strcmp(s1, s3) == 0) {
        printf("Los strings son iguales\n");
    }

    /* --- Manejo seguro con snprintf --- */
    printf("\n=== SPRINTF SEGURO CON snprintf ===\n");

    char buffer[80];
    const char *producto = "teclado";
    int precio = 1500;

    /* snprintf evita desbordamiento del buffer */
    snprintf(buffer, sizeof(buffer), "Producto: %s, Precio: $%d", producto, precio);
    printf("Buffer seguro: \"%s\"\n", buffer);

    /* Recorrer un string caracter por caracter */
    printf("\n=== RECORRER CARACTER POR CARACTER ===\n");

    const char *palabra = "Cadena";
    printf("Caracteres de \"%s\":\n", palabra);
    for (int i = 0; palabra[i] != '\0'; i++) {
        printf("  [%d] = '%c'\n", i, palabra[i]);
    }

    return 0;
}
