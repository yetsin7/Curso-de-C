/*
 * ============================================================
 * Modulo 01 -- Introduccion a C
 * Archivo: 04_calculadora_simple.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este programa junta varias ideas basicas vistas al inicio del curso:
 *
 *   1. Crear variables.
 *   2. Guardar numeros en esas variables.
 *   3. Hacer operaciones matematicas.
 *   4. Guardar los resultados en nuevas variables.
 *   5. Mostrar los resultados en la consola con printf().
 *
 * Es una calculadora simple porque no pide datos al usuario todavia.
 * Usa numeros escritos directamente en el codigo para que primero sea
 * facil entender la logica.
 *
 * ------------------------------------------------------------
 * Compilar
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o calculadora 04_calculadora_simple.c
 *
 * Ejecutar en Windows:
 *
 *   calculadora.exe
 *
 * Ejecutar en Linux/macOS:
 *
 *   ./calculadora
 *
 */

#include <stdio.h>

int main(void) {
    printf("=== Calculadora Simple en C ===\n");

    /*
     * Estos son los dos numeros principales de la calculadora.
     *
     * Usamos float porque queremos permitir numeros con decimales.
     * La letra f al final indica que el valor es de tipo float.
     */
    float numero1 = 24.5f;
    float numero2 = 7.0f;

    printf("\nNumeros usados por la calculadora:\n");
    printf("Numero 1: %.1f\n", numero1);
    printf("Numero 2: %.1f\n", numero2);

    /*
     * Aqui hacemos operaciones aritmeticas basicas.
     *
     * Cada resultado se guarda en una variable diferente para que el
     * codigo sea mas facil de leer.
     */
    float suma = numero1 + numero2;
    float resta = numero1 - numero2;
    float multiplicacion = numero1 * numero2;
    float division = numero1 / numero2;

    /*
     * %.2f significa que queremos mostrar el numero con 2 decimales.
     *
     * Ejemplo:
     *   31.500000 se muestra como 31.50
     */
    printf("\n--- Resultados ---\n");
    printf("Suma:             %.1f + %.1f = %.2f\n", numero1, numero2, suma);
    printf("Resta:            %.1f - %.1f = %.2f\n", numero1, numero2, resta);
    printf("Multiplicacion:   %.1f * %.1f = %.2f\n", numero1, numero2, multiplicacion);
    printf("Division:         %.1f / %.1f = %.2f\n", numero1, numero2, division);

    /*
     * Tambien podemos usar C para resolver problemas cotidianos.
     *
     * En este ejemplo calculamos cuantas horas se trabajan en una semana
     * si una persona trabaja cierta cantidad de dias y cierta cantidad
     * de horas por dia.
     */
    int dias_trabajo = 5;
    int horas_diarias = 8;
    int total_horas = dias_trabajo * horas_diarias;

    printf("\n--- Ejemplo practico: horas de trabajo ---\n");
    printf("Dias de trabajo: %d\n", dias_trabajo);
    printf("Horas por dia: %d\n", horas_diarias);
    printf("Total de horas semanales: %d\n", total_horas);

    /*
     * Otro ejemplo comun es convertir unidades.
     *
     * Sabemos que 1 metro equivale a 100 centimetros.
     * Por eso multiplicamos los metros por 100.
     */
    float metros = 150.0f;
    float centimetros = metros * 100.0f;

    printf("\n--- Conversion de unidades ---\n");
    printf("%.1f metros equivalen a %.1f centimetros.\n", metros, centimetros);

    /*
     * Este programa todavia no lee datos del usuario.
     * Mas adelante aprenderas scanf(), que permite pedir datos por teclado.
     */
    printf("\n=== Fin de la calculadora ===\n");

    return 0;
}
