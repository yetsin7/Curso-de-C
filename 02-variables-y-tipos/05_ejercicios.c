/*
 * ============================================================
 * Modulo 02 -- Variables y Tipos de Datos
 * Archivo: 05_ejercicios.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este archivo contiene ejercicios para practicar los tipos de datos
 * vistos en el Modulo 02.
 *
 * La meta es que puedas usar correctamente:
 *
 *   - int para numeros enteros.
 *   - float y double para numeros con decimales.
 *   - char para caracteres.
 *   - bool para valores verdadero/falso.
 *   - cast para convertir manualmente entre tipos.
 *
 * ------------------------------------------------------------
 * Como usar este archivo
 * ------------------------------------------------------------
 *
 * 1. Lee cada ejercicio.
 * 2. Escribe tu solucion debajo del comentario correspondiente.
 * 3. Compila el archivo.
 * 4. Ejecuta el programa.
 * 5. Verifica si el resultado tiene sentido.
 *
 * No intentes resolver todo de una vez. Haz un ejercicio, prueba, y
 * luego sigue con el siguiente.
 *
 * ------------------------------------------------------------
 * Compilar
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o 05_ejercicios 05_ejercicios.c
 *
 * Ejecutar en Windows:
 *
 *   05_ejercicios.exe
 *
 * Ejecutar en Linux/macOS:
 *
 *   ./05_ejercicios
 *
 */

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    printf("=== EJERCICIOS - MODULO 02 ===\n\n");

    /*
     * Ejercicio 1:
     * Crea una variable int con valor 42 y muestra su doble.
     *
     * Pista:
     * El doble de un numero se obtiene multiplicando por 2.
     *
     * Ejemplo de idea:
     *   int numero = 42;
     *   int doble = numero * 2;
     */
    printf("Ejercicio 1: Crea una variable int con valor 42 y muestra su doble.\n");

    /*
     * Ejercicio 2:
     * Guarda el resultado de 22 / 7 en una variable float y en una
     * variable double. Luego imprime ambos resultados con 15 decimales.
     *
     * Pista:
     * Usa 22.0f / 7.0f para float.
     * Usa 22.0 / 7.0 para double.
     *
     * Observa cual conserva mas precision.
     */
    printf("Ejercicio 2: Guarda 22/7 en float y double, imprime ambos con 15 decimales.\n");

    /*
     * Ejercicio 3:
     * Crea una variable char con una letra mayuscula y muestra su codigo
     * numerico.
     *
     * Pista:
     * Puedes imprimir un char como numero usando %%d.
     *
     * Ejemplo:
     *   char letra = 'A';
     *   printf("%%c = %%d\\n", letra, letra);
     */
    printf("Ejercicio 3: Crea una letra mayuscula y muestra su codigo numerico.\n");

    /*
     * Ejercicio 4:
     * Crea una variable int y usa bool para indicar si ese numero es par.
     *
     * Pista:
     * Un numero es par si al dividirlo entre 2 el residuo es 0.
     *
     * En C, el operador %% obtiene el residuo de una division.
     *
     * Ejemplo:
     *   bool es_par = (numero %% 2 == 0);
     */
    printf("Ejercicio 4: Crea una variable int y usa bool para indicar si es par.\n");

    /*
     * Ejercicio 5:
     * Convierte un valor double a int usando cast y observa que pasa con
     * la parte decimal.
     *
     * Pista:
     *   double precio = 19.99;
     *   int precio_entero = (int)precio;
     */
    printf("Ejercicio 5: Convierte un double a int usando cast.\n");

    printf("\n--- Completa cada ejercicio y compila para verificar ---\n");

    return 0;
}
