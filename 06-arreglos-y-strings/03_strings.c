/*
 * ============================================================
 * Modulo 06 -- Arreglos y Strings
 * Archivo: 03_strings.c
 * ============================================================
 *
 * Este archivo explica los strings en C.
 *
 * En C, un string no es un tipo especial como en otros lenguajes.
 * Un string es un arreglo de caracteres que termina con el caracter
 * especial '\0', llamado caracter nulo.
 *
 * Ejemplo:
 *
 *   "Hola"
 *
 * Internamente se guarda asi:
 *
 *   'H' 'o' 'l' 'a' '\0'
 *
 * Ese '\0' le indica a C donde termina el texto.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 03_strings 03_strings.c
 *
 * Ejecutar:
 *   Windows: 03_strings.exe
 *   Linux/macOS: ./03_strings
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    printf("=== STRINGS EN C ===\n\n");

    /*
     * Declaracion de strings.
     *
     * El compilador agrega '\0' automaticamente al final del texto.
     */
    char saludo[] = "Hola, mundo!";

    /*
     * Buffer con espacio reservado.
     *
     * nombre puede guardar hasta 49 caracteres visibles mas el '\0'.
     */
    char nombre[50] = "Carlos";

    /* String vacio. */
    char vacio[100] = "";

    printf("saludo: \"%s\"\n", saludo);
    printf("nombre: \"%s\"\n", nombre);
    printf("vacio:  \"%s\"\n", vacio);

    /*
     * strlen calcula la longitud del texto sin contar el '\0'.
     * sizeof muestra el tamano total del arreglo en bytes.
     */
    printf("\n=== STRLEN Y SIZEOF ===\n");
    printf("strlen(\"%s\") = %zu\n", saludo, strlen(saludo));
    printf("sizeof(nombre) = %zu bytes\n", sizeof(nombre));

    /*
     * Copiar strings.
     *
     * strcpy copia un texto completo, pero puede ser peligroso si el
     * destino no tiene suficiente espacio.
     */
    printf("\n=== COPIAR STRINGS ===\n");

    char destino[50];
    strcpy(destino, "Curso de C");
    printf("strcpy: \"%s\"\n", destino);

    /*
     * strncpy permite limitar cuantos caracteres se copian.
     * Despues garantizamos manualmente que el string termine en '\0'.
     */
    strncpy(destino, "Programacion en C", sizeof(destino) - 1);
    destino[sizeof(destino) - 1] = '\0';
    printf("strncpy: \"%s\"\n", destino);

    /*
     * Concatenar significa unir textos.
     *
     * strcat agrega texto al final de otro string.
     * El arreglo destino debe tener espacio suficiente.
     */
    printf("\n=== CONCATENAR STRINGS ===\n");

    char frase[100] = "Hola";
    strcat(frase, ", ");
    strcat(frase, "mundo");
    strcat(frase, "!");

    printf("Concatenado: \"%s\"\n", frase);

    /*
     * Comparar strings.
     *
     * En C no se comparan strings con ==.
     * Para comparar contenido se usa strcmp.
     *
     * strcmp devuelve 0 cuando los strings son iguales.
     */
    printf("\n=== COMPARAR STRINGS ===\n");

    const char *s1 = "manzana";
    const char *s2 = "naranja";
    const char *s3 = "manzana";

    printf("strcmp(\"%s\", \"%s\") = %d\n", s1, s2, strcmp(s1, s2));
    printf("strcmp(\"%s\", \"%s\") = %d\n", s1, s3, strcmp(s1, s3));

    if (strcmp(s1, s3) == 0) {
        printf("s1 y s3 tienen el mismo texto.\n");
    }

    /*
     * snprintf escribe texto dentro de un buffer respetando su tamano.
     * Es mas seguro que sprintf porque ayuda a evitar desbordamientos.
     */
    printf("\n=== FORMATEAR TEXTO CON snprintf ===\n");

    char buffer[80];
    const char *producto = "teclado";
    int precio = 1500;

    snprintf(buffer, sizeof(buffer), "Producto: %s, Precio: $%d", producto, precio);
    printf("Buffer seguro: \"%s\"\n", buffer);

    /*
     * Recorrer un string caracter por caracter.
     *
     * El bucle termina cuando encuentra '\0'.
     */
    printf("\n=== RECORRER CARACTER POR CARACTER ===\n");

    const char *palabra = "Cadena";

    printf("Caracteres de \"%s\":\n", palabra);
    for (int i = 0; palabra[i] != '\0'; i++) {
        printf("[%d] = '%c'\n", i, palabra[i]);
    }

    return 0;
}
