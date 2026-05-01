/*
 * ============================================================
 * Modulo 02 -- Variables y Tipos de Datos
 * Archivo: 04_conversor_unidades.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este programa muestra un proyecto practico sencillo: un conversor
 * de unidades.
 *
 * El objetivo es practicar varios tipos de datos al mismo tiempo:
 *
 *   int     -> numeros enteros
 *   float   -> numeros decimales de precision simple
 *   double  -> numeros decimales con mayor precision
 *   bool    -> valores verdadero/falso
 *   cast    -> conversion manual entre tipos
 *
 * ------------------------------------------------------------
 * Que es convertir unidades?
 * ------------------------------------------------------------
 *
 * Convertir unidades significa expresar una misma cantidad usando otra
 * escala de medida.
 *
 * Ejemplos:
 *
 *   100 grados Celsius equivalen a 212 grados Fahrenheit.
 *   1 metro equivale aproximadamente a 3.28084 pies.
 *   1 kilogramo equivale aproximadamente a 2.20462 libras.
 *
 * ------------------------------------------------------------
 * Compilar
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o 04_conversor 04_conversor_unidades.c
 *
 * Ejecutar en Windows:
 *
 *   04_conversor.exe
 *
 * Ejecutar en Linux/macOS:
 *
 *   ./04_conversor
 *
 */

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    printf("=== CONVERSOR DE UNIDADES ===\n\n");

    /*
     * Conversion de Celsius a Fahrenheit.
     *
     * Formula:
     *   F = C * 9 / 5 + 32
     *
     * Usamos 9.0f, 5.0f y 32.0f para que el calculo se haga con
     * numeros flotantes y conserve decimales.
     */
    printf("--- Temperatura (Celsius a Fahrenheit) ---\n");

    float celsius = 36.5f;
    float fahrenheit = (celsius * 9.0f / 5.0f) + 32.0f;

    printf("%.2f C = %.2f F\n", celsius, fahrenheit);

    celsius = 100.0f;
    fahrenheit = (celsius * 9.0f / 5.0f) + 32.0f;
    printf("%.2f C (agua hierve) = %.2f F\n", celsius, fahrenheit);

    celsius = 0.0f;
    fahrenheit = (celsius * 9.0f / 5.0f) + 32.0f;
    printf("%.2f C (agua congela) = %.2f F\n", celsius, fahrenheit);

    /*
     * Conversion de metros a pies y de kilometros a millas.
     *
     * Usamos double porque las distancias pueden necesitar mas precision,
     * especialmente cuando se trabaja con muchos decimales.
     */
    printf("\n--- Longitud ---\n");

    double metros = 180.0;
    double pies = metros * 3.28084;

    double kilometros = 5.0;
    double millas = kilometros * 0.621371;

    printf("%.2f metros = %.2f pies\n", metros, pies);
    printf("%.2f kilometros = %.4f millas\n", kilometros, millas);

    /*
     * Conversion de kilogramos a libras.
     *
     * Usamos float porque para este ejemplo la precision es suficiente.
     */
    printf("\n--- Peso (kilogramos a libras) ---\n");

    float kilogramos = 75.5f;
    float libras = kilogramos * 2.20462f;

    printf("%.2f kg = %.2f lbs\n", kilogramos, libras);

    /*
     * Ejemplo de cast.
     *
     * Aqui convertimos un resultado decimal a int.
     * Al hacer esto, C elimina la parte decimal. No redondea.
     */
    int kg_entero = 70;
    int lbs_entero = (int)(kg_entero * 2.20462f);
    printf("%d kg convertido a int = %d lbs aproximadas\n", kg_entero, lbs_entero);

    /*
     * Conversiones inversas.
     *
     * Fahrenheit a Celsius:
     *   C = (F - 32) * 5 / 9
     *
     * Pies a metros:
     *   metros = pies / 3.28084
     */
    printf("\n--- Conversiones inversas ---\n");

    fahrenheit = 98.6f;
    celsius = (fahrenheit - 32.0f) * 5.0f / 9.0f;
    printf("%.2f F = %.2f C\n", fahrenheit, celsius);

    pies = 100.0;
    metros = pies / 3.28084;
    printf("%.2f pies = %.4f metros\n", pies, metros);

    /*
     * bool puede servir para controlar opciones del programa.
     *
     * En este ejemplo, modo_metrico indica si estamos convirtiendo
     * desde el sistema metrico al sistema imperial.
     */
    printf("\n--- Modo de conversion ---\n");

    bool modo_metrico = true;

    if (modo_metrico) {
        printf("Modo actual: Metrico a Imperial\n");
    } else {
        printf("Modo actual: Imperial a Metrico\n");
    }

    /*
     * Resumen final de lo practicado.
     */
    printf("\n--- Tipos utilizados en este conversor ---\n");
    printf("float:  temperatura y peso con decimales.\n");
    printf("double: longitud con mayor precision.\n");
    printf("int:    valores enteros sin decimales.\n");
    printf("bool:   control de una opcion verdadera o falsa.\n");
    printf("cast:   conversion manual entre tipos.\n");

    printf("\n=== FIN DEL CONVERSOR ===\n");

    return 0;
}
