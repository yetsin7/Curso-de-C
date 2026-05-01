/*
 * Modulo 02 - Conversor de Unidades
 * Compilar: gcc -Wall -Wextra -std=c11 -o 04_conversor 04_conversor_unidades.c
 *
 * Proyecto practico: conversor de unidades que demuestra el uso de
 * tipos enteros, flotantes, bool y cast. Convierte temperatura,
 * longitud y peso entre sistemas metrico e imperial.
 */

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    printf("=== CONVERSOR DE UNIDADES ===\n\n");

    /* --- Conversion de temperatura --- */
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

    /* --- Conversion de longitud --- */
    printf("\n--- Longitud (metros a pies) ---\n");

    double metros = 180.0;
    double pies = metros * 3.28084;
    double kilometros = 5.0;
    double millas = kilometros * 0.621371;

    printf("%.2f metros = %.2f pies\n", metros, pies);
    printf("%.2f km = %.4f millas\n", kilometros, millas);

    /* --- Conversion de peso --- */
    printf("\n--- Peso (kilogramos a libras) ---\n");

    float kilogramos = 75.5f;
    float libras = kilogramos * 2.20462f;

    printf("%.2f kg = %.2f lbs\n", kilogramos, libras);

    int kg_entero = 70;
    int lbs_entero = (int)(kg_entero * 2.20462f);
    printf("%d kg (entero) = %d lbs (entero)\n", kg_entero, lbs_entero);

    /* --- Conversion inversa --- */
    printf("\n--- Conversiones inversas ---\n");

    fahrenheit = 98.6f;
    celsius = (fahrenheit - 32.0f) * 5.0f / 9.0f;
    printf("%.2f F = %.2f C\n", fahrenheit, celsius);

    pies = 100.0;
    metros = pies / 3.28084;
    printf("%.2f pies = %.4f metros\n", pies, metros);

    /* --- Uso de bool para seleccionar modo --- */
    printf("\n--- Modo de conversion ---\n");

    bool modo_metrico = true;
    bool modo_imperial = false;

    if (modo_metrico) {
        printf("Modo actual: Metrico a Imperial\n");
    } else {
        printf("Modo actual: Imperial a Metrico\n");
    }

    /* --- Resumen de tipos usados --- */
    printf("\n--- Tipos utilizados en este conversor ---\n");
    printf("float:  temperatura y peso (precision suficiente)\n");
    printf("double: longitud (mayor precision para distancias)\n");
    printf("int:    valores exactos sin decimales\n");
    printf("bool:   control de modo de conversion\n");
    printf("cast:   conversion entre int y float al truncar libras\n");

    printf("\n=== FIN DEL CONVERSOR ===\n");

    return 0;
}
