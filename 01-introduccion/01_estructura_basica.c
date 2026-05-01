/*
 * ============================================================
 * Modulo 01 -- Introduccion a C
 * Archivo: 01_estructura_basica.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este programa muestra la estructura mas basica que puede tener
 * un programa escrito en lenguaje C.
 *
 * La idea es que una persona que nunca ha programado pueda entender:
 *
 *   1. Que es una libreria.
 *   2. Para que sirve #include.
 *   3. Que es la funcion main().
 *   4. Que significa escribir instrucciones dentro de main().
 *   5. Como mostrar texto en la consola usando printf().
 *   6. Para que sirve return 0.
 *   7. Como compilar y ejecutar este archivo.
 *
 * ------------------------------------------------------------
 * Que es un programa en C?
 * ------------------------------------------------------------
 * Un programa en C es un archivo de texto que contiene instrucciones
 * escritas con una sintaxis especifica. Esas instrucciones no las
 * entiende directamente la computadora al principio.
 *
 * Por eso necesitamos un compilador.
 *
 * El compilador toma este archivo .c y lo traduce a un programa
 * ejecutable que la computadora si puede correr.
 *
 * ------------------------------------------------------------
 * Comando para compilar este archivo
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o estructura_basica 01_estructura_basica.c
 *
 * Explicacion rapida del comando:
 *
 *   gcc
 *     Es el compilador que traduce codigo C a un programa ejecutable.
 *
 *   -Wall -Wextra
 *     Activan advertencias utiles para detectar posibles errores.
 *
 *   -std=c11
 *     Le indica al compilador que use el estandar C11 del lenguaje C.
 *
 *   -o estructura_basica
 *     Indica el nombre del archivo ejecutable que se va a generar.
 *
 *   01_estructura_basica.c
 *     Es el archivo de codigo fuente que queremos compilar.
 *
 * ------------------------------------------------------------
 * Como ejecutar el programa despues de compilarlo
 * ------------------------------------------------------------
 *
 * En Windows:
 *
 *   estructura_basica.exe
 *
 * En Linux o macOS:
 *
 *   ./estructura_basica
 *
 */

/*
 * #include sirve para incluir codigo ya hecho por otros programadores
 * o por el propio lenguaje C.
 *
 * En este caso incluimos la libreria stdio.h.
 *
 * stdio.h significa Standard Input/Output, es decir,
 * Entrada y Salida Estandar.
 *
 * Esta libreria nos permite usar funciones como printf(),
 * que sirve para mostrar texto en la consola.
 */
#include <stdio.h>

/*
 * main() es la funcion principal de un programa en C.
 *
 * Todo programa en C necesita una funcion main(), porque ahi es donde
 * comienza la ejecucion del programa.
 *
 * Cuando ejecutamos el programa, el sistema operativo busca main()
 * y empieza a ejecutar las instrucciones que estan dentro de sus llaves.
 *
 * En esta linea:
 *
 *   int main(void)
 *
 * int significa que la funcion main va a devolver un numero entero.
 * Ese numero se usa para indicar si el programa termino bien o si hubo
 * algun error.
 *
 * void significa que main no recibe datos de entrada.
 */
int main(void) {
    /*
     * Las llaves { } marcan el inicio y el final del bloque de codigo
     * que pertenece a la funcion main().
     *
     * Todo lo que este dentro de estas llaves se ejecutara en orden,
     * de arriba hacia abajo.
     */

    /*
     * printf() sirve para imprimir o mostrar texto en la consola.
     *
     * El texto que queremos mostrar se escribe entre comillas dobles.
     *
     * La secuencia \n significa salto de linea. Es decir, despues de
     * imprimir ese texto, el cursor baja a la siguiente linea.
     */
    printf("=== Estructura basica de un programa en C ===\n");

    /*
     * Esta segunda instruccion printf() muestra otro mensaje.
     *
     * Observa que cada instruccion termina con punto y coma ;
     *
     * En C, el punto y coma indica el final de una instruccion.
     */
    printf("Todo programa en C necesita una funcion main().\n");

    /*
     * Los comentarios son textos que el compilador ignora.
     *
     * Sirven para explicar el codigo y hacerlo mas facil de entender.
     *
     * Hay dos formas comunes de escribir comentarios en C:
     *
     *   1. Comentario de una linea:
     *      Se escribe usando dos barras inclinadas.
     *
     *      Ejemplo:
     *      // Esto es un comentario de una linea
     *
     *   2. Comentario de bloque:
     *      Se usa para escribir explicaciones de varias lineas.
     *      Comienza con barra y asterisco, y termina con asterisco y barra.
     *
     * Importante:
     * No conviene escribir un comentario de bloque dentro de otro comentario
     * de bloque, porque el lenguaje C no maneja bien comentarios anidados.
     */

    /*
     * Podemos usar printf() varias veces.
     * Cada llamada a printf() puede mostrar una linea diferente.
     */
    printf("El compilador traduce este archivo a codigo maquina.\n");
    printf("El archivo ejecutable resultante corre directamente en el procesador.\n");

    /*
     * return 0 finaliza la funcion main().
     *
     * El numero 0 normalmente significa que el programa termino correctamente.
     *
     * Si devolvieramos un numero diferente de 0, normalmente indicaria que
     * ocurrio algun tipo de error.
     */
    return 0;
}
