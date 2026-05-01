/*
 * ============================================================
 * Modulo 02 -- Variables y Tipos de Datos
 * Archivo: 02_tipos_flotantes.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este programa explica los tipos de punto flotante en C.
 *
 * Los tipos de punto flotante sirven para guardar numeros con parte
 * decimal, por ejemplo:
 *
 *   3.14, 36.6, 0.5, -12.75
 *
 * En C los tipos flotantes principales son:
 *
 *   float       -> precision simple
 *   double      -> precision doble
 *   long double -> precision extendida
 *
 * ------------------------------------------------------------
 * Que significa precision?
 * ------------------------------------------------------------
 *
 * Precision significa cuanta exactitud puede conservar un numero.
 *
 * Algunos numeros decimales no se pueden representar exactamente en
 * binario, que es como trabaja internamente la computadora. Por eso,
 * un resultado puede verse como 0.3333333433 en vez de 0.3333333333.
 *
 * Esto no significa necesariamente que el programa este mal. Es una
 * caracteristica normal de los numeros flotantes.
 *
 * ------------------------------------------------------------
 * Recomendacion practica
 * ------------------------------------------------------------
 *
 * Usa double para la mayoria de calculos con decimales.
 * Usa float cuando necesites ahorrar memoria y la precision no sea tan
 * importante, por ejemplo en graficos, sensores o grandes arreglos.
 *
 * ------------------------------------------------------------
 * Compilar
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o 02_tipos_flotantes 02_tipos_flotantes.c
 *
 * Ejecutar en Windows:
 *
 *   02_tipos_flotantes.exe
 *
 * Ejecutar en Linux/macOS:
 *
 *   ./02_tipos_flotantes
 *
 */

#include <stdio.h>
#include <float.h>

int main(void) {
    printf("=== MODULO 02 - TIPOS FLOTANTES ===\n\n");

    /*
     * float guarda numeros decimales con precision simple.
     *
     * La letra f al final del numero indica que el literal es float.
     */
    printf("--- float (precision simple) ---\n");

    float f_temp = 36.6f;
    float f_pi = 3.14159265358979323846f;

    printf("Temperatura float: %.2f\n", f_temp);
    printf("Pi float:          %.2f\n", f_pi);
    printf("Pi float (10 dec): %.10f\n", f_pi);

    /*
     * double guarda numeros decimales con mas precision que float.
     *
     * En C, los numeros con decimal escritos sin f normalmente se
     * consideran double.
     */
    printf("\n--- double (precision doble) ---\n");

    double d_temp = 36.6;
    double d_pi = 3.14159265358979323846;

    printf("Temperatura double: %.2f\n", d_temp);
    printf("Pi double:          %.2f\n", d_pi);
    printf("Pi double (10 dec): %.10f\n", d_pi);

    /*
     * long double puede ofrecer mas precision que double, dependiendo
     * del compilador y del sistema operativo.
     *
     * La letra L al final del numero indica que es long double.
     */
    printf("\n--- long double (precision extendida) ---\n");

    long double ld_pi = 3.14159265358979323846L;

    printf("Pi long double:      %.2Lf\n", ld_pi);
    printf("Pi long double(10d): %.10Lf\n", ld_pi);
    printf("Pi long double(20d): %.20Lf\n", ld_pi);

    /*
     * Comparacion de precision.
     *
     * Aqui calculamos 1 / 3 usando float y double.
     * Observa que double conserva mas precision.
     */
    printf("\n--- Comparacion de precision ---\n");

    float f_val = 1.0f / 3.0f;
    double d_val = 1.0 / 3.0;

    printf("1/3 como float:  %.10f\n", f_val);
    printf("1/3 como double: %.10f\n", d_val);

    /*
     * sizeof muestra cuantos bytes ocupa cada tipo.
     */
    printf("\n--- Tamano en bytes ---\n");

    printf("sizeof(float):       %zu bytes\n", sizeof(float));
    printf("sizeof(double):      %zu bytes\n", sizeof(double));
    printf("sizeof(long double): %zu bytes\n", sizeof(long double));

    /*
     * float.h contiene informacion sobre los limites y precision de
     * los tipos flotantes.
     *
     * %e imprime numeros en notacion cientifica.
     */
    printf("\n--- Valores maximos ---\n");

    printf("FLT_MAX:  %e\n", FLT_MAX);
    printf("DBL_MAX:  %e\n", DBL_MAX);
    printf("LDBL_MAX: %Le\n", LDBL_MAX);

    /*
     * FLT_DIG, DBL_DIG y LDBL_DIG indican aproximadamente cuantos
     * digitos significativos puede representar cada tipo.
     */
    printf("\n--- Digitos de precision ---\n");

    printf("FLT_DIG:  %d digitos significativos\n", FLT_DIG);
    printf("DBL_DIG:  %d digitos significativos\n", DBL_DIG);
    printf("LDBL_DIG: %d digitos significativos\n", LDBL_DIG);

    return 0;
}
